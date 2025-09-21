public class mergeSortProblems {

    public static void mergeSort(int[] arr, int l, int r) {
        if (l < r){
            int mid = (l + r) / 2;
            // first half
            mergeSort(arr, l, mid);
            // second half
            mergeSort(arr, mid+1, r);

            merge(arr, l, mid, r);
        }
    }

    // we'll need two arrays to combine and form it into one, and it'll happen for more than once to form the final original sorted array
    private static void merge(int[] arr, int l, int mid, int r) {
        // simply finding the length of the two arrays
        int n1 = mid - l + 1; // because it starts with l and ends with mid but also has 0 so the +1 there
        int n2 =  r - mid;


        // left array and right array for combining into one
        int larr[] = new int[n1];
        int rarr[] = new int[n2];

        for (int i = 0; i < n1; i++) {
            larr[i] = arr[l + i]; // 0(first value) + i
        }

        for (int i = 0; i < n2; i++) {
            rarr[i] = arr[mid + 1 + i]; // 2(mid) + 1(of the next array) + i
        }

        int i = 0, j = 0, k = l; // i, j are for pointers to the array values and k is the counter of the main array

        while (i < n1 && j < n2){ // [5, 8, 9] & [1, 6, 7] | comparing 5 to 1 and then
            if(larr[i] < rarr[j]){
                arr[k] = larr[i]; // comparing here and
                i++; // updating the pointer to point to the next value since now the first values of the both the splitted arrays are done
            }
            else {
                arr[k] = rarr[j];
                j++; //
            }
            k++; // moving the main array pointer
        }

        while(i<n1){
            arr[k] = larr[i];
            i++;
            k++;
        }
        while(j<n2){
            arr[k] = rarr[j];
            j++;
            k++;
        }
    }

    public static void main(String[] args) {
        int arr[] = {3, 8, 5, 91, 111, 42, 51, 9, 6, 2, 200};

        for (int n: arr){
            System.out.print(n + " ");
        }

        mergeSort(arr, 0, arr.length-1);

        System.out.println();

        System.out.println("After sorting");
        for (int n: arr){
            System.out.print(n + " ");
        }
    }
}
