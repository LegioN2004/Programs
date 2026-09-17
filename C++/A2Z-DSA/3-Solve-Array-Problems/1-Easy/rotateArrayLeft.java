/**
 * rotateArrayLeft
 * TC: O(n)
 * SC: O(n) since we are modifying the array
 * What is the space used in the algo? O(n)
 * What is the extra space used? O(1)
 */
public class rotateArrayLeft {

    public static void main(String[] args) {
        int arr[] = { 1, 2, 3, 4, 5 };
        int temp = arr[0];

        for (int i = 1; i < arr.length; i++) {
            arr[i - 1] = arr[i];
        }
        arr[arr.length - 1] = temp;

        for (int i : arr) {
            System.out.println(i);
        }
    }
}