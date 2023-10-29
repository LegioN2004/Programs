package Arrays.Easy;

public class qno4 {
  public static void main(String[] args) {
    int[][] a = { { 1, 3 }, { 7, 3 }, { 6, 6 } };
    int max = 0;
    for (int m = 0; m < a.length; m++) {
        int b = 0;
        for (int n = 0; n < a[m].length; n++) {
        b = b + a[m][n];
          if(b > max) {
              max = b;
          }
      }
    }
      System.out.println(max);
  }
}


// max = b;
// if (b > max) {
// c = max;
// } else {
// c = b;
// }
