# 1. Variable names, declarations, and initialization

A **variable** is a named place for a value that a program can use. C++ is statically typed: every variable has a type, and the compiler checks how that type is used.

## Naming rules

- Use letters, digits, and underscores; the first character cannot be a digit.
- Names are case-sensitive: `score`, `Score`, and `SCORE` are different.
- A name cannot be a C++ keyword such as `int`, `class`, or `return`.
- Choose descriptive names such as `itemCount` or `accountBalance`.

```cpp
int itemCount = 4;
double accountBalance = 125.50;
bool isReady = true;
```

## Declaration and initialization

A declaration gives a variable its type and name. Initialization gives it its first value. Prefer initializing variables immediately; an uninitialized local built-in variable has an indeterminate value.

```cpp
int attempts;       // declared, but not initialized: do not read it yet
int lives{3};       // direct-list initialization
int level = 1;      // copy initialization
auto price{9.99};   // auto deduces double
```

Braces prevent some accidental narrowing conversions:

```cpp
int count{5};
// int bad{3.7}; // error: would discard the fractional part
```

## Assignment changes a value

```cpp
int score{10};
score = 12; // assignment; score now contains 12
```

The type usually stays the same after assignment. A variable declared `int` remains an `int`.
