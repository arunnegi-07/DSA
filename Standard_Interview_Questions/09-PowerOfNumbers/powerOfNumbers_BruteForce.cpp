// Approach 1 : BruteForce 
// TC : O(R)  SC : O(1)
// Note : This approach will lead to overflow and will give TLE for larger inputs.

#include <iostream>
const int MOD = 1000000007;

// Function to calculate the power of a number (brute-force approach)
int pow(int N, int R) {
    long long result = 1;

    for (int i = 0; i < R; i++) {
        result = (result * N) % MOD;
    }

    return result;
}

int main() {
    // Sample input 1
    int N1 = 2; // Number
    int R1 = 2; // Reverse of the number

    // Calculate power of N1 raised to R1
    int result1 = pow(N1, R1);
    std::cout << "Result 1: " << result1 << std::endl;

    // Sample input 2
    int N2 = 12; // Number
    int R2 = 21; // Reverse of the number

    // Calculate power of N2 raised to R2
    int result2 = pow(N2, R2);
    std::cout << "Result 2: " << result2 << std::endl;

    return 0;
}
