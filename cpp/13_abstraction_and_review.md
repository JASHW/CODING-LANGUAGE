# 13. Abstraction and OOP review

**Abstraction** exposes what a type can do while hiding the details of how it does it. A small public interface lets callers use an object without depending on its implementation.

The four commonly taught OOP ideas are:

1. **Encapsulation** — protect state and expose controlled operations.
2. **Abstraction** — show essential operations and hide implementation details.
3. **Inheritance** — derive a specialized type from a base type when the relationship fits.
4. **Polymorphism** — use a common interface with behavior supplied by concrete types.

## Small design checklist

- Give each class one clear responsibility.
- Keep data private unless public access is part of the type's design.
- Initialize members in constructors and keep objects valid.
- Prefer composition for “has-a”; use inheritance for a genuine substitutable “is-a.”
- Use `const` for operations that should not change state.
- Use `override` on derived virtual functions.
- Avoid deep inheritance trees; simple composition is often easier to maintain.

## Practice: a library item

Create a `Book` class with private title and page-count members, a constructor, and read-only accessors. Then create a `Library` class that stores books in a `std::vector<Book>`. Add a method that prints each title. This practices variables, strings, collections, classes, constructors, encapsulation, and composition.
