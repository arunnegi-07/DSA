// TC : O(NlogN)  SC : O(1)

// Note : Refer to "Intuition" file attached to understand this approach better.

#include <iostream>

bool isHappy(int n) {
    // Check if the number is 1 or 7, as they are the only happy numbers below 10
    if (n == 1 || n == 7) 
        return 1;
        
    int next, sum;
    next = sum = n;

    // Loop until the number becomes a single-digit number
    while (next > 9) {
        sum = 0;

        // Calculate the sum of squares of digits
        while (next > 0) {
            int digit = next % 10;
            next /= 10;
            sum += digit * digit;
        }

        // Check if the sum is 1 or 7 (happy numbers)
        // if number is single digit and other than 1 and 7 then loop will break and false will be returned 
        // which means current number is not a happy number.
        if (sum == 1 || sum == 7)
            return 1;

        next = sum;
    }

    // The number is not a happy number
    return 0;
}

int nextHappy(int n) {
    int nextNum = n + 1;

    // Loop until a happy number is found
    while (isHappy(nextNum) != 1)
        nextNum++;

    return nextNum;
}

int main() {
    // Sample inputs
    int N1 = 8;
    int N2 = 10;

    // Find the next happy numbers
    int nextHappy1 = nextHappy(N1);
    int nextHappy2 = nextHappy(N2);

    // Output the results
    std::cout << "Next happy number after " << N1 << ": " << nextHappy1 << std::endl;
    std::cout << "Next happy number after " << N2 << ": " << nextHappy2 << std::endl;

    return 0;
}
