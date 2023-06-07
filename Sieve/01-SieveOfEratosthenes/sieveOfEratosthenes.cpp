// TC : O(n*log(logn))  SC : O(n)
// Note : if we used Brute Force way to do same job then Time Complexity would have been O(n*n), so using
//        Sieve of Eratosthenes algorithm is much more effiecient.

#include <iostream>
#include <vector>

void sieveOfEratosthenes(int n) {
    // Create a boolean array "prime[0..n]" and initialize
    // all entries as true. A value in prime[i] will be
    // false if i is not a prime, and true otherwise.
    std::vector<bool> prime(n + 1, true);

    // 0 and 1 are not prime numbers, so set them as false
    prime[0] = prime[1] = false;

    // Iterate from 2 to sqrt(n) (inclusive) as any non-prime
    // number <= sqrt(n) must have a prime factor greater than sqrt(n)
    for (int p = 2; p * p <= n; ++p) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p]) {
            // Update all multiples of p as non-prime
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    // Print all prime numbers
    std::cout << "Prime numbers in the range 1 to " << n << " are: ";
    for (int p = 2; p <= n; ++p) {
        if (prime[p]) {
            std::cout << p << " ";
        }
    }
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    sieveOfEratosthenes(n);

    return 0;
}
