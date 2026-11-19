# 11. Classes and objects

A class defines a new kind of object. An object has data (attributes) and behavior (methods). `self` refers to the current instance and is written explicitly as the first method parameter.

```python
class Dog:
    def __init__(self, name: str) -> None:
        self.name = name

    def bark(self) -> str:
        return f"{self.name} says woof"


pet = Dog("Milo")
print(pet.bark())
```

`__init__` initializes an instance. Python does not enforce private fields; a leading underscore (such as `_balance`) signals an implementation detail. Use `@property` when attribute-style access needs validation or computed behavior.

Classes should model a coherent concept. Prefer simple functions and data structures until a class provides useful behavior, invariants, or identity.
