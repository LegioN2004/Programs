# Inheritance

Inheritance is a core pillar of Object-Oriented Programming (OOP) that allows one class to derive properties (fields) and behaviors (methods) from another class.

Instead of writing repetitive code from scratch, you build specialized classes on top of general ones.

---

### 1. The Core Idea: The "IS-A" Relationship

Inheritance models an **"IS-A"** relationship:

* A `Bike` **is a** `Vehicle`.
* A `SavingsAccount` **is a** `BankAccount`.
* A `Developer` **is an** `Employee`.

The class that gives features is called the **Parent class** (Base / Superclass).

The class that inherits features is called the **Child class** (Derived / Subclass).

---

### 2. Basic Syntax: The `extends` Keyword

In Java, you inherit using the `extends` keyword:

```java
// Parent Class (Superclass)
class Vehicle {
    double speed;

    void startEngine() {
        System.out.println("Engine started.");
    }
}

// Child Class (Subclass)
class Bike extends Vehicle {
    int gears = 6;

    void wheelie() {
        System.out.println("Doing a wheelie!");
    }
}

```

When you instantiate `Bike`:

```java
public class Main {
    public static void main(String[] args) {
        Bike myBike = new Bike();

        // 1. Inherited members from Vehicle
        myBike.speed = 80.0;
        myBike.startEngine(); // Output: Engine started.

        // 2. Members specific to Bike
        System.out.println("Gears: " + myBike.gears);
        myBike.wheelie();
    }
}

```

---

### 3. Key Concepts You Must Know

#### A. The `super` Keyword

`super` refers directly to the immediate parent class. It has two main uses:

1. **Calling the parent constructor:** `super()` must be the **first line** inside a child constructor.
2. **Accessing overridden methods or parent variables:** `super.startEngine()`.

```java
class Vehicle {
    String brand;

    Vehicle(String brand) {
        this.brand = brand;
    }
}

class Bike extends Vehicle {
    int cc;

    Bike(String brand, int cc) {
        super(brand); // Passes brand up to Vehicle constructor
        this.cc = cc;
    }
}

```

#### B. Access Modifiers in Inheritance

* `public`: Inherited everywhere.
* `protected`: Inherited by subclasses (even if in different packages).
* `default` (package-private): Inherited only if the child is in the **same package**.
* `private`: **Never directly inherited** or accessible by child classes. Use public/protected getters and setters to interact with private fields.

#### C. Preventing Inheritance: `final`

* If a class is declared `final`, it **cannot be extended**:
```java
final class SecuritySystem { ... } // No class can extend this

```


* If a method is declared `final`, subclasses **cannot override** it:
```java
final void calculateTax() { ... }

```



---

### 4. Types of Inheritance in Java

```
1. Single:           Parent ───► Child
2. Multilevel:       Grandparent ───► Parent ───► Child
3. Hierarchical:     Parent ───► ChildA
                            └───► ChildB

```

* **Single:** One child extends one parent (`Bike extends Vehicle`).
* **Multilevel:** A chain of inheritance (`ElectricBike extends Bike extends Vehicle`).
* **Hierarchical:** Multiple children extend one parent (`Bike extends Vehicle`, `Car extends Vehicle`).
* **Multiple Inheritance with Classes is NOT allowed:** Java does **not** allow `class C extends A, B` to avoid ambiguity (the classic "Diamond Problem"). Multiple inheritance is achieved using **Interfaces** instead.

---

### A Quick Check

Consider this scenario:

```java
class A {
    A() {
        System.out.print("A ");
    }
}

class B extends A {
    B() {
        System.out.print("B ");
    }
}

```

If you run `B obj = new B();`, in what order do you think the constructors will execute, and what will print to the console?

Let's verify the execution mechanism step by step.

1. When you instantiate a subclass using `new B()`, control enters constructor `B()`.
2. Because constructor `B()` does not explicitly specify a constructor call as its first statement, the Java compiler automatically inserts a call to the no-argument superclass constructor: `super();`.
3. Before executing the body of `B()`, the call `super()` jumps execution to constructor `A()`.
4. Constructor `A()` runs first and outputs `"A "`.
5. Once `A()` finishes, execution returns to complete the body of `B()`, which outputs `"B "`.

The console output is:

```text
A B 

```

The parent class constructor runs first, so your answer is correct.