# Intermediate Java: objects, collections, and design

This guide assumes you can write basic Java programs with variables, conditions, loops, methods, and classes. It focuses on choices that make Java programs safer and easier to maintain. Examples target Java 17 or later.

## Types, references, and null

Primitive variables (`int`, `double`, `boolean`, and others) hold primitive values. Variables of class and array types hold references to objects. Assigning an object reference copies the reference, so both variables can refer to the same mutable object. A method can mutate the referenced object, though assigning a new reference to its parameter does not change the caller's variable. Java always passes arguments by value.

Use `==` for primitive value comparison and object identity. Use `.equals()` for logical object equality. Strings are immutable, so operations such as `toUpperCase()` return a new string. Avoid `null` when an empty collection, a clear default, or `Optional<T>` in a return type describes the situation better. Validate required references at API boundaries with `Objects.requireNonNull`.

```java
String first = new String("Java");
String second = new String("Java");
System.out.println(first == second);      // false: distinct objects
System.out.println(first.equals(second)); // true: same text
```

## Methods and class design

Keep methods focused, use names that describe actions, and make inputs and outputs explicit. Prefer immutable data when it fits: make fields `private final`, avoid setters, and defensively copy mutable inputs and outputs. `final` prevents reassignment of a reference; it does not make the referenced object immutable.

Constructors should establish valid object state. Use access modifiers intentionally (`private`, package-private, `protected`, `public`) and expose operations rather than every field. Static methods belong to the class and cannot use instance state without an instance. Avoid large utility classes that collect unrelated behavior.

Records are a concise choice for transparent data carriers. Their component fields are final, and Java generates accessors, `equals`, `hashCode`, and `toString`. A record is only shallowly immutable: a mutable component still needs defensive copying. Use a normal class when the object has evolving state, identity, or behavior that does not fit a data carrier.

```java
public record Point(double x, double y) {
    public double distanceTo(Point other) {
        double dx = x - other.x;
        double dy = y - other.y;
        return Math.sqrt(dx * dx + dy * dy);
    }
}
```

## Equality and hashing

When a class defines logical equality, implement `equals` and `hashCode` together. Equal objects must have equal hash codes; otherwise hash-based collections such as `HashMap` and `HashSet` can behave incorrectly. Equality should be reflexive, symmetric, transitive, and consistent. Records generate these methods from their components, which is often enough for value objects.

Do not base hash keys on fields that may change while the object is stored in a hash collection. Prefer immutable keys such as strings, enums, and records made from immutable components.

## Collections and generics

Program to interfaces such as `List`, `Set`, and `Map`, and choose implementations by their behavior. `ArrayList` is a good default for indexed sequences and appending. `HashSet` supports average constant-time membership checks. `HashMap` supports average constant-time key lookup. `TreeSet` and `TreeMap` maintain sorted order at additional cost. These performance descriptions are typical, not guarantees for every operation or workload.

Use generics to preserve type information and catch mistakes at compile time: `List<String>` is safer than a raw `List`. Avoid raw types and unchecked casts. Java generics are invariant, so a `List<Integer>` is not a `List<Number>`. For flexible APIs, use bounded wildcards: `? extends T` when reading values as `T`, and `? super T` when adding `T` values (the producer-extends, consumer-super rule).

Return an unmodifiable view or defensive copy when callers should not mutate internal state. `List.of(...)` creates an unmodifiable list, but does not make its elements immutable. Do not modify most collections structurally while iterating with an enhanced `for` loop; use an `Iterator`'s `remove` method or collect changes and apply them afterward.

## Exceptions and resource cleanup

Use exceptions for failures that prevent an operation from succeeding. Validate bad arguments early with `IllegalArgumentException` or `Objects.requireNonNull`. Catch an exception only when you can recover, add useful context, or translate it at a boundary. Avoid empty catch blocks and overly broad `catch (Exception e)` handlers.

Use try-with-resources for files, streams, database connections, and other `AutoCloseable` resources. It closes them even when an exception occurs. Choose checked exceptions when callers can reasonably recover and should be required to address the failure; unchecked exceptions are common for programming errors and violated preconditions.

```java
try (var reader = java.nio.file.Files.newBufferedReader(path)) {
    return reader.lines().toList();
}
```

## Lambdas and streams

Lambdas and method references are useful for short behavior passed to another method. Streams express transformations over data: use `filter`, `map`, and `collect` or terminal operations when they make the flow clearer. A stream is consumed once. Prefer ordinary loops when they are easier to read, when control flow is complex, or when you need to handle checked exceptions inside the loop.

Avoid side effects in intermediate stream operations. A stream pipeline should generally transform data and produce a result, rather than mutate shared state. Do not use parallel streams as an automatic speed improvement; measure first and ensure the work is independent and safe to run concurrently.

```java
List<String> longNames = names.stream()
        .filter(name -> name.length() >= 5)
        .map(String::toUpperCase)
        .toList(); // unmodifiable result on modern Java
```

## Interfaces, inheritance, and composition

Use an interface to describe behavior that multiple implementations can provide. Use `implements` for that contract and `@Override` so the compiler checks overrides. Prefer composition for “has-a” relationships and reuse. Use inheritance for a genuine substitutable “is-a” relationship where subclasses can honor the base type's contract. Favor small interfaces and avoid deep inheritance trees.

Use `abstract` classes when related implementations share state or implementation as well as a contract. Use `sealed` classes or interfaces (Java 17+) when the permitted set of implementations should be explicit. `enum` is a strong choice for a fixed set of named values.

## Packages and project structure

Put related types in packages that reflect responsibilities, and use imports rather than fully qualifying every type. Keep public types focused and avoid circular dependencies between packages. A standard project tool such as Maven or Gradle can manage dependencies, compilation, and tests; keep application code separate from tests and generated build output. Use a consistent Java version across the build configuration and development environment.

## Concurrency basics

A thread shares memory with other threads in the same process. Shared mutable state therefore needs coordination. Prefer immutable data and task-based APIs such as `ExecutorService` over manually creating and managing threads for each task. Use concurrent collections or synchronization when state truly must be shared. `volatile` makes certain reads and writes visible across threads, but does not make compound operations such as incrementing an integer atomic.

Do not assume code is thread-safe because it works in a single-threaded run. Keep concurrency boundaries small, define who owns each piece of mutable state, and use higher-level concurrency utilities before building custom locking protocols.

## Practice

1. Create an immutable `Money` record or class that stores an amount in cents and rejects invalid values.
2. Implement a `Book` value type with correct equality, then use it as a key in a `HashMap`.
3. Write a method that accepts `List<? extends Number>` and returns the sum as a `double`.
4. Read a text file with try-with-resources and return the nonblank lines in uppercase.
5. Model a shopping cart with composition; keep its items private and expose operations that preserve quantity and price rules.
6. Describe which parts of a small task-processing program can be immutable and which, if any, need synchronization.
