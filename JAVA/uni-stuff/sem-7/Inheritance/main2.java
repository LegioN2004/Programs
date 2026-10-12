package Inheritance;

class Vehicle {
    String brand;

    Vehicle(String brand) {
        this.brand = brand;
        System.out.println(brand);
    }

    void run() {
        System.out.println("--------- Inside vehicle ------");
        System.out.println(brand);
    }
}

class Bike extends Vehicle {
    int cc;

    Bike(String brand) {
        super(brand);
        this.cc = cc;
        System.out.println("--------- Inside bike ------");
        System.out.println(brand);
        System.out.println(cc);
    }

    @Override 
    void run() {
        System.out.println("hello bike");
    }

}

public class main2 {

    public static void main(String[] args) {
        Bike first = new Bike("Honda AT");

        first.brand = "hello";
        first.cc = 1000;

        first.run();
    }

}
