# 9. Classes and objects

A **class** defines a new type. An **object** is one value of that type, with its own state.

```cpp
#include <string>

class Dog {
public:
    std::string name;
    void bark() const {
        // A member function can use the object's members.
    }
};

int main() {
    Dog pet;
    pet.name = "Milo";
    pet.bark();
}
```

Members can be data (state) or functions (behavior). `pet.name` uses the dot operator to access a public member.

Prefer classes whose operations keep their state valid. Usually data should be private, with a small public interface; see the next note.
