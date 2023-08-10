// Approach 1 : BruteForce --> Checking every number to find Largest Prime Factor
// TC : O(N*sqrt(N))  SC : O(1)
#include <iostream>

// Function to check if a number is prime
bool isPrime(int num) {
    int count = 0;
    // Loop to check divisibility up to the square root of the number
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            count++;
        }
    }
    // If count is 1, the number is prime; otherwise, it's not
    if (count == 1) return true;
    return false;
}

// Function to find the largest prime factor of a number
long long int largestPrimeFactor(int N) {
    long long int largestPrime = 0;
    // Loop to iterate through numbers from 2 to N
    for (int i = 2; i <= N; i++) {
        // Check if 'i' is a factor of 'N' and also prime
        if (N % i == 0 && isPrime(i)) {
            // Update the largest prime factor
            largestPrime = i;
        }
    }
    return largestPrime;
}

int main() {
    int number;

    // Sample input 1
    number = 56;
    std::cout << "For input " << number << ":\n";
    long long int result1 = largestPrimeFactor(number);
    std::cout << "The largest prime factor of " << number << " is: " << result1 << std::endl;

    // Sample input 2
    number = 13195;
    std::cout << "For input " << number << ":\n";
    long long int result2 = largestPrimeFactor(number);
    std::cout << "The largest prime factor of " << number << " is: " << result2 << std::endl;

    return 0;
}

