# 12. Polymorphism

**Polymorphism** lets code use a common base interface while the actual object supplies the specific behavior. In C++, runtime polymorphism uses virtual functions.

```cpp
#include <iostream>

class Shape {
public:
    virtual double area() const = 0; // pure virtual: no Shape implementation
    virtual ~Shape() = default;      // safe deletion through a base pointer
};

class Square : public Shape {
public:
    explicit Square(double side) : side_(side) {}
    double area() const override { return side_ * side_; }
private:
    double side_;
};

void printArea(const Shape& shape) {
    std::cout << shape.area() << '\n';
}
```

`override` asks the compiler to confirm the function overrides a base virtual function. A class with a pure virtual function is abstract and cannot be instantiated directly. Use a virtual destructor in a polymorphic base class when objects may be destroyed through a base pointer.
