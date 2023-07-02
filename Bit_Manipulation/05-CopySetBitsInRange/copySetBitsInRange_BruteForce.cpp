// Approach 1 : BruteForce --> Converting given numbers to binary and setting bits of 'X' w.r.t 'Y' and then converting it back to decimal.
// TC : O(32)  SC : O(32) 

#include <iostream>
#include <vector>
using namespace std;

// Function to convert a binary representation to an integer
int binaryToDecimal(const vector<int>& n) {
    int power = 1;
    int num = 0;
    for (int i = 31; i >= 0; i--) {
        num = num + n[i] * power;
        power *= 2;
    }
    return num;
}

// Function to convert an integer to its binary representation
vector<int> decimalTobinary(int n) {
    std::vector<int> binary(32, 0);
    int i = 31;
    while (n != 0) {
        int rem = n % 2;
        binary[i] = rem;
        i--;
        n = n / 2;
    }
    return binary;
}

// Function to copy set bits from 'y' to 'x' within the given range
int setSetBit(int x, int y, int l, int r) {
    // Get binary representations of x and y
    vector<int> binary_x = decimalTobinary(x);
    vector<int> binary_y = decimalTobinary(y);

    // Calculate the start and end positions within the binary representation
    int start = 32 - r;
    int end = 32 - l;

    // Copy set bits from 'y' to 'x' within the given range
    for (int i = start; i <= end; i++) {
        if (binary_y[i] == 1) {
            binary_x[i] = binary_y[i];
        }
    }

    // Convert the modified binary representation back to an integer
    return binaryToDecimal(binary_x);
}

int main() {
    // Example 1:
    int x1 = 44, y1 = 3, l1 = 1, r1 = 5;
    int result1 = setSetBit(x1, y1, l1, r1);
    std::cout << "Output 1: " << result1 << std::endl; // Output: 47

    // Example 2:
    int x2 = 16, y2 = 2, l2 = 1, r2 = 3;
    int result2 = setSetBit(x2, y2, l2, r2);
    std::cout << "Output 2: " << result2 << std::endl; // Output: 18

    return 0;
}
