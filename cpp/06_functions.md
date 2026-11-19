# 6. Functions and scope

A function names a reusable task. Its **return type** describes the result; parameters receive inputs.

```cpp
int add(int left, int right) {
    return left + right;
}
```

Call it with `int result = add(2, 3);`. A function that returns no value uses `void`.

## Declaration and definition

A declaration (prototype) tells the compiler a function's signature before its definition appears:

```cpp
int square(int number); // declaration

int main() {
    return square(4);
}

int square(int number) { // definition
    return number * number;
}
```

## Pass by value and reference

Pass by value gives a function a copy. Pass by reference (`&`) lets it work with the caller's object. Use `const T&` for a read-only reference to a potentially large object.

```cpp
void addOne(int& number) { ++number; }
void printName(const std::string& name) { std::cout << name; }
```

## Scope

A local variable exists only inside its block or function. Keep variables in the smallest scope that needs them. Avoid global mutable variables because any part of a program can change them.
