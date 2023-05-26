// Recursive Approach

#include <iostream>
#include <vector>
#include <cmath>

const int MOD = 1000000007;

int countWays(int n, int x, int currentNum) {
    // Base cases
    if (n == 0) {
        return 1;  // Found a valid combination
    }
    if (n < 0 || currentNum <= 0) {
        return 0;  // Invalid combination
    }

    // Recursively count the ways by considering or excluding the current number
    int includeCurrent = countWays(n - pow(currentNum, x), x, currentNum - 1);  // decreasing 'n' if included
    int excludeCurrent = countWays(n, x, currentNum - 1);  // 'n' remains the same if excluded

    // Return the total number of ways modulo MOD
    return (includeCurrent + excludeCurrent) % MOD; 
}

int numOfWays(int n, int x) {
    return countWays(n, x, int(pow(n, 1.0 / x)));  // Start with the largest possible number

    /* Note: in 3rd parameter we have passed we are calculating largest number possible which 
                 will contribute to the sum.
        
           For Ex:
                
                1. n = 10 x = 2
                         pow(10, 1.0/2) -->  which is nothing but x-th root of 'n'
                                             this will give us largest number possible
                                             so that we can start from there and go till where our 
                                             condition satisfies.
                
                    here we got, '3'  and which is right 10 = 1^2 + 3^2
                    
                2.  n = 100 x = 2
                         pow(100, 1.0/2) --> '10'  
                          
                           and one of the possibility is : 100 = 10^2                     */
                
}

int main() {
    int n1 = 10;
    int x1 = 2;
    int result1 = numOfWays(n1, x1);
    std::cout << "Number of ways to express " << n1 << " as the sum of x-th powers: " << result1 << std::endl;
    
    int n2 = 100;
    int x2 = 2;
    int result2 = numOfWays(n2, x2);
    std::cout << "Number of ways to express " << n2 << " as the sum of x-th powers: " << result2 << std::endl;
    
    return 0;
}
