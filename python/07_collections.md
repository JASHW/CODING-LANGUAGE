# 7. Collections

## Lists

Lists are mutable ordered sequences and can contain mixed types, though homogeneous lists are usually easier to reason about.

```python
scores = [80, 90]
scores.append(100)
first = scores[0]
last = scores[-1]
```

Indexing starts at zero. Slices use `[start:stop:step]`; the stop is excluded. A slice creates a shallow copy of the selected sequence.

## Tuples

Tuples are immutable ordered sequences, useful for fixed groups of values and unpacking: `x, y = (3, 4)`. A one-element tuple needs a comma: `(5,)`.

## Dictionaries and sets

Dictionaries map hashable keys to values. Sets store unique hashable values and support membership and set operations.

```python
prices = {"tea": 2.5, "coffee": 3.0}
prices["tea"] = 2.75
unique_ids = {4, 7, 4}  # {4, 7}
```

Use `dict.get(key, default)` for optional lookup, `in` to test key membership, and iterate with `for key, value in prices.items()`.

Choose collections by behavior: list for ordered mutable sequences, tuple for fixed records, dict for keyed lookup, and set for uniqueness/membership.
