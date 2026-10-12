class Animal {
    void sound(){
        System.out.println("Animal makes this sound");
    }
}

class Cat extends Animal {
    void sound(){
        System.out.println("Cat makes sound meow");
    }
}

class Bird extends Animal {
    void sound(){
        System.out.println("Bird makes sound meow");
    }
}

public class polymorphismDog {
    public static void main(String[] args) {
        Animal myAnimal = new Cat();
        myAnimal.sound();

        Animal myAnimal2 = new Bird();
        myAnimal2.sound();

    }
}


