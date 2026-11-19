# 2. Types, constants, and conversions

## Common built-in types

| Type | Typical use | Example |
|---|---|---|
| `int` | whole numbers | `int age{20};` |
| `double` | decimal measurements | `double height{1.72};` |
| `char` | one character | `char grade{'A'};` |
| `bool` | true/false | `bool isOpen{false};` |
| `std::string` | text | `std::string name{"Ari"};` |

Use `#include <string>` for `std::string`. Exact type sizes can vary by platform; use `sizeof(type)` when the size matters.

## Constants

Use `const` when a value should not change after initialization. Use `constexpr` when a value can be computed at compile time.

```cpp
const double taxRate{0.08};
constexpr int daysInWeek{7};
```

## Conversions

Some conversions happen implicitly, but can lose information. Make intended conversions explicit and check ranges when converting user input.

```cpp
int whole{7};
double precise = whole; // safe widening conversion: 7.0

double measurement{4.8};
int truncated = static_cast<int>(measurement); // 4; fractional part discarded
```

`static_cast` documents the conversion; it does not make a lossy conversion safe by itself.
