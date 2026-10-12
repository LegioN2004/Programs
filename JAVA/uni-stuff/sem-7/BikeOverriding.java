class Vehicle {
    void run() {
        System.out.println("Vehicle is running");
    }
}

public class BikeOverriding extends Vehicle {

    @Override 
    void run() {
        System.out.println("Bike is running safely");
    }

    public static void main(String[] args) {
        BikeOverriding obj = new BikeOverriding();
        obj.run();
    }
}
