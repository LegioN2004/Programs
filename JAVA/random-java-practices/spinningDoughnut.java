public class spinningDoughnut {
    public static void main(String[] args) {
        int width = 75;
        int height = 25;
        double a = 0, b = 0;
        char[] chars = {' ', '.', ':', ';', 'o', 'e', '!', '*', 'x', '%', '#', '@'};
        char[][] output = new char[height][width];

        while (true) {
            double sinA = Math.sin(a);
            double cosA = Math.cos(a);
            double sinB = Math.sin(b);
            double cosB = Math.cos(b);

            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    double z = 1.5 - (j * (3.0 / width));
                    double x = z * sinA;
                    double y = z * cosA;
                    double c = x * sinB + y * cosB;
                    int index = (int) ((c * 9 / 8) + 9);
                    output[i][j] = chars[index];
                }
            }

            for (int i = 0; i < height; i++) {
                System.out.println(output[i]);
            }

            a += 0.07;
            b += 0.03;
        }
    }
}

