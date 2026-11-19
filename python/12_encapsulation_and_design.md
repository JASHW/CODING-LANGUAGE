# 12. Encapsulation and object design

Encapsulation groups state and behavior and provides a clear interface. Python relies on conventions and properties rather than enforced private access.

```python
class BankAccount:
    def __init__(self, owner: str, opening_cents: int = 0) -> None:
        if opening_cents < 0:
            raise ValueError("opening balance cannot be negative")
        self.owner = owner
        self._balance_cents = opening_cents

    @property
    def balance_cents(self) -> int:
        return self._balance_cents

    def deposit(self, cents: int) -> None:
        if cents <= 0:
            raise ValueError("deposit must be positive")
        self._balance_cents += cents
```

An invariant is a condition that should always hold for a valid object. Validate it at construction and at every operation that could break it. Prefer a meaningful method such as `deposit` over an unrestricted setter.

Use `@dataclass` for classes primarily storing data. Add methods when they express useful behavior. Favor composition (“has-a”) for building larger objects from smaller ones. Avoid classes that merely wrap one function without adding state or a useful interface.
