# 8. References and pointers

Both references and pointers can refer to another object. They are useful, but should be introduced after variables and functions are understood.

## References

A reference is an alias for an existing object. It must be initialized and normally cannot be reseated to refer to a different object.

```cpp
int value{5};
int& alias = value;
alias = 8; // value is now 8
```

## Pointers

A pointer stores an object's address. `&value` obtains an address; `*pointer` accesses the pointed-to object. A pointer can be null, so check before dereferencing when null is possible.

```cpp
int value{5};
int* pointer = &value;
if (pointer != nullptr) {
    *pointer = 9;
}
```

Prefer references when an object is required, and modern ownership types/containers for resource management. Avoid raw `new` and `delete` in beginner code; mismatched ownership can cause leaks or invalid access.
