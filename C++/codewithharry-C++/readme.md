# Important notes

## Tutorial 14

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

| Feature                | Struct                          | Union                          | Enum                          |
|------------------------|---------------------------------|--------------------------------|-------------------------------|
| **Purpose**            | Group related data members      | Store different types in the same memory | Define named integer constants |
| **Memory Allocation**  | Sum of all members (+ padding)  | Size of the largest member     | Size of an `int` (typically)  |
| **Member Access**      | All members can be accessed     | Only one member at a time      | Enumerators are constants     |
| **Use Case**           | Represent records or objects    | Save memory or variant types   | Represent sets of constants   |
| **Example**            | `struct Point { int x, y; };`   | `union Data { int i; float f; };` | `enum Day { Monday, Tuesday };` |

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

