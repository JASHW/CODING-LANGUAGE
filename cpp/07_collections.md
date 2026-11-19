# 7. Arrays, strings, and vectors

## C-style arrays

An array stores a fixed number of same-typed elements. Indexes start at zero; valid indexes are `0` through `size - 1`.

```cpp
int values[3]{10, 20, 30};
std::cout << values[0]; // 10
```

Out-of-range array access is undefined behavior. C-style arrays do not track their size for you.

## `std::array`

For a fixed-size collection, prefer `std::array` from `<array>`; it knows its size and works with range-based loops.

```cpp
#include <array>
std::array<int, 3> values{10, 20, 30};
std::cout << values.size();
```

## `std::vector`

For a resizable collection, use `std::vector` from `<vector>`.

```cpp
#include <vector>
std::vector<int> scores{80, 90};
scores.push_back(100);
std::cout << scores.at(0); // at() checks bounds
```

## `std::string`

Use `std::string` from `<string>` for text. `std::getline(std::cin, line)` reads a whole line, including spaces. Mixing `std::cin >> value` and `getline` may require consuming the leftover newline first.
