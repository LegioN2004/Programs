use std::io;

fn main() {
    println!("new guessing game start");

    println!("Guess the number!");
    println!("Input your guess");
     
    let mut guess = String::new();
    // let mut guess: u8 = "hello";
    // let apples = 5; // it is immutable(since the mut keyword is not used) i.e it means once a value is bound to a name, you can’t change that value.
    // let mut bananas = 5; // mut means mutable, meaning its value can be changed later in the program.

    io::stdin()
        .read_line(&mut guess)
        .expect("Failed to read the line");

        println!("You guessed: {guess}");

    print!("byeeeeeeeeeeee");
}
