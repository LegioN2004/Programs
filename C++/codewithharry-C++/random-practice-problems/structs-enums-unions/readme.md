Here are some practice problems to help you understand and apply the concepts of `struct`, `union`, and `enum` in C++:

---

### **Struct Problems**

1. **Basic Struct Usage:**
   - Define a `struct` called `Rectangle` with members `length` and `width`.
   - Write a function to calculate the area of the rectangle.
   - Create an instance of `Rectangle`, initialize its members, and print the area.

   **Solution:**
   ```cpp
   #include <iostream>
   struct Rectangle {
       float length;
       float width;
   };

   float calculateArea(Rectangle rect) {
       return rect.length * rect.width;
   }

   int main() {
       Rectangle rect = {5.0, 3.0};
       std::cout << "Area: " << calculateArea(rect) << std::endl;
       return 0;
   }
   ```

---

2. **Array of Structs:**
   - Define a `struct` called `Student` with members `name`, `rollNumber`, and `marks`.
   - Create an array of 5 `Student` objects, initialize them, and print the details of the student with the highest marks.

   **Solution:**
   ```cpp
   #include <iostream>
   #include <string>

   struct Student {
       std::string name;
       int rollNumber;
       float marks;
   };

   int main() {
       Student students[5] = {
           {"Alice", 1, 95.5},
           {"Bob", 2, 88.0},
           {"Charlie", 3, 92.3},
           {"David", 4, 76.5},
           {"Eve", 5, 89.7}
       };

       int topStudentIndex = 0;
       for (int i = 1; i < 5; i++) {
           if (students[i].marks > students[topStudentIndex].marks) {
               topStudentIndex = i;
           }
       }

       std::cout << "Top Student: " << students[topStudentIndex].name
                 << ", Roll Number: " << students[topStudentIndex].rollNumber
                 << ", Marks: " << students[topStudentIndex].marks << std::endl;
       return 0;
   }
   ```

---

### **Union Problems**

3. **Basic Union Usage:**
   - Define a `union` called `Value` that can hold an `int`, a `float`, or a `char`.
   - Write a program to demonstrate how the same memory location can be used to store different types of data.

   **Solution:**
   ```cpp
   #include <iostream>

   union Value {
       int i;
       float f;
       char c;
   };

   int main() {
       Value val;
       val.i = 42;
       std::cout << "Integer: " << val.i << std::endl;

       val.f = 3.14;
       std::cout << "Float: " << val.f << std::endl;

       val.c = 'A';
       std::cout << "Char: " << val.c << std::endl;

       return 0;
   }
   ```

---

4. **Union in a Struct:**
   - Define a `struct` called `Data` that contains a `union` to store either an `int`, a `float`, or a `char`.
   - Add a `type` field to the `struct` to indicate which member of the union is currently in use.
   - Write a function to print the value stored in the `Data` struct based on the `type`.

   **Solution:**
   ```cpp
   #include <iostream>

   enum DataType { INT, FLOAT, CHAR };

   struct Data {
       DataType type;
       union {
           int i;
           float f;
           char c;
       };
   };

   void printData(Data data) {
       switch (data.type) {
           case INT:
               std::cout << "Integer: " << data.i << std::endl;
               break;
           case FLOAT:
               std::cout << "Float: " << data.f << std::endl;
               break;
           case CHAR:
               std::cout << "Char: " << data.c << std::endl;
               break;
       }
   }

   int main() {
       Data d1 = {INT, .i = 42};
       Data d2 = {FLOAT, .f = 3.14};
       Data d3 = {CHAR, .c = 'A'};

       printData(d1);
       printData(d2);
       printData(d3);

       return 0;
   }
   ```

---

### **Enum Problems**

