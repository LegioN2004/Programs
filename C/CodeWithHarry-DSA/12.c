// binary search

#include <stdio.h>

int linearSearch(int arr[], int size, int element)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == element)
    {
      return i;
    }
  }
  return -1;
}

// int bubbleSortArray(int *arr[], int size){
//   for (int i = 0; i < size - 1; i++) // for no of passes, it'll run for n-1 times
//   {
//     for (int j = 0; j < size - i - 1; j++)
//     {
//       /* code */
//     }
    
//   }
  

// }



// array must be sorted, DIY
int binarySearch(int arr[], int size, int element)
{
  int low = 0, mid, high = size - 1; // low will be the first elememt and high will be the last element.
  // keep searching until low <= high

  // will work till it finds the element or else it'll return -1
  while (low <= high)
  {
    mid = (low + high) / 2;
    if (arr[mid] == element)
    {
      return mid;
    }
    else if (element > arr[mid])
    {
      low = mid + 1; // why + 1, because the element we are looking for is not present in the mid index, so we can skip and start after this part
    }
    else if (element < arr[mid])
    {
      high = mid - 1; // why - 1, because the element we are looking for is not present in the mid index, so we can skip and start before this part.
    } else {
      printf("element not found");
      return -1;
    }
  }
  return -1;
}

int main()
{
  int n = 0, element = 0;
  printf("Enter the size of the array: ");
  scanf("%d", &n);
  int arr[n];

  printf("Enter the elements of the array: \n");
  for (int i = 0; i < n; i++)
  {
    printf("\nelement(%d): ", i);
    scanf("%d", &arr[i]);
  }

  printf("Enter the element you want to find from the array: ");
  scanf("%d", &element);
  // int index = linearSearch(arr, n, element);
  // run the sorting code before doing the binary search okay
  // bubbleSortArray(arr, n);
  int index = binarySearch(arr, n, element);
  if (index)
  {
    printf("Element %d found at index %d", element, index);
  }
  else
  {
    printf("Element not found");
  }

  return 0;
}