# Important notes

# tut 12 - All about the doubts pointers

Your understanding is mostly correct, but I’ll clarify and correct a few things to ensure accuracy.

### Given Code

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 3;
    int* b = &a;
    cout << b << endl;

    cout << "The address of a is " << &a << endl;
    cout << "The address of a is " << b << endl;

    int** c = &b;
    cout << "The address of b is " << &b << endl;
    cout << "The address of b is " << c << endl;
    cout << "The address of c is " << *c << endl;
    cout << "The value at address c is " << **c << endl;

    return 0;
}
```

---

### Breakdown

#### 1️⃣ **Understanding `a` and `b`**

```cpp
int a = 3;
int* b = &a;
```

- `a` is a normal integer with the value `3`.
- `b` is a pointer to `a`, meaning `b` stores the **memory address of `a`**.

#### 2️⃣ **Printing Memory Addresses**

```cpp
cout << b << endl;
cout << "The address of a is " << &a << endl;
cout << "The address of a is " << b << endl;
```

- `b` stores the address of `a`, so `cout << b;` and `cout << &a;` will print the **same address**.

#### 3️⃣ **Introducing `c`, a Double Pointer**

```cpp
int** c = &b;
```

- `c` is a **pointer to a pointer**, meaning `c` stores the **address of `b`**.

#### 4️⃣ **Printing the Address of `b`**

```cpp
cout << "The address of b is " << &b << endl;
cout << "The address of b is " << c << endl;
```

- `&b` gives the **memory address of `b`**.
- `c` stores `&b`, so `cout << c;` prints the **same address as `&b`**.

#### 5️⃣ **Dereferencing `c`**

```cpp
cout << "The address of c is " << *c << endl;
```

- `*c` means "the value stored at `c`".
- Since `c` stores `&b`, `*c` is `b`, which stores `&a`.
- Therefore, `*c` prints the **address of `a`**.

#### 6️⃣ **Dereferencing `*c` Further**

```cpp
cout << "The value at address c is " << **c << endl;
```

- `**c` means "the value at the address stored in `b`".
- Since `b` stores `&a`, `*b` is `a`, which is `3`.
- Therefore, `**c` prints `3`.

---

### Corrected Explanation

| Expression | What It Stores                             | What It Prints        |
| ---------- | ------------------------------------------ | --------------------- |
| `b`        | Address of `a`                             | Prints address of `a` |
| `&a`       | Address of `a`                             | Prints address of `a` |
| `c`        | Address of `b`                             | Prints address of `b` |
| `&b`       | Address of `b`                             | Prints address of `b` |
| `*c`       | Value stored in `c` (which is `b`)         | Prints address of `a` |
| `**c`      | Value stored at address `b` (which is `a`) | Prints `3`            |

---

### Minor Mistake in Your Explanation

> "**c = &b**"  
> **Correction:** `c` is **already** declared as `int** c = &b;`, meaning `c` stores the **address of `b`**, not `&b` itself.

# Tut 14: about enums, structs and unions

In C++, `struct`, `union`, and `enum` are three distinct constructs used for different purposes. Here's a detailed explanation of each, along with their differences:

### 1. **Struct (Structure)**

- **Purpose:** A `struct` is used to group related data members under a single name. Each member has its own memory location.
- **Memory Allocation:** The size of a `struct` is the sum of the sizes of all its members (plus padding for alignment).
- **Usage:** Used to represent a collection of related data, such as a record or an object with multiple attributes.
- **Example:**

  ```cpp
  struct Point {
      int x;
      int y;
  };
  ```

  - Members `x` and `y` are independent and can be accessed simultaneously.
  - Example usage:

    ```cpp
    Point p;
    p.x = 10;
    p.y = 20;
    ```

---

### 2. **Union**

- **Purpose:** A `union` is used to store different types of data in the same memory location. Only one member can hold a value at any given time.
- **Memory Allocation:** The size of a `union` is the size of its largest member.
- **Usage:** Used when you need to save memory or represent a variable that can hold different types of data at different times.
- **Example:**

  ```cpp
  union Data {
      int i;
      float f;
      char c;
  };
  ```

  - Members `i`, `f`, and `c` share the same memory location.
  - Example usage:

    ```cpp
    Data d;
    d.i = 10;       // Store an integer
    d.f = 3.14;     // Overwrite with a float
    d.c = 'A';      // Overwrite with a character
    ```

---

### 3. **Enum (Enumeration)**

- **Purpose:** An `enum` is used to define a set of named integer constants, making code more readable and maintainable.
- **Memory Allocation:** Each enumerator is an integer constant, and the size of an `enum` is typically the size of an `int`.
- **Usage:** Used to represent a set of related named constants, such as days of the week, states, or options.
- **Example:**

  ```cpp
  enum Day {
      Monday,    // 0
      Tuesday,   // 1
      Wednesday, // 2
      Thursday,  // 3
      Friday,    // 4
      Saturday,  // 5
      Sunday     // 6
  };
  ```

  - Each enumerator is assigned an integer value starting from 0 by default.
  - Example usage:

    ```cpp
    Day today = Wednesday;
    if (today == Wednesday) {
        std::cout << "It's Wednesday!" << std::endl;
    }
    ```

---

### Key Differences

| Feature               | Struct                         | Union                                    | Enum                            |
| --------------------- | ------------------------------ | ---------------------------------------- | ------------------------------- |
| **Purpose**           | Group related data members     | Store different types in the same memory | Define named integer constants  |
| **Memory Allocation** | Sum of all members (+ padding) | Size of the largest member               | Size of an `int` (typically)    |
| **Member Access**     | All members can be accessed    | Only one member at a time                | Enumerators are constants       |
| **Use Case**          | Represent records or objects   | Save memory or variant types             | Represent sets of constants     |
| **Example**           | `struct Point { int x, y; };`  | `union Data { int i; float f; };`        | `enum Day { Monday, Tuesday };` |

---

### Combined Example

Here’s an example that demonstrates the use of `struct`, `union`, and `enum` together:

```cpp
#include <iostream>