5. **Basic Enum Usage:**
   - Define an `enum` called `Weekday` with the days of the week.
   - Write a program that takes an integer input (0-6) and prints the corresponding day of the week.

   **Solution:**
   ```cpp
   #include <iostream>

   enum Weekday {
       Monday,
       Tuesday,
       Wednesday,
       Thursday,
       Friday,
       Saturday,
       Sunday
   };

   std::string getDayName(Weekday day) {
       switch (day) {
           case Monday: return "Monday";
           case Tuesday: return "Tuesday";
           case Wednesday: return "Wednesday";
           case Thursday: return "Thursday";
           case Friday: return "Friday";
           case Saturday: return "Saturday";
           case Sunday: return "Sunday";
           default: return "Invalid day";
       }
   }

   int main() {
       int dayInput;
       std::cout << "Enter a number (0-6): ";
       std::cin >> dayInput;

       Weekday day = static_cast<Weekday>(dayInput);
       std::cout << "Day: " << getDayName(day) << std::endl;

       return 0;
   }
   ```

---

6. **Enum in a Struct:**
   - Define a `struct` called `Task` with members `name`, `priority` (an `enum` with values `Low`, `Medium`, `High`), and `status` (an `enum` with values `Pending`, `InProgress`, `Completed`).
   - Create an array of `Task` objects, initialize them, and print the tasks with `High` priority.

   **Solution:**
   ```cpp
   #include <iostream>
   #include <string>

   enum Priority { Low, Medium, High };
   enum Status { Pending, InProgress, Completed };

   struct Task {
       std::string name;
       Priority priority;
       Status status;
   };

   int main() {
       Task tasks[3] = {
           {"Fix Bug", High, InProgress},
           {"Write Docs", Medium, Pending},
           {"Test Code", High, Completed}
       };

       std::cout << "High Priority Tasks:" << std::endl;
       for (const auto& task : tasks) {
           if (task.priority == High) {
               std::cout << "Task: " << task.name
                         << ", Status: " << task.status << std::endl;
           }
       }

       return 0;
   }
   ```

---

### **Mixed Problems**

7. **Struct with Union and Enum:**
   - Define a `struct` called `Vehicle` with members `type` (an `enum` with values `Car`, `Bike`, `Truck`), `details` (a `union` to store specific details for each type), and `mileage`.
   - Write a program to create and display details of different vehicles.

   **Solution:**
   ```cpp
   #include <iostream>
   #include <string>

   enum VehicleType { Car, Bike, Truck };

   struct Vehicle {
       VehicleType type;
       union {
           struct {
               int numSeats;
               std::string model;
           } car;
           struct {
               float topSpeed;
               std::string brand;
           } bike;
           struct {
               float loadCapacity;
               std::string company;
           } truck;
       } details;
       float mileage;
   };

   void printVehicle(Vehicle vehicle) {
       switch (vehicle.type) {
           case Car:
               std::cout << "Type: Car, Seats: " << vehicle.details.car.numSeats
                         << ", Model: " << vehicle.details.car.model
                         << ", Mileage: " << vehicle.mileage << std::endl;
               break;
           case Bike:
               std::cout << "Type: Bike, Top Speed: " << vehicle.details.bike.topSpeed
                         << ", Brand: " << vehicle.details.bike.brand
                         << ", Mileage: " << vehicle.mileage << std::endl;
               break;
           case Truck:
               std::cout << "Type: Truck, Load Capacity: " << vehicle.details.truck.loadCapacity
                         << ", Company: " << vehicle.details.truck.company
                         << ", Mileage: " << vehicle.mileage << std::endl;
               break;
       }
   }

   int main() {
       Vehicle car = {Car, .details.car = {4, "Sedan"}, 15.5};
       Vehicle bike = {Bike, .details.bike = {120.0, "Harley"}, 50.0};
       Vehicle truck = {Truck, .details.truck = {5000.0, "Volvo"}, 8.0};

       printVehicle(car);
       printVehicle(bike);
       printVehicle(truck);

       return 0;
   }
   ```

---

These problems cover a wide range of scenarios and will help you get comfortable with `struct`, `union`, and `enum` in C++. Practice them to strengthen your understanding!