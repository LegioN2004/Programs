import pandas as pd

# this is a list but we'll convert this to series so that we can access some extra functionalities over lists, over being the same 1d array as lists.
# data = [1, 2, 3, 4, 5]
# index = ['a', 'b', 'c', 'd', 'e']
#
# series = pd.Series(data, index = index)
# print(series)


data = pd.read_csv("sanitary_product_dataset.csv")
print(data)
print(data.head())

print("column names")
print(data.columns)

print("no of rows and columns")
print(data.shape)

print("view specific columns")
print(data['Product_Recommended'].head())

print("view a range of columns from 10 to 15")
print(data.iloc[10:16])
