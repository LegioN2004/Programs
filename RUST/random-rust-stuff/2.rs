use std::io;

fn main() {
    println!("Enter the first number:");
    let mut first_num = String::new();  // declare a mutable string to store user input
    io::stdin()
        .read_line(&mut first_num)
        .expect("Failed to read line");  // read user input and store it in `first_num`

    let first_num: i32 = first_num.trim().parse().expect("Please enter a valid integer"); // convert user input to integer and reassign it to `first_num`


    println!("Enter the second number:");
    let mut second_num = String::new();
    io::stdin()
        .read_line(&mut second_num)
        .expect("Failed to read line");

    let second_num: i32 = second_num.trim().parse().expect("Please enter a valid integer");



    let sum = first_num + second_num;
    println!("The sum of {} and {} is {}", first_num, second_num, sum);
}
