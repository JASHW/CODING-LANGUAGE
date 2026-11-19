# 13. Inheritance and polymorphism

Inheritance creates a specialized class from a base class. Use it when the derived object genuinely can stand in for the base object. Python supports multiple inheritance, but simple single-inheritance hierarchies are easier to understand.

```python
class Shape:
    def area(self) -> float:
        raise NotImplementedError


class Square(Shape):
    def __init__(self, side: float) -> None:
        self.side = side

    def area(self) -> float:
        return self.side * self.side
```

Polymorphism means callers can use different objects through a common behavior. Python often uses duck typing: an object is suitable if it provides the needed method, whether or not it inherits from a particular base class.

Use `abc.ABC` and `@abstractmethod` when you need an explicit abstract interface. Prefer composition when the relationship is “has-a”; inheritance should express substitutability, not just code reuse.
