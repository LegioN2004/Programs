nums = [1,2,3,4,5]
print(nums[1], nums[0], nums[0:3])

names = ['hello', 'world', 'python']

values = [1,2,3,4,5]

mixedValues = [1,2.1, 'hello', 'w']

print(names[0], values[0], mixedValues[0])
print(names, values, mixedValues)

listOfList = [names , values , mixedValues , [1, 4, 7]]

print(listOfList)

# since lists are mutable we can do this

values.append(200) # adds 200 to the end of the list
values.insert(2, "hello") # adds 200 to the 2nd index
print(values)
values.remove(200) # removes 200 from the list, give the name or value directly. If the same thing exits multiple times, it will remove the first occurance of it
values.pop(2) # to remove the element from a given index, removes the 2nd index
print(values)
