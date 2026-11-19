# 4. Input and decisions

`input()` reads a line of text and returns a `str`. Convert and validate it before using it as a number.

```python
raw = input("Enter your age: ")
try:
    age = int(raw)
except ValueError:
    print("Please enter a whole number.")
else:
    print(f"Next year you will be {age + 1}.")
```

Use `if`, `elif`, and `else` for branching:

```python
if age < 0:
    print("Age cannot be negative")
elif age < 18:
    print("Minor")
else:
    print("Adult")
```

Conditions use truthiness: `False`, `None`, numeric zero, and empty containers are false; most other values are true. Prefer explicit comparisons when the distinction matters (for example, `value is not None` instead of `if value`).

The conditional expression `"open" if is_open else "closed"` is suitable for a short value choice. Use a regular `if` for multi-step branches.
