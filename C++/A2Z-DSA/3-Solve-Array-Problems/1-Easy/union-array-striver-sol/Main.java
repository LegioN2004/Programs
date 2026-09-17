import java.util.ArrayList;
import java.util.List;
import java.util.TreeMap;

// Define the Solution class
 class Solution {
    // Function to find union of two arrays
    public List<Integer> FindUnion(int[] arr1, int[] arr2, int n, int m) {
        // Create TreeMap to store elements in sorted order
        TreeMap<Integer, Integer> freq = new TreeMap<>();
        // Loop through first array and store frequency
        for (int i = 0; i < n; i++)
            freq.put(arr1[i], freq.getOrDefault(arr1[i], 0) + 1);
        // Loop through second array and store frequency
        for (int i = 0; i < m; i++)
            freq.put(arr2[i], freq.getOrDefault(arr2[i], 0) + 1);
        // Create a list to store union result
        List<Integer> Union = new ArrayList<>();
        // Traverse map keys and add to union list
        for (int key : freq.keySet())
            Union.add(key);
        // Return the union list
        return Union;
    }
}

// Driver class
public class Main {
    public static void main(String[] args) {
        // Define size of first array
        int n = 10;
        // Define size of second array
        int m = 7;
        // Initialize first array
        int[] arr1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        // Initialize second array
        int[] arr2 = { 2, 3, 4, 4, 5, 11, 12 };
        // Create object of Solution class
        Solution obj = new Solution();
        // Call FindUnion method
        List<Integer> Union = obj.FindUnion(arr1, arr2, n, m);
        // Print output message
        System.out.println("Union of arr1 and arr2 is ");
        // Print all elements of union
        for (int val : Union)
            System.out.print(val + " ");
    }
}
