# 3. Operators and expressions

Arithmetic: `+`, `-`, `*`, `/` (true division), `//` (floor division), `%` (remainder), and `**` (power).

```python
total = 17
people = 5
print(total / people)   # 3.4
print(total // people)  # 3
print(total % people)   # 2
```

Comparison operators include `==`, `!=`, `<`, `>`, `<=`, and `>=`. Logical operators are the words `and`, `or`, and `not`. Python comparisons can be chained: `0 <= score <= 100`.

`in` tests membership in sequences and keys in dictionaries. `is` tests identity, and is most often used with singleton values such as `None`.

```python
if user_name is not None and user_name in allowed_names:
    print("Welcome")
```

Use parentheses to make non-obvious precedence clear. Avoid compact expressions that hide side effects or make the order hard to see.
