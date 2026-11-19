# Intermediate Python: variables through OOP

This guide supplements the numbered notes. It assumes you can read basic Python and focuses on choices that make programs predictable and maintainable.

## Names, objects, and mutation

Names are bindings to objects, not boxes with fixed types. Assignment can create another binding to the same object. This is harmless for immutable values but important for mutable containers. Passing a list to a function passes an object reference by assignment; mutations to that list are visible to the caller. Rebinding the parameter is not.

Use `==` for value equality and `is` for identity (especially `is None`). Do not use `is` to compare strings or numbers. Type hints improve communication and static analysis, but do not validate values at runtime.

## Functions and scope

Prefer explicit parameters and return values over globals. Use `None` as the default when a function needs a fresh mutable object. Avoid mutable default arguments because Python evaluates defaults once when defining the function. Use keyword-only arguments (`def f(value, *, strict=False)`) when named options improve call-site clarity. Keep side effects obvious.

Closures capture names from an enclosing scope; decorators wrap or modify functions; generators produce lazy, one-pass iterators. Learn these tools when they simplify a concrete task rather than applying them everywhere.

## Data structures and complexity

Choose the collection by the operation you need. List membership is linear in list length; set and dictionary lookup is average constant time. Dictionaries preserve insertion order in modern Python. Avoid repeatedly searching a list when a set or dictionary can express the lookup directly.

Comprehensions are concise transformations; generator expressions avoid allocating a complete result. Avoid deeply nested comprehensions because they make control flow difficult to understand.

## Exceptions, resources, and modules

Exceptions should represent exceptional or invalid conditions, not ordinary loop control. Catch narrow exception types close to the operation that can raise them. Use `with open(...)` and other context managers so cleanup is deterministic. Split reusable code into modules, use an `if __name__ == "__main__"` guard for script entry points, and avoid circular imports.

## Classes and data models

Use a class when state and behavior form a coherent concept, identity matters, or invariants need protection. Use `@dataclass` for data-centric objects. Python's `_name` is a convention for internal use, not enforced privacy. Properties can preserve a simple attribute API while adding validation, but ordinary methods are often clearer for actions.

Implement special methods (`__repr__`, `__eq__`, `__iter__`, and others) only when their semantics are well-defined. Dataclasses can generate common representation and equality behavior. Be cautious with mutable class attributes: they are shared by instances. Put per-instance mutable data in `__init__`.

## Inheritance and polymorphism

Prefer composition for “has-a.” Use inheritance when every instance of a subclass can honor the base contract. Python's duck typing allows polymorphism without inheritance: callers rely on behavior rather than class ancestry. Use `abc.ABC` for runtime abstract base classes and `typing.Protocol` for static structural interfaces. Multiple inheritance and mixins are powerful but require care with method resolution order.

## Example: a small value object

```python
from dataclasses import dataclass


@dataclass(frozen=True)
class Point:
    x: float
    y: float

    def distance_squared_to(self, other: "Point") -> float:
        dx = self.x - other.x
        dy = self.y - other.y
        return dx * dx + dy * dy
```

`frozen=True` prevents normal attribute reassignment after construction. It is useful for simple value objects, but does not recursively freeze mutable values stored inside fields.

## Practice

1. Write a function that groups words by their first letter and returns a `dict[str, list[str]]`.
2. Implement a generator that yields lines from a file while skipping blank lines; use it with a context manager.
3. Model a shopping cart with a private list of line items and methods that preserve quantity and price invariants.
4. Define a `Protocol` for objects that can be serialized, then make two unrelated classes satisfy it.
5. Explain when your design uses composition, inheritance, duck typing, or an abstract base class—and why.
