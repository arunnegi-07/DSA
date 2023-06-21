// Approach : Mathematical
//  TC : O(1)  SC : O(1)

#include <iostream>

int sumOfNaturals(int n) {
    // Declare variables
    long long num = n; // Store the value of n as a long long to prevent overflow
    long long MOD = 1e9 + 7; // Define the modulus value
    
    // Calculate the sum of the first n natural numbers and take the remainder modulo MOD
    return (num * (num + 1) / 2) % MOD; 
}

int main() {
    // Sample inputs
    int n1 = 6;
    int n2 = 4;
    
    // Calculate and print the sum of natural numbers for each sample input
    std::cout << "Sum of natural numbers for n1: " << sumOfNaturals(n1) << std::endl;
    std::cout << "Sum of natural numbers for n2: " << sumOfNaturals(n2) << std::endl;
    
    return 0;
}
