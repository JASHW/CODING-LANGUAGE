# 2. Types and values

Python is dynamically typed: types belong to objects and are checked while a program runs. Common built-in types include `int`, `float`, `bool`, `str`, `NoneType`, `list`, `tuple`, `dict`, and `set`.

```python
age: int = 20
height: float = 1.72
is_ready: bool = True
name: str = "Mina"
middle_name: str | None = None  # Python 3.10+
```

Type annotations document expectations and help editors and static checkers, but Python does not enforce them automatically at runtime.

## Mutable and immutable objects

Numbers, strings, and tuples are immutable: operations create new values. Lists, dictionaries, and sets are mutable: their contents can change. Multiple names can refer to the same mutable object.

```python
first = [1, 2]
second = first
second.append(3)
assert first == [1, 2, 3]  # same list object
```

Use `copy.copy` or `copy.deepcopy` from the `copy` module when an actual copy is needed; understand shallow versus deep copying.

## Conversions

Use constructors such as `int("42")`, `float("2.5")`, and `str(42)` for explicit conversions. Invalid conversions raise `ValueError`. `bool(value)` follows truthiness rules, so prefer explicit conditions when empty values could be ambiguous.
