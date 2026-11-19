# 1. Variables and naming

A variable name refers to an object. Unlike C++, Python names do not declare a fixed type: a name can later refer to an object of another type. The object itself still has a type.

```python
count = 4
name = "Mina"
count = "four"  # legal, but usually confusing design
```

## Naming rules

- Names may contain letters, digits, and underscores; they cannot start with a digit.
- Names are case-sensitive: `score` and `Score` differ.
- Do not use keywords such as `class`, `if`, or `return` as names.
- Use `snake_case` for variables and functions, `PascalCase` for classes, and uppercase names for module-level constants.
- Choose names that explain purpose: `retry_count` is clearer than `x`.

Python does not enforce constants, but uppercase names signal that callers should treat a value as fixed: `MAX_RETRIES = 3`.

## Assignment and identity

Assignment binds a name to an object; it does not necessarily copy the object. This distinction matters for mutable lists and dictionaries. `is` checks object identity, while `==` checks value equality. Use `is None` to test for `None`.
