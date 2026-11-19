#include <iostream>
#include <memory>
#include <vector>

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Square final : public Shape {
public:
    explicit Square(double side) : side_{side} {}
    double area() const override { return side_ * side_; }
private:
    double side_;
};

class Circle final : public Shape {
public:
    explicit Circle(double radius) : radius_{radius} {}
    double area() const override { return 3.141592653589793 * radius_ * radius_; }
private:
    double radius_;
};

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Square>(3.0));
    shapes.push_back(std::make_unique<Circle>(2.0));

    for (const auto& shape : shapes) std::cout << shape->area() << '\n';
}
