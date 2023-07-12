// Approach 3 : Using Binary Exponentiation
// TC : O(logR)  SC : O(1)

#include <iostream>
#define mod (int)(1e9 + 7)

// Function to calculate the power of a number using bitwise operations
long long power(int N, int R) {
    long long ans = 1LL;
    
    while (R) {
        // If the least significant bit of R is 1 (i.e., R is odd),
        // multiply ans by N and take the modulo mod
        if (R & 1)
            ans = (ans * 1LL * N) % mod;
        
        // Square N and take the modulo mod to prepare for the next iteration
        N = (N * 1LL * N) % mod;
        
        // Right-shift R by 1 to divide it by 2
        R >>= 1;
    }
    
    return ans;
}

int main() {
    // Sample input 1
    int N1 = 2; // Number
    int R1 = 2; // Reverse of the number

    // Calculate power of N1 raised to R1
    int result1 = power(N1, R1);
    std::cout << "Result 1: " << result1 << std::endl;

    // Sample input 2
    int N2 = 12; // Number
    int R2 = 21; // Reverse of the number

    // Calculate power of N2 raised to R2
    int result2 = power(N2, R2);
    std::cout << "Result 2: " << result2 << std::endl;

    return 0;
}
