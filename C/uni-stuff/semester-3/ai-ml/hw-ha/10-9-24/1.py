# write a for loop till 100 and print the even numbers
for i in range(1, 101):
    if i % 3 == 0:
        if i % 5 == 0:
            print("FizzBuzz")
        else:
            print("Fizz")
    elif i % 5 == 0:
        if i % 3 == 0:
            print("FizzBuzz")
        else:
            print("Buzz")
    else:
        print(i)
