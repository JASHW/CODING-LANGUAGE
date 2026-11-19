# 5. Loops

Loops repeat work. Make sure the loop has a clear stopping condition.

## `while`

Checks the condition before each repetition; it may run zero times.

```cpp
int count{0};
while (count < 3) {
    std::cout << count << '\n';
    ++count;
}
```

## `for`

Useful when the loop has an obvious counter or range.

```cpp
for (int i{0}; i < 3; ++i) {
    std::cout << i << '\n';
}
```

## Range-based `for`

```cpp
int scores[]{80, 90, 100};
for (int score : scores) {
    std::cout << score << '\n';
}
```

`break` exits a loop. `continue` skips to its next iteration. Use them sparingly so the loop's flow stays easy to follow.
