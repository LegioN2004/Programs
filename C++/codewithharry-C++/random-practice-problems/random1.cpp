class MyClass {
private:
    int member1;
    int member2;
    static const int defaultValue = 42;

public:
    // Constructor with parameters
    MyClass(int param1, int param2) : member1(param1), member2(param2) {
        // Other constructor tasks
    }

    // Constructor with a single parameter (delegating constructor)
    MyClass(int param) : MyClass(param, defaultValue) {
        // Other constructor tasks
    }

    // Default constructor (delegating constructor)
    MyClass() : MyClass(defaultValue) {
        // Other constructor tasks
    }
};