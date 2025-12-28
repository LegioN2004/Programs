def MergeSort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left = arr[:mid]
        right = arr[mid:]

        MergeSort(left)
        MergeSort(right)

        i = 0
        j = 0
        k = 0

        while i < len(left) and j < len(right):
            if left[i] <= right[j]:
                arr[k] = left[i]
                i = i + 1
            else:
                arr[k] = right[j]
                j = j + 1
            k = k + 1

        while i < len(left):
            arr[k] = left[i]
            k = k + 1
            i = i + 1
        while j < len(right):
            arr[k] = right[j]
            k = k + 1
            j = j + 1



arr = [5, 3, 10, 9, 1, 12, 8]
MergeSort(arr)
print(arr)
