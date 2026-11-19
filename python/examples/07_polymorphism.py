from abc import ABC, abstractmethod
from math import pi


class Shape(ABC):
    @abstractmethod
    def area(self) -> float:
        raise NotImplementedError


class Square(Shape):
    def __init__(self, side: float) -> None:
        self.side = side

    def area(self) -> float:
        return self.side**2


class Circle(Shape):
    def __init__(self, radius: float) -> None:
        self.radius = radius

    def area(self) -> float:
        return pi * self.radius**2


def main() -> None:
    shapes: list[Shape] = [Square(3), Circle(2)]
    for shape in shapes:
        print(shape.area())


if __name__ == "__main__":
    main()
