// Approach 1 : Recursive Method 
// TC : O(2^N)  SC : O(N)

#include <iostream>
using namespace std;

// Define a constant for the modulo value
const int MOD = 1e9 +7;

// Recursive function to calculate the Nth Fibonacci number
int f(int n) {
    // Base case: If n is less than 2, return n
    if (n < 2) 
        return n;
    
    // Recursive step: Calculate the Nth Fibonacci number by summing the (N-2)th and (N-1)th Fibonacci numbers
    // Apply modulo operation to avoid overflow and keep the result within the specified range
    return (f(n - 2) % MOD + f(n - 1) % MOD) % MOD;
}

// Function to calculate the Nth Fibonacci number modulo MOD
int nthFibonacci(int n) {
    // Call the recursive function to calculate the Nth Fibonacci number
    // Apply modulo operation to the final result to keep it within the specified range
    return f(n) % MOD;
}

int main() {
    // Example input 1
    int input1 = 6;
    int result1 = nthFibonacci(input1);
    cout << "Fibonacci(" << input1 << ") modulo " << " = " << result1 << std::endl;

    // Example input 2
    int input2 = 20;
    int result2 = nthFibonacci(input2);
    cout << "Fibonacci(" << input2 << ") modulo " << " = " << result2 << std::endl;

    return 0;
}