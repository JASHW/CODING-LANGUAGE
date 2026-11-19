# 11. Inheritance

Inheritance lets a derived class extend or specialize a base class. Use it when the derived type truly can be used wherever the base type is expected (an “is-a” relationship).

```cpp
#include <string>

class Animal {
public:
    explicit Animal(std::string name) : name_(std::move(name)) {}
    const std::string& name() const { return name_; }
private:
    std::string name_;
};

class Cat : public Animal {
public:
    using Animal::Animal; // inherit the base constructor
    void purr() const {}
};
```

`public` inheritance keeps the base's public interface public on the derived type. A derived class can add behavior and data. Prefer composition (a class contains another object) when the relationship is “has-a,” such as a `Car` having an `Engine`.
