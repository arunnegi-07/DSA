// Approach 2 : Optimized Solution
// TC : O(sqrt(n))  SC : O(1)

#include <bits/stdc++.h>
using namespace std;

// Function to find the largest prime factor of a number
long long int largestPrimeFactor(int n) {
    long long int ans = INT_MIN; // Initialize the answer with a very small value
    
    // Loop through potential prime factors up to the square root of 'n'
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            // 'i' is a prime factor of 'n', update the answer
            ans = max(ans, (long long)i);
            n /= i; // Divide 'n' by 'i' to reduce it for the next iteration
        }
    }
    
    // If 'n' is greater than 1, it is itself a prime factor
    // Or if no prime factors were found, 'ans' will still be INT_MIN
    // In that case, the largest prime factor is 'n'
    return max((long long)n, ans);
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    
    // Find and display the largest prime factor of the given number
    long long int result = largestPrimeFactor(number);
    cout << "The largest prime factor of " << number << " is: " << result << endl;

    return 0;
}
