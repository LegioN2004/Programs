// normal panic
// fn main() {
//     panic!("Hello, world!");
// }

// panic happening here
// fn main() {
//     let v = vec![1, 2, 3];
//
//     v[99];
// }

// file contents reading and using unwrap
// use std::fs::File;
// use std::io::{ Read;
// fn main() {
//     let mut file = File::open("hello.txt").unwrap();
//
//     let mut contents = String::new();
//
//     file.read_to_string(&mut contents).unwrap();
//
//     println!("{}", contents);
// }

// using unwrap_or_else for better and concise error handling
// use std::fs::File;
// use std::io::ErrorKind;
//
// fn main() {
//     let file = File::open("hello.txt").unwrap_or_else(|error| {
//         if error.kind() == ErrorKind::NotFound {
//             File::create("HELLO2.txt").unwrap_or_else(|error| {
//                 panic!("file creation error {:?}", error);
//             })
//         } else {
//             panic!("some other error {:?}", error);
//         }
//     });
// }

// error propagation example using reading a file
// use std::fs::File;
// use std::io::{self, Read};
//
// fn read_username_from_file() -> Result<String, io::Error> {
//     let username_file_result = File::open("hello.txt");
//
//     let mut username_file = match username_file_result {
//         Ok(file) => file,
//         Err(error) => return Err(error),
//     };
//
//     let mut username = String::new();
//
//     match username_file.read_to_string(&mut username) {
//         Ok(_) => Ok(username), // OK(_) because read_to_string returns no of bytes read and not
//         // anything related to the data. Also &mut username because in read_to_string the file
//         // cursor continuously changes.
//         Err(e) => Err(e),
//     }
//     // returns <Ok(usize), Err(io::Error)>
// }
//
// fn main() {
//     println!("{:?}", read_username_from_file());
//     read_username_from_file();
// }

// shorter operation
// use std::fs::File;
// use std::io::{self, Read};
//
// fn read_username_from_file() -> Result<String, io::Error> {
//     let mut username_file = File::open("hello.txt")?;
//
//     let mut username = String::new();
//
//     username_file.read_to_string(&mut username)?;
//     Ok(username)
// }
//
// fn main() {
//     println!("{:?}", read_username_from_file());
//     read_username_from_file();
// }

// even shorter operation
// use std::fs::File;
// use std::io::{self, Read};
//
// fn read_username_from_file() -> Result<String, io::Error> {
//     let mut username = String::new();
//
//     File::open("hello.txt")?.read_to_string(&mut username)?;
//     Ok(username)
// }
//
// fn main() {
//     println!("{:?}", read_username_from_file());
//     read_username_from_file();
// }

// shortest operation
use std::fs;
use std::io;

fn read_username_from_file() -> Result<String, io::Error> {
    fs::read_to_string("hello.txt")
}

fn main() {
    println!("{:?}", read_username_from_file());
    read_username_from_file();
}
