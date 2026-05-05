package Arrays.Easy;

public class qno13 {
    public static void main(String[] args) {
        // Prepare the input as a List of Lists
        int[][] image = new int[3][3];
        image[0][0] = 1;
        image[0][1] = 1;
        image[0][2] = 0;
        image[1][0] = 1;
        image[1][1] = 0;
        image[1][2] = 1;
        image[2][0] = 0;
        image[2][1] = 0;
        image[2][2] = 0;

        System.out.println(flipAndInvertImage(image));
        // int[][] answer = flipAndInvertImage(image);

        for (int i = 0; i < image.length; i++) {
            for (int j = 0; j < image[i].length; j++) {
                System.out.println(answer[i][j]);
            }
        }
    }

    static int[][] flipAndInvertImage(int[][] image) {
        int n = image.length;
        int[][] ans = new int[n][n];
        int last = image[0].length - 1;
        int first = 0;
        for (int i = 0; i < image.length; i++) {
            for (int j = 0; j < image[0].length; j++) {
                int index = 0;
                ans[i][j] = ans[i][j];
            }
        }
        // for (int i = 0; i < image.length; i++) {
        //     for (int j = i; j < image[i].length; j++) {
        //         if(ans[i][j] == 1)
        //             ans[i][j] = 0;
        //         else if(ans[i][j] == 0)
        //             ans[i][j] = 1;
        //     }
        // }
        return ans;
    }

}
