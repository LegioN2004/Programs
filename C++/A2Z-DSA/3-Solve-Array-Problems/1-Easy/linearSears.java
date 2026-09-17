public class linearSears {

    static int sol() {
        int arr[] = { 5, 4, 3, 2, 1 };
        int value_to_find = 5;
        int i = 0;
        for ( i = 0; i < arr.length; i++) {
            if (arr[i] == value_to_find) {
                break;
            }
        }
        return i;
    }

    public static void main(String[] args) {
        System.out.println(sol());
    }
}
