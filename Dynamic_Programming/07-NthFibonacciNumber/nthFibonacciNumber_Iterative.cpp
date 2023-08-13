// Approach 4 : Iterative Approach --> Using Swapping of Variables
// TC : O(N)  SC : O(1)  

#include <iostream>

const int MOD = 1e9 + 7;

// Function to calculate the Nth Fibonacci number using an iterative approach
int nthFibonacci(int n) {
    // Base cases: If n is 0 or 1, return n
    if (n < 2)
        return n;
    
    // Initialize variables to store the first two Fibonacci numbers
    int a = 0, b = 1, c;
    
    // Loop to calculate Fibonacci numbers from 2 to n
    for (int i = 2; i <= n; ++i) {
        // Calculate the current Fibonacci number by summing the last two Fibonacci numbers
        // Apply modulo operation to each term to prevent overflow and keep the result within the specified range
        c = (a + b) % MOD;
        a = b;
        b = c;
    }
    
    // Return the Nth Fibonacci number
    return b;
}

int main() {
    // Example input 1
    int input1 = 10;
    int result1 = nthFibonacci(input1);
    std::cout << "Fibonacci(" << input1 << ") modulo " << " = " << result1 << std::endl;

    // Example input 2
    int input2 = 20;
    int result2 = nthFibonacci(input2);
    std::cout << "Fibonacci(" << input2 << ") modulo " << " = " << result2 << std::endl;

    return 0;
}
