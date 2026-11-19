# 4. Input, output, and decisions

Use `std::cout` to print and `std::cin` to read. Both are provided by `<iostream>`.

```cpp
#include <iostream>

int main() {
    int age{};
    std::cout << "Enter your age: ";
    std::cin >> age;
    std::cout << "You entered " << age << '\n';
}
```

## `if`, `else if`, and `else`

```cpp
if (age < 0) {
    std::cout << "Age cannot be negative\n";
} else if (age < 18) {
    std::cout << "Minor\n";
} else {
    std::cout << "Adult\n";
}
```

Braces make the body clear and help prevent mistakes. Conditions should be boolean expressions. For multiple fixed choices, `switch` can be useful:

```cpp
switch (menuChoice) {
    case 1: std::cout << "Start\n"; break;
    case 2: std::cout << "Help\n"; break;
    default: std::cout << "Unknown choice\n";
}
```

Remember `break` to avoid falling through to the next case unintentionally.
