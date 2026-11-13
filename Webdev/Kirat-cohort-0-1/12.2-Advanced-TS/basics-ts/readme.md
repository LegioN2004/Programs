# type inference

TypeScript is smart enough to infer types based on the assigned values. For example:

```typescript
let name = "milinda"; // TypeScript infers the type of 'name' as string
console.log(name);
```

This means that once a variable is assigned a value of a certain type, TypeScript will not allow you to assign a value of a different type to that variable later on. For example, the following code will result in an error:

```typescript
name = 42; // Error: Type 'number' is not assignable to type 'string'
```

To fix this, you can explicitly declare the type of the variable when you define it:

```typescript
let name: string = "milinda"; // Explicitly declaring the type as string
name = 42; // Error: Type 'number' is not assignable to type
```

```typescript
let age: number = 30; // Explicitly declaring the type as number
age = "thirty"; // Error: Type 'string' is not assignable to type 'number'
```

and more ....

This helps catch type-related errors at compile time, making your code more robust and easier to maintain.

## tsconfig.json

This file makes rules for what to do with the transpilation of ts to js.

- By default, ts compiles down to js even if theres' a type error. If you don't want that to happen, you will need to change the config file to
