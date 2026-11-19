# 5. Loops

## `for`

Python's `for` loop iterates over items, rather than requiring an index counter.

```python
for name in ["Mina", "Lee", "Ari"]:
    print(name)
```

Use `range(stop)`, `range(start, stop)`, or `range(start, stop, step)` for integer sequences. The stop value is excluded. Use `enumerate(items)` when both index and item are needed.

```python
for index, name in enumerate(["Mina", "Lee"], start=1):
    print(index, name)
```

## `while`

Repeats while a condition remains true. Ensure the loop makes progress toward stopping.

```python
remaining = 3
while remaining > 0:
    print(remaining)
    remaining -= 1
```

`break` exits the nearest loop; `continue` skips to its next iteration. A loop's optional `else` suite runs when the loop ends normally (not through `break`), a feature useful for search loops but unfamiliar to many beginners.