// Enum for days of the week
enum Day {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

// Union to store different types of data
union Data {
    int i;
    float f;
    char c;
};

// Struct to group related data
struct Employee {
    int id;
    Day shift;  // Using enum
    Data info;  // Using union
};

int main() {
    Employee emp;
    emp.id = 101;
    emp.shift = Wednesday;

    // Using the union in the struct
    emp.info.i = 42;  // Store an integer
    std::cout << "Employee ID: " << emp.id << ", Shift: " << emp.shift << ", Data: " << emp.info.i << std::endl;

    emp.info.f = 3.14;  // Overwrite with a float
    std::cout << "Employee ID: " << emp.id << ", Shift: " << emp.shift << ", Data: " << emp.info.f << std::endl;

    return 0;
}
```

---

## more about enums

### **What is an Enum in C++?**

An **enum** (short for **enumeration**) is a user-defined data type that consists of a set of named integral constants. It allows you to define a variable that can take only one of the predefined constant values.

Enums are useful for improving code readability and maintainability by giving meaningful names to integral values.

---

## **1️⃣ Declaring Enums**

### **Basic Enum Declaration**

```cpp
enum Color { RED, GREEN, BLUE };
```

- `RED` is assigned `0`, `GREEN` is `1`, `BLUE` is `2` by default.
- These values are of type `int`.

**Usage:**

```cpp
Color c1 = GREEN;
cout << c1; // Output: 1
```

---

## **2️⃣ Assigning Custom Values**

You can assign custom values to enum constants.

```cpp
enum Color { RED = 10, GREEN = 20, BLUE = 30 };
```

- `RED` is `10`, `GREEN` is `20`, `BLUE` is `30`.

**Usage:**

```cpp
Color c2 = BLUE;
cout << c2; // Output: 30
```

---

## **3️⃣ Partially Assigned Values**

```cpp
enum Status { IDLE = 1, RUNNING, STOPPED = 5, PAUSED };
```

- `IDLE = 1`
- `RUNNING = 2` (auto-incremented)
- `STOPPED = 5`
- `PAUSED = 6` (incremented from `STOPPED`)

**Usage:**

```cpp
cout << RUNNING; // Output: 2
cout << PAUSED;  // Output: 6
```

---

## **4️⃣ Scoped Enums (`enum class`)**

C++11 introduced **`enum class`**, which provides **strongly typed** enums, preventing implicit conversions to `int`.

```cpp
enum class Color { RED, GREEN, BLUE };
```

- **No implicit conversion to `int`** (unlike regular enums).
- **Safer** (no accidental assignment of unrelated integer values).
- Values must be accessed with the **enum name** (`Color::RED`).

**Usage:**

```cpp
Color c3 = Color::GREEN;
cout << static_cast<int>(c3); // Output: 1
```

---

## **5️⃣ Using Enums with `typedef` (C++98) or `using` (C++11)**

### **C++98 `typedef` with Enum**

```cpp
typedef enum { SUCCESS, FAILURE } Result;
```

- This allows `Result` to be used as a type directly.

### **C++11 `using` with Enum**

```cpp
using Result = enum { SUCCESS, FAILURE };
```

**Usage:**

```cpp
Result r = SUCCESS;
cout << r; // Output: 0
```

---

## **6️⃣ Using Enum with `switch`**

Enums are often used in `switch` statements for better readability.

```cpp
enum Day { MON, TUE, WED, THU, FRI, SAT, SUN };

void checkDay(Day d) {
    switch (d) {
        case MON: cout << "Monday"; break;
        case FRI: cout << "Friday"; break;
        default: cout << "Other day"; break;
    }
}

int main() {
    checkDay(FRI); // Output: Friday
}
```

---

## **7️⃣ Enum in a Class**

Enums can be **declared inside classes**.

```cpp
class TrafficLight {
public:
    enum Light { RED, YELLOW, GREEN };
};
```

**Usage:**

```cpp
TrafficLight::Light signal = TrafficLight::RED;
cout << signal; // Output: 0
```

---

## **8️⃣ Enums with Bit Flags**

Enums can be used as bit flags by assigning values in powers of `2`.

```cpp
enum Permission {
    READ = 1,  // 0001
    WRITE = 2, // 0010
    EXEC = 4   // 0100
};
```

**Usage:**

```cpp
Permission p = static_cast<Permission>(READ | WRITE);
cout << p; // Output: 3 (0001 | 0010 = 0011)
```

---

## **9️⃣ Printing Enum Values as Strings**

Since enums are stored as integers, you need a helper function to print names.

```cpp
enum Color { RED, GREEN, BLUE };

string getColorName(Color c) {
    switch (c) {
        case RED: return "RED";
        case GREEN: return "GREEN";
        case BLUE: return "BLUE";
        default: return "UNKNOWN";
    }
}

cout << getColorName(GREEN); // Output: GREEN
```

---

## **🔹 When to Use Enums?**

✅ When you have **a fixed set of related constants**.  
✅ When you need **better readability** in code instead of using `int` values directly.  
✅ When using **switch-case statements** for controlling logic.  
✅ When you need **strong typing** (`enum class`).

---

### **🔹 Summary Table**

| Feature                              | `enum` | `enum class` |
| ------------------------------------ | ------ | ------------ |
| Implicit conversion to `int`         | ✅ Yes | ❌ No        |
| Scoped                               | ❌ No  | ✅ Yes       |
| Requires prefix (e.g., `Color::RED`) | ❌ No  | ✅ Yes       |
| Type safety                          | ❌ No  | ✅ Yes       |

---

### **Final Example with Everything**

```cpp
#include <iostream>
using namespace std;

enum class Color { RED = 1, GREEN = 2, BLUE = 3 };
enum Status { IDLE = 0, RUNNING = 1, STOPPED = 5 };

int main() {
    Color c = Color::GREEN;
    Status s = RUNNING;

    cout << "Color: " << static_cast<int>(c) << endl; // Output: 2
    cout << "Status: " << s << endl; // Output: 1

    return 0;
}
```

🚀 **Now you know everything about Enums!**

# tutorial 17

Need of Inline Functions
When a function is called, the CPU stores the return address, copies arguments to the stack, and transfers control to the function. After execution, the return value is stored, and control is returned to the caller. This overhead can be significant for small, frequently used functions, as their execution time is less than the time spent on the call and return process.

This is where the inline functions shine. They remove this overhead by substituting the code of the function in place of function call.

One other thing to remember is that it is only useful to make the function inline if the time spent during a function call is more compared to the function body execution time.

An example where the inline function has no effect at all:

```cpp
inline void show()
{
    cout << “value of S = ” << S << endl;
}
```

The above function relatively takes a long time to execute. In general, a function that performs an input-output (I/O) operation shouldn’t be defined as inline because it spends a considerable amount of time.

Appropriate use of inline functions can provide performance enhancement but if inline functions are used arbitrarily then they can’t provide better results. In other words, don’t make every function inline. It is better to keep inline functions as small as possible.

### **🔹 What is an Inline Function in C++?**

An **inline function** is a function that is **expanded at compile time** instead of being called like a normal function. The compiler replaces the function call with the actual function code, which can **reduce function call overhead** and **improve execution speed**.

To declare an inline function, use the `inline` keyword before the function definition.

---

## **🔹 Why Use Inline Functions?**

1. **Avoids Function Call Overhead**

   - Normally, when a function is called, the CPU has to:
     1. Store the return address.
     2. Pass arguments.
     3. Jump to the function location.
     4. Execute the function.
     5. Return to the stored address.
   - This overhead is eliminated with inline functions.

2. **Faster Execution for Small Functions**

   - Ideal for **small, frequently used** functions.

3. **Better Optimization**

   - The compiler can optimize inlined code better than separately called functions.

4. **Useful for Getters and Setters**
   - Small functions like getters and setters in classes are often inlined.

---

## **🔹 How to Declare an Inline Function**

The `inline` keyword is placed before the function definition.

```cpp
#include <iostream>
using namespace std;

// Inline function definition
inline int square(int x) {
    return x * x;
}

int main() {
    cout << "Square of 5: " << square(5) << endl; // Output: 25
    return 0;
}
```

🔹 **How it Works:**

- Instead of making a function call to `square(5)`, the compiler replaces it with `5 * 5` directly in the code.

---

## **🔹 Inline Functions with Classes**

In classes, methods defined **inside the class body** are automatically treated as inline.

```cpp
#include <iostream>
using namespace std;

class Math {
public:
    inline int cube(int x) {  // Inline function
        return x * x * x;
    }
};

int main() {
    Math m;
    cout << "Cube of 3: " << m.cube(3) << endl; // Output: 27
    return 0;
}
```

📌 **Note:**

- Since `cube(int x)` is defined inside the class, it is **implicitly inline**.

---

## **🔹 Inline Function with Default Arguments**

Inline functions can have **default arguments**, just like normal functions.

```cpp
#include <iostream>
using namespace std;

inline void greet(string name = "User") {
    cout << "Hello, " << name << "!" << endl;
}

int main() {
    greet();         // Output: Hello, User!
    greet("Alice");  // Output: Hello, Alice!
    return 0;
}
```

🔹 **How it Works:**

- If no argument is passed, it defaults to `"User"`.

---

## **🔹 When NOT to Use Inline Functions**

❌ **For Large Functions:**

- If the function is large, inlining increases **code size** (code bloat).
- This can **increase memory usage** and **reduce cache efficiency**.

❌ **For Recursion & Loops:**

- Functions with loops or recursion should NOT be inlined.
- Since recursion requires function calls, inlining does not work effectively.

```cpp
inline int factorial(int n) {  // ❌ Bad use of inline
    return (n <= 1) ? 1 : n * factorial(n - 1);
}
```

❌ **When Used Frequently Across Different Files:**

- If an inline function is used in multiple files, it can lead to **duplicate copies** of the function in each translation unit, increasing the binary size.

---

## **🔹 Summary**

| Feature           | Inline Function                   |
| ----------------- | --------------------------------- |
| Function Overhead | Eliminated                        |
| Execution Speed   | Faster (for small functions)      |
| Suitable for      | Short functions, Getters/Setters  |
| Not Suitable for  | Large functions, Recursion, Loops |

---

## **🔹 Final Example**

```cpp
#include <iostream>
using namespace std;

inline int add(int a, int b) {
    return a + b;
}

int main() {
    cout << "Sum: " << add(4, 5) << endl; // Output: 9
    return 0;
}
```

✔️ **The compiler replaces `add(4, 5)` with `4 + 5` directly in the code.**  
✔️ **Reduces function call overhead.**

🚀 Now you know **what inline functions are, why to use them, and when NOT to use them!**

# tut 18: Recursion

Yes! Let's break it down step by step to understand **how the multiplication happens** in the recursive factorial function.

---

## **Step-by-Step Breakdown of Factorial Function**

### **Function Code**

```cpp
int factorial(int n) {
  if (n <= 1) {
    return 1; // Base case: When n is 1 or 0, return 1
  }
  return n * factorial(n - 1); // Recursive case: Multiply n with factorial(n-1)
}
```

---

## **🔹 How Recursion Works**

When you call `factorial(5)`, **the function does NOT immediately multiply everything**.  
Instead, it **keeps calling itself** until it reaches the base case (`n <= 1`).

Let's go step by step:

| Call           | Condition (`n <= 1`?) | What Happens               |
| -------------- | --------------------- | -------------------------- |
| `factorial(5)` | No                    | Returns `5 * factorial(4)` |
| `factorial(4)` | No                    | Returns `4 * factorial(3)` |
| `factorial(3)` | No                    | Returns `3 * factorial(2)` |
| `factorial(2)` | No                    | Returns `2 * factorial(1)` |
| `factorial(1)` | Yes ✅                | Returns `1` (Base Case)    |

🔹 Now, the recursion starts **returning values back up the call stack**.

---

## **🔹 How Multiplication Happens**

The function calls **pause at each step** until they reach the base case.  
Then, they **return values back up the stack**, multiplying at each step.

### **Stack Unfolding (Returning Phase)**

Now, each function call **returns** the computed value to its previous caller:

| Call                                  | What it Returns |
| ------------------------------------- | --------------- |
| `factorial(1)` returns `1`            |
| `factorial(2)` returns `2 * 1 = 2`    |
| `factorial(3)` returns `3 * 2 = 6`    |
| `factorial(4)` returns `4 * 6 = 24`   |
| `factorial(5)` returns `5 * 24 = 120` |

### **Final Answer**

`factorial(5)` returns `120`, so `cout << factorial(5);` prints:

```
The factorial of 5 is 120
```

---

## **🔹 Key Takeaways**

1️⃣ **First, function calls stack up until the base case is reached.**  
2️⃣ **The base case (`n = 1`) returns 1.**  
3️⃣ **Then, the values are returned step by step, multiplying at each level.**  
4️⃣ **Multiplication only happens during the return phase, NOT during the function call phase.**

---

### **🔹 Example with `n = 3`**

```cpp
factorial(3)
= 3 * factorial(2)
= 3 * (2 * factorial(1))
= 3 * (2 * 1)
= 3 * 2
= 6
```

📌 **Notice:**

- Function calls **keep stacking** until `factorial(1)` is reached.
- Then, multiplication happens **as the calls return**.

---

## **🔹 Visual Representation of Call Stack**

At `n = 5`, the **function calls stack up** like this:

```
factorial(5)
    ├── factorial(4)
    │       ├── factorial(3)
    │       │       ├── factorial(2)
    │       │       │       ├── factorial(1)  <-- Base case, returns 1
```

Then, **returns and multiplies back**:

```
factorial(5) = 5 * 24
factorial(4) = 4 * 6
factorial(3) = 3 * 2
factorial(2) = 2 * 1
factorial(1) = 1  <-- Base case
```

# Friend functions

```cpp
#include <iostream>
using namespace std;

class Complex {
  int a, b;

public:
  void setNumber(int n1, int n2) {
    a = n1;
    b = n2;
  }

