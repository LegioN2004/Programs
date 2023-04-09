public class Main { // inside this block of {} is the int main of java as found in cpp
	public static void main(String[] args) { //Main function is the entry point of the program it has to be there with the name main
		System.out.println("hello world!!");
		System.out.println(args[0]); // here args is the arguments given in the terminal with java command (like java Main 50 100 ...) after compiling with the javac(like javac Main(class/file name)) and the no inside the [] is the index of the array to which the values given with the java command will be printed , the values given with the java command is stored in the String[] array
				// javac -d _directory_ _name_: this -d flag is used to give a directory to store the .class file
}