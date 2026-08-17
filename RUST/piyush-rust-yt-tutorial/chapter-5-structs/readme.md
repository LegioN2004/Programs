# Structs

- Structs are similar to tuples, in that both hold multiple related values.
- Like tuples, the pieces of a struct can be different types. Unlike with tuples, in a struct you’ll name each piece of data so it’s clear what the values mean.
- Adding these names means that structs are more flexible than tuples: You don’t have to rely on the order of the data to specify or access the values of an instance.
- Then, inside curly brackets, we define the names and types of the pieces of data, which we call fields. Following example, shows a struct that stores information about a user account.

```rust
struct User {
    active: bool,
    username: String,
    email: String,
    sign_in_count: u64,
}
```

(here in the above, String is an owned String which means on creating this
struct the User struct will take ownership of this String variable. We aren't
defining &str otherwise we need to specify in lifetimes)

- To use a struct after we’ve defined it, we create an instance of that struct by specifying concrete values for each of the fields.
- We create an instance by stating the name of the struct and then add curly brackets containing key: value pairs, where the keys are the names of the fields and the values are the data we want to store in those fields.
- We don’t have to specify the fields in the same order in which we declared them in the struct. In other words, the struct definition is like a general template for the type, and instances fill in that template with particular data to create values of the type. For example, we can declare a particular user as shown in Listing 5-2.

```rust
fn main() {
    let user1 = User {
        active: true,
        username: String::from("someusername123"),
        email: String::from("someone@example.com"),
        sign_in_count: 1,
    };
}
```

- to add values you can do this(after converting to mut), `user1.username = String::from("hello name");` or another way `user1.username.push_str("hello name");`

```rust
fn main() {
    let user1 = User {
        active: true,
        username: String::from("someusername123"),
        email: String::from("someone@example.com"),
        sign_in_count: 1,
    };
}

// no errors because active is in the stack, not heap
let s1 = user1.active;
println!("value: {}", user1.active);

// errors because username is in the heap
let s1 = user1.username;
println!("value: {}", user1.username);

// but if the ownership is moved
let s1 = user1.username; // s1 will have old user1 address
user1.username = String::from("new username"); // but this will have new address
println!("value: {}", user1.username);
```

- it's not possible to make a certain field mut.
