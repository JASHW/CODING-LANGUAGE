# 14. Abstraction and OOP review

Abstraction exposes the operations a caller needs while hiding implementation details. Python commonly expresses interfaces through documented behavior, duck typing, and optionally abstract base classes or `typing.Protocol`.

The usual OOP principles are:

1. **Encapsulation** — group state with operations and protect valid state through a clear interface.
2. **Abstraction** — expose useful behavior without requiring callers to know implementation details.
3. **Inheritance** — specialize a base type when the subtype can be substituted for it.
4. **Polymorphism** — use different implementations through shared behavior.

## Design checklist

- Keep functions and classes focused on one responsibility.
- Prefer simple data and functions until an object provides a clear benefit.
- Use type hints to clarify public interfaces; add static checking when useful.
- Validate inputs at boundaries and keep object invariants true.
- Prefer composition for “has-a” relationships.
- Catch only errors you can handle; use context managers for cleanup.
- Avoid mutable default arguments and accidental shared mutable state.

## Practice: library inventory

Create a `Book` class with title and page count. Create a `Library` that stores books in a list, adds books, finds a title, and reports total pages. Keep the collection behind methods. Then add a `DigitalBook` only if it is behaviorally substitutable for `Book`; otherwise represent format through composition or a field.
