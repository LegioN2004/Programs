# JWT and Auth Recap

## Bank example

Cheque book

1. Whenever I have to pay someone, I sign the cheque
2. Everyone can see my sign
3. People can try to do the same sign on their cheque book
4. Bank won't accept theirs, will only accept my cheque

This cheque book == my JWT

considering the cheque I get from the bank is already signed, so I will have to keep it very safe

Cheque is

1. Something that the bank gives me the first time I visit it(sign in)
2. Something I need to keep safe, if I lose it anyone can take out my account
3. recreating the signature or the cheque will get caught and will not be allowed to take any money out
4. But if the theif sends the exact signed cheque of the main person, then they can take out money

JWTs are just like these cheques. They're issued by the backend when you sign in. Anyone can create something very similar, but the backend would reject it. If you lose the original jwt, then it is a problem

### Things to understand before creating JWTs

1. generating: Whenever you have a backend server, generating means to the bank issuing generating a chequebook. Somehow does something that can lets the bank differentiate between a fake and a real one. The backend does the same, it generates a veryyy long string using the password and email combo which is called a JWT, and if it directly comes to the backend then it can verify that the user is genuine one
2. decoding: Other people can look at and hence 'decode' it if they get the jwt. They can get very close to the original jwt but the next step
3. verifying: Other people who can generate the almost original jwt can only pass through the target if the site can verify it and as such only the backend can verify it since it needs a password. So it is useless to decode and get the almost original jwt.

The only difference between them is that decoding gives you the details that lies kind of a secret in the long string(which can be shown) on the other hand verifying is done only by the backend using the same decoding process plus an extra step, the specific 'password' that was used in the first place for signing in which only then makes the verification possible

## Try and Catch, throwing and catching errors in JS

```js
function getLength(name) {
  return name.length;
}

// error point(normal syntax)
// const ans = getLength();
// console.log(ans);
// console.log("hiiiiiiiiiiiiiiiiii");

// introducing try catches
try {
  const ans = getLength();
  console.log(ans);
} catch (error) {
  // aorstni
}

console.log("hiiiiiiiiiiiii");
```

- undefined is another kind of error where a variable that is not defined throws an error 'undefined' when used.
- Developers do make these kind of mistakes which makes the compiler panic and stops the code from running further. And so in these kind of erros the compiler throws an error.
- In the above example we get the error: cannot read undefined, which means that the length variable is undefined of whom the value is being returned.

```
return name.length;
              ^

TypeError: Cannot read properties of undefined (reading 'length')
```

- This above error is called an "exception". When an exception is raised, the process exits since the JS program doesn't want to proceed anymore.
  - So the control never reaches in the last console.log. But you still may want to continue the program even if there is an error, that's where try catches come in.
  - If we know there is a certain codebase that is unsafe and may throw errors, we wrap it inside try-catch. But how are we supposed to know that and even if we know we are going to write buggy then we will not write that in the first place.
  - Bunch of times we will know that there will be errors so in such cases using a try-catch is a very good practice. For example: jwt.verify either runs or thwors errors
- What happens in a try-catch statetment, is that whenever there is an exception thrown inside the try block it stops the code execution then and there and then reaches the catch statement and starts executing the code in that block. Most of the times the catch will contain an error message. If the code is correct, the control will never reach the catch block. And everything else after the catch block will proceed any way

### JWT

- jwt.verify is a different function from the others, like decode and sign, mainly the Error Handling:
  - jwt.verify throws an error if verification fails, providing detailed information about the issue.
  - jwt.decode does not perform verification and doesn't throw errors related to signature issues.

```js
function signJwt(username, password) {
  // Your code here
  const usernameParse = usernameSchema.safeParse(username);
  const passwordParse = passwordSchema.safeParse(password);
  if (!usernameParse.success || !passwordParse.success) {
    return null;
  }
  const token = jwt.sign({ username }, jwtPassword);
  return token;
}
```

Explanation:

1. **Zod Schemas:**

   - `usernameSchema` and `passwordSchema` are Zod schemas for validating the username and password.
   - `.email()` ensures that the `username` is a valid email address.
   - `.min(6)` ensures that the `password` has a minimum length of 6 characters.

2. **Zod `.safeParse()`:**

   - `.safeParse()` is a method provided by Zod to validate data against a schema.
   - It returns an object with a `.success` property indicating whether the validation was successful.

3. **JWT Operations:**
   - In `signJwt`, it checks if both the `username` and `password` pass validation before generating a JWT.
   - In `verifyJwt`, it attempts to verify the JWT using `jwt.verify`. If successful, it returns `true`; otherwise, it returns `false`.
   - In `decodeJwt`, it decodes the JWT without verification and returns the decoded payload or `false` if decoding fails.

Overall, the `.success` property is used to check whether the Zod schema validation succeeded for `username` and `password`. If it fails, the functions return `null` or `false` accordingly.

### Assignment stuff

- what is the best way to create a new course id in JS, lets say by generating a random number or string. tell me what is the best way for a beginner like me

For generating a new course ID in JavaScript, you can use a combination of the `Math.random()` function and some string manipulation to create a unique identifier. Here's a simple example:

```javascript
function generateCourseId() {
  // Generate a random number and convert it to a string
  const randomNumber = Math.floor(Math.random() * 10000).toString();

  // Add a prefix to ensure uniqueness or use other strategies if needed
  const courseId = `COURSE_${randomNumber}`;

  return courseId;
}

// Example usage:
const newCourseId = generateCourseId();
console.log(newCourseId);
```

Explanation:

1. **`Math.random()`:** Generates a random floating-point number between 0 (inclusive) and 1 (exclusive).

2. **`Math.floor()`:** Rounds the random number down to the nearest whole number.

3. **`toString()`:** Converts the random number to a string.

4. **Prefix and String Concatenation:** You can add a prefix to the generated number to create a unique course ID. In the example, the prefix is `"COURSE_"`.

This method is simple and works well for generating unique identifiers. However, keep in mind that for certain applications, especially those requiring high security or uniqueness guarantees, more sophisticated approaches might be necessary. For example, using a dedicated ID generation library or relying on a database's auto-incremented ID field.
