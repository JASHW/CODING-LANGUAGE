# Intermediate C++ notes: variables through OOP

These notes extend the numbered beginner sequence. Examples target C++17. Focus on understanding lifetime, ownership, and interface design—not just syntax.

## Variables, scope, and initialization

C++ determines a variable's type at compile time. Initialize objects at their declaration, preferably with braces (`int count{4};`). This avoids accidentally reading an indeterminate local value and prevents many narrowing conversions (`int n{3.8};` is rejected). `auto` still has a fixed compile-time type; use it when the initializer makes that type clear, not to hide an important distinction.

Variables have scope and lifetime. A local variable's lifetime usually ends at the closing brace. Keep mutable state local and short-lived. A `static` local persists across calls, so use it only when that persistence is intentional. `const` prevents mutation through a name; `constexpr` requires a compile-time constant expression when possible.

```cpp
constexpr int maxRetries{3};
const double taxRate{0.08};
auto itemCount = 4; // int, fixed at compile time
```

## Types, conversions, and expressions

Use types that match the domain. `int` represents signed whole numbers; `double` approximates real numbers; `bool` represents truth values; `std::string` owns text. Floating-point values may not represent decimal fractions exactly, so represent exact currency in integer minor units (such as cents) or use a suitable decimal type.

Integer division truncates toward zero. Signed overflow is undefined behavior. Conversions can lose information; use `static_cast<T>(value)` to make an intentional conversion visible, and validate the range first. Container sizes use `std::size_t`; avoid careless signed/unsigned comparisons. Use `enum class` for a fixed set of named states instead of unrelated integers.

`&&` and `||` short-circuit. This supports guards such as `p != nullptr && p->ready()`. Avoid hiding side effects in expressions. Use parentheses when precedence is not obvious.

## Functions and API design

Pass small scalar values by value. Pass larger read-only objects by `const T&` to avoid copying; use `T&` when the function is meant to mutate the caller's object. A pointer can represent an optional object (`nullptr`); a reference represents a required object. Keep each function focused and make mutation visible in its signature.

Returning a local object by value is safe and typically efficient due to copy elision and move operations. Never return a pointer or reference to a local variable. Overloads differ by parameter list, not return type. Put default arguments in one declaration, commonly a header.

```cpp
std::string greeting(const std::string& name) {
    return "Hello, " + name;
}
```

## Collections and iterators

Use `std::array<T, N>` for fixed compile-time size and `std::vector<T>` for a resizable contiguous sequence. `std::vector` is the default sequence container for many tasks. `std::map` and `std::unordered_map` model key-value lookup. Prefer standard algorithms such as `std::sort` and `std::find` when they state intent clearly.

An iterator or reference into a vector may become invalid when the vector reallocates or erases elements. After a mutation that can invalidate them, reacquire iterators/references. Use `.at(i)` for bounds-checked access and `[]` when validity is already guaranteed.

## Pointers, ownership, and RAII

A pointer is an address, not an ownership policy. Decide who owns each resource. Prefer automatic objects and standard containers. Use `std::unique_ptr<T>` for exclusive dynamic ownership and `std::shared_ptr<T>` only for genuinely shared ownership. A reference or raw pointer is generally non-owning; document whether null is allowed.

RAII (Resource Acquisition Is Initialization) ties resource lifetime to object lifetime. Constructors acquire/initialize; destructors release. Standard types such as `std::string`, `std::vector`, `std::ifstream`, and smart pointers already follow this pattern. This keeps cleanup correct when returning early or throwing exceptions. Avoid manual `new`/`delete` in ordinary application code.

`std::move(x)` is a cast that permits move overloads; it does not itself transfer anything. After moving, `x` remains valid but its value is generally unspecified. Do not use it as if it still contained its old value.

## Class design and encapsulation

A class defines a type; an object is one instance. Use private data to preserve invariants—conditions that must remain true for every valid object. Constructors should establish those invariants. Expose operations that communicate intent, not setters for every field. Mark observer member functions `const`, and mark single-argument constructors `explicit` when implicit conversion would be surprising.

```cpp
class Percentage {
public:
    explicit Percentage(int value) : value_{value} {
        if (value < 0 || value > 100)
            throw std::out_of_range("percentage out of range");
    }
    int value() const { return value_; }
private:
    int value_;
};
```

`struct` and `class` have the same capabilities; default member access is public for `struct` and private for `class`. C++ generates copy/move/destructor operations when appropriate. Resource-owning classes should follow the Rule of Zero: use resource-managing member types instead of writing those operations manually.

## Composition, inheritance, and polymorphism

Composition models “has-a” and is usually the simplest reuse mechanism. Inheritance models a substitutable “is-a”: every derived object should meet the expectations of the base interface. Keep base interfaces small. Avoid inheriting only to reuse implementation.

For runtime polymorphism, declare a base operation `virtual`, use `override` in derived classes, and give polymorphic bases a virtual destructor. Use a pure virtual function (`= 0`) for an interface with no base implementation. Pass polymorphic objects by reference or pointer: passing a derived object by value as a base slices off the derived portion. Own mixed implementations with `std::unique_ptr<Base>`; do not put derived objects into `std::vector<Base>` by value.

Templates provide compile-time polymorphism; virtual functions provide runtime polymorphism. Use templates when the type is known during compilation and a shared runtime interface is not needed.

## Practice tasks

1. Implement a `Temperature` value class that stores Celsius and rejects values below absolute zero.
2. Write a function that accepts `const std::vector<int>&` and returns the median without changing the input.
3. Implement a `Library` containing `std::vector<Book>`; use composition and keep the book list private.
4. Create an abstract `Shape` interface and two implementations, then compute total area through `const Shape&` references.
5. Explain which operations could invalidate an iterator in your collection code and how you avoid using it afterward.
