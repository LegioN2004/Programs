package Inheritance;

class Vehicle {
    double speed;


    void startEngine() {
        System.out.println("vehicle engine vroom vroom");
    }
}

class Bike extends Vehicle {
    int gear;

    void wheelie() {
        System.out.println("Doing wheelie beeek");
    }
}

public class Main {
    public static void main(String[] args) {
        Bike bike = new Bike();
        
        bike.gear = 1;
        bike.startEngine();

        System.out.println("Gears: " + bike.gear);
        System.out.println("Speed: " + bike.speed);

        bike.wheelie();
    }
}