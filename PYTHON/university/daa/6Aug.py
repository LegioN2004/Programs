# ---
# jupyter:
#   jupytext:
#     text_representation:
#       extension: .py
#       format_name: percent
#       format_version: '1.3'
#       jupytext_version: 1.17.3
#   kernelspec:
#     display_name: .venv
#     language: python
#     name: python3
# ---

# %% [markdown]
#
# ```py
# # addition
# num1 = int(input("Enter a number: "))
# num2 = int(input("Enter second number: "))
#
# print("sum is ", num1 + num2)
# print("division is", num1 / num2)
# print("subtraction is", num1 - num2)
# print("multiplication is ", num1 * num2)
#
# max(num1, num2)
# min(num1, num2)
# ```
#
#
# # algorithm
#
# Algorithm: Basic_Calculator(num1, num2)
#     where num1, num2 are two numbers
# 1. Start
# 2. Read num1 and num2
# 3. Write num1 + num2
# 4. Write num1 - num2
# 5. Write num1 * num2
# 6. Write num1 / num2
# 7. If num1 > num2, then
#        Max = num1
#    Else
#        Max = num2
# 8. If num1 < num2, then
#        Min = num1
#    Else
#        Min = num2
# 9. Print Max
# 10. Print Min
# 11. End

# %%
# addition
num1 = int(input("Enter a number: "))
num2 = int(input("Enter second number: "))

print("sum is ", num1 + num2)

print("division is", num1 / num2)

print("subtracson is", num1 - num2)

print("multiplicason is ", num1 * num2)

max(num1, num2)
min(num1, num2)

# %%
num = 5
fact = 1

for i in range(1, num+1):
    fact *= i

print(fact)

# %% [markdown]
# # sum of square of N natural numbers

# %%
n = 5
sum = 0
for i in range(1, n + 1):
    sum += i * i

print(sum)

# %%
array = [1, 2, 3, 4, 5]
max_num = max(array)
print("Maximum number in the array is", max_num)

# %%
# check where a character is present in the string or not

string = input("Enter a string: ")
char = input("Enter the character to find: ")

if char in string:
    print(f"'{char}' is present in the string.")
else:
    print(f"'{char}' is not present in the string.")

# %%
arr = [1, 9, 3, 4, 5]

max_val = arr[0]

for i in arr:
    if i > max_val:
        max_val = i
print("max value is: ", max_val)

# %%
num = [11, 12, 13, 14, 15]

for i in num:
    if((i % 2) == 0):
        print(i, "is even number")




# %% [markdown]
# # strings

# %%
print('hello')
print(r'C:\hello\hi')

print( """
Usage: Mili [OPTIONS]
      -c code
      -H helpppppppp
      -t tur mur tu
""")

print("helo " * 4)

# %%
count = int(input("how much he cares for her"))

print("He cares her this much")
for i in range(1, count+1):
    print("care" * i)


