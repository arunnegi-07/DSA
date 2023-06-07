#include <iostream>
#include <vector>

// Helper Function to find the least prime factor for every number from 1 to N
void leastPrime(int num, std::vector<int> &primes, int n) {
    for (int j = num; j <= n; j += num) {
        // Checking this condition because we want the least prime factor
        // If the entry is already filled, then that is the least prime factor
        if (primes[j] == 0) {
            primes[j] = num;
        }
    }
}

// Function to find the least prime factor for each number from 1 to N
std::vector<int> leastPrimeFactor(int n) {
    std::vector<int> primes(n + 1, 0);
    primes[1] = 1; // For '0' and '1', the entry is filled at the starting only

    for (int i = 2; i <= n; ++i) {
        // Calling the helper function for each number from 1 to N
        leastPrime(i, primes, n);
    }

    // Finally, returning the answer
    return primes;
}

int main() {
    // Sample inputs
    int n1 = 10;
    int n2 = 20;

    // Find the least prime factors for the given inputs
    std::vector<int> leastFactors1 = leastPrimeFactor(n1);
    std::vector<int> leastFactors2 = leastPrimeFactor(n2);

    // Print the least prime factors for the first input
    std::cout << "Least prime factors for numbers 1 to " << n1 << " are: ";
    for (int i = 1; i <= n1; ++i) {
        std::cout << leastFactors1[i] << " ";
    }
    std::cout << std::endl;

    // Print the least prime factors for the second input
    std::cout << "Least prime factors for numbers 1 to " << n2 << " are: ";
    for (int i = 1; i <= n2; ++i) {
        std::cout << leastFactors2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
