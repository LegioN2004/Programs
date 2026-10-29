class Bike {
    String model = "Duke 390";
    int cc = 399;

    @Override
    public String toString() {
        return "Bike: " + model + " having cc: " + cc;
    }
}

public class ToString {
    public static void main(String[] args) {
        Bike b = new Bike();
        System.out.println(b);
    }
}
