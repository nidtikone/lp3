import java.util.Scanner;

public class Fibonacci {

    // Iterative approach to calculate Fibonacci number
    public static int fibonacciIterative(int n) {
        if (n <= 1) return n;
        
        int prev = 0, curr = 1;
        for (int i = 2; i <= n; i++) {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        
        return curr;
    }

    // Recursive approach to calculate Fibonacci number
    public static int fibonacciRecursive(int n) {
        if (n <= 1) return n;
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of terms for the Fibonacci series: ");
        int n = scanner.nextInt();

        // Iterative Approach
        System.out.println("\nIterative Fibonacci Series:");
        Runtime runtime = Runtime.getRuntime();
        runtime.gc(); // Hint JVM to run garbage collection
        long startMemory = runtime.totalMemory() - runtime.freeMemory();
        long startTime = System.nanoTime();
        
        for (int i = 0; i < n; i++) {
            System.out.print(fibonacciIterative(i) + " ");
        }
        
        long endTime = System.nanoTime();
        long endMemory = runtime.totalMemory() - runtime.freeMemory();
        long iterativeTime = endTime - startTime;
        long iterativeMemory = endMemory - startMemory;

        System.out.println("\nIterative Time Taken (nanoseconds): " + iterativeTime);
        System.out.println("Iterative Memory Used (bytes): " + iterativeMemory);

        // Recursive Approach
        System.out.println("\nRecursive Fibonacci Series:");
        runtime.gc(); // Hint JVM to run garbage collection
        startMemory = runtime.totalMemory() - runtime.freeMemory();
        startTime = System.nanoTime();
        
        for (int i = 0; i < n; i++) {
            System.out.print(fibonacciRecursive(i) + " ");
        }
        
        endTime = System.nanoTime();
        endMemory = runtime.totalMemory() - runtime.freeMemory();
        long recursiveTime = endTime - startTime;
        long recursiveMemory = endMemory - startMemory;

        System.out.println("\nRecursive Time Taken (nanoseconds): " + recursiveTime);
        System.out.println("Recursive Memory Used (bytes): " + recursiveMemory);

        scanner.close();
    }
}
