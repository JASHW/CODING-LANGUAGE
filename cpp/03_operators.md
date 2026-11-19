# 3. Operators and expressions

Operators combine values to make expressions.

## Arithmetic

`+`, `-`, `*`, `/`, `%` (remainder for integers)

```cpp
int total{17};
int people{5};
int each = total / people; // integer division: 3
int leftover = total % people; // 2
double average = 17.0 / 5; // 3.4
```

## Comparisons and logic

- Comparisons: `==`, `!=`, `<`, `>`, `<=`, `>=`; result is `bool`.
- Logic: `&&` (and), `||` (or), `!` (not).
- Assignment is `=`; equality comparison is `==`.

```cpp
int age{22};
bool canVote = age >= 18;
bool hasTicket{true};
bool mayEnter = canVote && hasTicket;
```

## Updating values

`x += 1`, `x -= 1`, `++x`, and `--x` update a variable. Prefer clear expressions; avoid relying on subtle operator precedence or changing the same variable multiple times in one expression.

Use parentheses when they make the intended order clear: `price * (1.0 + taxRate)`.
