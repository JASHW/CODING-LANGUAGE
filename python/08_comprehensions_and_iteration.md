# 8. Comprehensions and iteration

Comprehensions build a collection from an iterable with an expression and optional filter.

```python
squares = [number * number for number in range(6)]
even_squares = [number * number for number in range(10) if number % 2 == 0]
lookup = {word: len(word) for word in ["red", "green"]}
```

Use comprehensions for simple transformations. If the logic needs nested conditions or multiple steps, use a regular loop for clarity. A generator expression `(n * n for n in range(1_000_000))` yields values lazily and avoids building a full list.

An iterable can provide an iterator; `for` repeatedly requests its next value until it is exhausted. A generator function uses `yield` to produce a sequence lazily:

```python
def countdown(start: int):
    while start > 0:
        yield start
        start -= 1
```

Generators are one-pass: once exhausted, they do not restart automatically. Create a new generator by calling the generator function again.
