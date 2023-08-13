// Approach 3 : Dynamic Programming --> Tabulation Method
// TC : O(N)  SC : O(N)  -->  Extra Space

#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

// Function to calculate the Nth Fibonacci number modulo MOD using tabulation
int nthFibonacci(int n) {
    // Base cases: If n is 0 or 1, return n
    if (n < 2)
        return n;
    
    // Create a vector to store Fibonacci numbers modulo MOD
    std::vector<int> dp(n + 1, 0);
    
    // Initialize the first two Fibonacci numbers
    dp[1] = 1;
    
    // Loop to calculate Fibonacci numbers from 2 to n
    for (int i = 2; i <= n; ++i) {
        // Calculate the current Fibonacci number by summing the (i-2)th and (i-1)th Fibonacci numbers
        // Apply modulo operation to each term to prevent overflow and keep the result within the specified range
        dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
    }
    
    // Return the Nth Fibonacci number
    return dp[n];
}

int main() {
    // Example input 1
    int input1 = 10;
    int result1 = nthFibonacci(input1);
    std::cout << "Fibonacci(" << input1 << ") modulo " << MOD << " = " << result1 << std::endl;

    // Example input 2
    int input2 = 20;
    int result2 = nthFibonacci(input2);
    std::cout << "Fibonacci(" << input2 << ") modulo " << MOD << " = " << result2 << std::endl;

    return 0;
}