  friend Complex sumComplex(Complex o1, Complex o2);

  void printNumber() {
    cout << "Your number is " << a << " + " << b << "i" << endl;
  }
};

// It doesn't become a part of the class, it just gets some permissions to use
// the values of the data members
Complex sumComplex(Complex o1, Complex o2) {
  // this is wrong, since you are accessing the private data members, so you got
  // to define it as friend inside the class(declaration is opitional outside or
  // inside as per necessary)
  Complex o3;
  o3.setNumber((o1.a + o2.a), (o1.b + o2.b));
  return o3;
}

int main() {
  Complex c1, c2, sum;
  c1.setNumber(1, 4);
  c1.printNumber();

  c2.setNumber(5, 8);
  c2.printNumber();

  sum = sumComplex(c1, c2);
  sum.printNumber();
  return 0;
}
```

Friend functions are not members of the class, but they can access private and protected members of the class. They are declared inside the class with the `friend` keyword, allowing them to access private data members directly.

It doesn't become a part of the class, it just gets some permissions to use the values of the data members.
`Complex sumComplex(Complex o1, Complex o2) {`
Just using this is wrong, since you are accessing the private data members, so you got to define it as friend inside the class(declaration is optional outside or inside as per necessary).

properties of friend functions

- not in the scope of the class
- It is a non-member function that is allowed to do any  with the private data members of the class.
- Since it is not in the scope of the class, it cannot be called from the object of the class. c1.sumComplex() is invalid
- can be invoked without the help of the object of the class
- usually contains the objects as arguments
- can be declared inside the public or private section of the class, doesn't matter
- It cannot access the members directly by their names so has to use the object name like `object_name.member_name` to access any member.

# Inheritance

Inheritance is a way to form new classes using classes that have already been defined. The new class is called the derived class, and the class from which it is derived is called the base class. The derived class inherits all the features from the base class and can have additional features of its own.

- Reusability of code: The derived class can use the members of the base class, which means you don't have to rewrite the same code again.
- Extensibility: You can add new features to the derived class without modifying the base class alongside reusing it.
- Reusing classes saves time and effort in programming, as you can build upon existing classes rather than starting from scratch.
- Reusing already tested and debugged classes reduces the efforts of developing and debugging the same thing again since that's what the inheritance is all about.
- We can reuse the properties of an existing class by inheriting from it.
- The existing class is called the *base class* or *parent class*, and the new class is called the *derived class* or *child class*.
- There are many different types of inheritance in C++ like single inheritance, multiple inheritance, hierarchical inheritance, multilevel inheritance, and hybrid inheritance.

Types of inheritance:

- Single inheritance: A derived class inherits from a single base class.
- Multiple inheritance: A derived class inherits from multiple base classes.
- Multilevel inheritance: A derived class inherits from another derived class.
- Hierarchical inheritance: Multiple derived classes inherit from a single base class.
- Hybrid inheritance: A combination of two or more types of inheritance.
- Multilevel inheritance: A derived class inherits from another derived class.

## How are you inheriting your derived class?

- *Default visiblity mode(private)*: If inheriting derived class using default access specifier => public members of the base class becomes private members of the derived class. The private members of the base class will not be accessible in the derived class, but the protected members of the base class will become the private members of the derived class.
- *Public visibility mode*: If you are inheriting your derived class using the public access specifier, then the public members of the base class will become the public members of the derived class as well. The private members of the base class will not be accessible in the derived class, but the protected members of the base class will become the protected members of the derived class.
- *Private visibility mode*: If you are inheriting your derived class using the private access specifier, then the public members of the base class will become the private members of the derived class. The private members of the base class will not be accessible in the derived class, but the protected members of the base class will become the private members of the derived class.
- *Protected visibility mode*: If you are inheriting your derived class using the protected access specifier, then the public members of the base class will become the protected members of the derived class. The private members of the base class will not be accessible in the derived class, but the protected members of the base class will become the protected members of the derived class.
- *Private members cannot be inherited*
