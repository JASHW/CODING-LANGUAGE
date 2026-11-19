# 9. Exceptions

Exceptions report errors or unusual conditions. Catch only exceptions you can handle meaningfully, and keep the `try` block as small as possible.

```python
try:
    quantity = int(input("Quantity: "))
except ValueError:
    print("Enter a whole number.")
else:
    print(f"You requested {quantity} items.")
```

`else` runs only when no exception occurred. `finally` runs during cleanup whether or not an exception occurred. Prefer context managers (`with`) for files and other resources because they guarantee cleanup.

Raise an appropriate exception for invalid input to an API: `raise ValueError("quantity must be positive")`. Define custom exception classes when callers need to distinguish domain-specific failures. Avoid bare `except:` because it catches even interrupts and makes bugs hard to diagnose.
