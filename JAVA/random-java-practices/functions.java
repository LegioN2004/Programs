import java.util.Scanner;

public class functions {
	public static void main(String[] args) {
		// String a = greet();
		// System.out.println(a);

		String personalized = myGreet("Kunal, he has tooo high bp");
		System.out.println(personalized);
		Scanner in = new Scanner(System.in);
		if (hello(in.next()) == "ananda" || hello(in.next()) == "Ananda") {
			System.out.println("You are Ananda and she is a human being");
		} else if (hello(in.next()) == "pratiksha" || hello(in.next()) == "Pratiksha") {
			System.out.println("You are pratiksha and she is a human being");
		} else {
			System.out.println("you are a goru");
		}
	}

	static String myGreet(String name) {
		String message = "Hello, " + name;
		return message;
	}

	static String hello(String naam) {
		String hello = "tuin ugga foulll hoi, " + naam;
		return hello;
	}

	static String greet() {
		String greet = "This is a string";
		return greet;
	}
}
