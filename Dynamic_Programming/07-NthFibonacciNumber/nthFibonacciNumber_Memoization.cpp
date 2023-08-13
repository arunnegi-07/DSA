// Approach 2 : Dynamic Programming --> Memoization
// TC : O(N)  SC : O(N) + O(N)  --> Stack Space + Extra Space

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Recursive function to calculate the Nth Fibonacci number
int f(int n, std::vector<int>& memo) {
    // Base case: If n is less than 2, return n
    if (n < 2)
        return n;

    // If the result for this value of n is already memoized, return it
    if (memo[n] != -1)
        return memo[n];

    // Recursive step: Calculate the Nth Fibonacci number by summing the (N-2)th and (N-1)th Fibonacci numbers
    // Apply modulo operation to each term to prevent overflow and keep the result within the specified range
    return memo[n] = (f(n - 2, memo) % MOD + f(n - 1, memo) % MOD) % MOD;
}

// Function to calculate the Nth Fibonacci number modulo MOD using memoization
int nthFibonacci(int n) {
    // Create a vector to store memoized values, initialized with -1
    vector<int> memo(n + 1, -1);

    // Call the recursive function to calculate the Nth Fibonacci number
    // Apply modulo operation to the final result to keep it within the specified range
    return f(n, memo) % MOD;
}

int main() {
    // Example input 1
    int input1 = 10;
    int result1 = nthFibonacci(input1);
    cout << "Fibonacci(" << input1 << ") modulo " << " = " << result1 << std::endl;

    // Example input 2
    int input2 = 20;
    int result2 = nthFibonacci(input2);
    cout << "Fibonacci(" << input2 << ") modulo " << " = " << result2 << std::endl;

    return 0;
}
