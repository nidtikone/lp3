#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

// Iterative approach to calculate Fibonacci number
int fibonacciIterative(int n) {
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
int fibonacciRecursive(int n) {
    if (n <= 1) return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main() {
    int n;
    cout << "Enter the number of terms for the Fibonacci series: ";
    cin >> n;

    // Iterative Approach
    cout << "\nIterative Fibonacci Series:\n";
    auto startTime = chrono::high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        cout << fibonacciIterative(i) << " ";
    }

    auto endTime = chrono::high_resolution_clock::now();
    auto iterativeTime = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count();

    cout << "\nIterative Time Taken (nanoseconds): " << iterativeTime << endl;

    // Recursive Approach
    cout << "\nRecursive Fibonacci Series:\n";
    startTime = chrono::high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        cout << fibonacciRecursive(i) << " ";
    }

    endTime = chrono::high_resolution_clock::now();
    auto recursiveTime = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count();

    cout << "\nRecursive Time Taken (nanoseconds): " << recursiveTime << endl;

    return 0;
}
