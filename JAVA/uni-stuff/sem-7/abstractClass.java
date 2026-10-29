abstract class Vehicle {
    int speed;
    abstract void accelerate(); // Abstract method
}

class Car extends Vehicle {
    void accelerate() {
        System.out.println("Car accelerates");
    }
}

class Bike extends Vehicle {
    void accelerate() {
        System.out.println("Bike accelerates");
    }
}

public class abstractClass {
    public static void main(String[] args) {
        Vehicle myCar = new Car();
        myCar.accelerate(); // Output: Car accelerates
        Vehicle myBike = new Bike();
        myBike.accelerate(); // Output: Bike accelerates
    }
}