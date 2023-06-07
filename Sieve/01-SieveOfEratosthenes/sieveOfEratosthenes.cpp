// TC : O(n*log(logn))  SC : O(n)
// Note : if we used Brute Force way to do same job then Time Complexity would have been O(n*n), so using
//        Sieve of Eratosthenes algorithm is much more effiecient.

#include <iostream>
#include <vector>

std::vector<int> sieveOfEratosthenes(int n) {
    // Create a boolean array "prime[0..n]" and initialize
    // all entries as true. A value in prime[i] will be
    // false if i is not a prime, and true otherwise.
    std::vector<bool> prime(n + 1, true); 
    prime[0] = prime[1] = false; // 0 and 1 are not prime numbers

    std::vector<int> primes; // Vector to store prime numbers

    for (int p = 2; p <= n; ++p) { // Iterate from 2 to n
        if (prime[p]) { // If p is prime
            primes.push_back(p); // Add p to the primes vector

            // Update all multiples of p as non-prime
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    return primes; // Return the vector of prime numbers
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    std::vector<int> primes = sieveOfEratosthenes(n); // Find prime numbers up to n

    std::cout << "Prime numbers in the range 1 to " << n << " are: ";
    for (int prime : primes) { // Print the prime numbers
        std::cout << prime << " ";~
    }
    std::cout << std::endl;

    return 0;
}
