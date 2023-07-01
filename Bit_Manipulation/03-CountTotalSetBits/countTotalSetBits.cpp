// TC : O(log(n))  SC : O(1)

#include <iostream>
using namespace std;

// Function to count the number of set bits in a given integer
// Input: a long integer n
// Output: number of set bits in n
long countBits(long n) {
    if (n == 0)
        return 0;

    // Find the largest power of 2 that is less than or equal to n
    long x = larPowOf2(n);
    
    // Compute the total number of set bits in all numbers from 1 to (2^x - 1)
    // The formula for this is x * 2^(x-1)
    long y = x * (1 << (x - 1));
    
    // Find the number of set bits in the remaining numbers from (2^x) to n
    long z = n - (1 << x);
    
    // Recursively count the number of set bits in the remaining numbers from (2^x) to n
    return y + z + 1 + countBits(z);
}

// Function to find the largest power of 2 that is less than or equal to a given integer
// Input: a long integer n
// Output: the largest power of 2 that is less than or equal to n
long larPowOf2(long n) {
    long x = 0;
    while ((1 << x) <= n)
        x++;

    return x - 1;
}

// Sample usage of the countBits function
int main() {
    long n = 123456;
    cout << "Number of set bits in " << n << ": " << countBits(n) << endl;
    return 0;
}
