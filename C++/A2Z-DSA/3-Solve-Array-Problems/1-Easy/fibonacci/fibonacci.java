public class fibonacci {

    private static long[] fibonacciCache;
    public static void main(String[] args) {
        int n = 10;

        // we need create an extra element n + 1 to calculate till n so that's why
        fibonacciCache = new long[n + 1];

        for (int i = 0; i <= n; i++)
            System.out.print(fibonacci(i) + " ");
    }

    public static long fibonacci(int n) {
        if (n <= 1) return n;

        if (fibonacciCache[n] != 0) return fibonacciCache[n];

        long nthfib = fibonacci(n - 1) + fibonacci(n - 2);

        fibonacciCache[n] = nthfib;

        return  nthfib;
    }
}
