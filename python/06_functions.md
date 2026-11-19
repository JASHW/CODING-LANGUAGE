# 6. Functions

Define reusable behavior with `def`. Parameters receive values; `return` sends a result back. A function without an explicit return returns `None`.

```python
def area(width: float, height: float = 1.0) -> float:
    """Return the area of a rectangle."""
    return width * height
```

Call with positional or keyword arguments: `area(3, 4)` and `area(width=3, height=4)`. Defaults should be immutable values or `None`; mutable defaults are created once and reused across calls.

```python
def add_tag(tag: str, tags: list[str] | None = None) -> list[str]:
    if tags is None:
        tags = []
    tags.append(tag)
    return tags
```

Names assigned inside a function are local by default. Avoid `global` state; pass data in and return results. Functions are first-class values and can be passed to other functions.

Type hints document the API, but are not runtime validation. Keep functions focused, use descriptive names, and avoid surprising mutation of arguments.
