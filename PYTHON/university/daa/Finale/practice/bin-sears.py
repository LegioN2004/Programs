def binary_search(arr, low, high, key):
    if low > high:
        return -1

    mid = (low + high) // 2

    if arr[mid] == key:
        return mid
    elif key < arr[mid]:
        binary_search(arr, low, mid - 1, key)
    else:
        binary_search(arr, mid + 1, high, key)


arr = [1,2,3,4,5]
key = 2

result = binary_search(arr, 0, len(arr) - 1, key)

if result != -1:
    print("element found at ", result + 1, "position")
else:
    print("element not found")

