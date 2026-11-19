# 10. Encapsulation, constructors, and access control

**Encapsulation** keeps an object's internal state together with the operations that manage it. A class can enforce rules by making data `private` and exposing intentional `public` functions.

```cpp
#include <string>
#include <utility>

class Student {
private:
    std::string name_;
    int score_{};

public:
    Student(std::string name, int score)
        : name_(std::move(name)), score_(score) {}

    const std::string& name() const { return name_; }
    int score() const { return score_; }
};
```

The constructor has the same name as the class and initializes a new object. The **member initializer list** (after `:`) initializes members directly. `private` members are available to the class's own functions; `public` members are available through the interface.

The trailing `const` on `name()` and `score()` promises those functions will not change the object's state. `std::move` is introduced later; here it efficiently transfers the constructor's string parameter into the member.
