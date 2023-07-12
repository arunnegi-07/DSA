// Approach 2 : Recursive Method
// TC : O(logN)  SC : O(logN)

#include <iostream>
const int MOD = 1000000007;

// Recursive function to calculate the power of a number
long long power(long long N, long long R){
    if (N == 0)
        return 1;

    if (R == 1)
        return N % MOD;

    long long res = power(N, R / 2) % MOD;
    res = (res * res) % MOD;

    if (R % 2 == 0)
        return res;
    else
        return (res * N) % MOD;
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
