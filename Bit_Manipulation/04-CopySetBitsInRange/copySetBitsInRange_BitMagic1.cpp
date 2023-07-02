// Approach 2 : Using concept of Bit Manipulation (Right Shift and Bitwise AND)
// You can say it like BruteForce way using BitManipulation.

// TC : O(r-l)  SC : O(1)

// Note : refer 'Intution1' file attached to get clear understanding of each step involved in this appraoch.
#include <iostream>
#include <cmath>

int setSetBit(int x, int y, int l, int r) {
    int sum = 0;
    int temp = x;
    
    temp >>= l - 1; // Right shift 'temp' to align the range [l, r] with the least significant bits
    y >>= l - 1;    // Right shift 'y' to align with the least significant bits
    int pos = l - 1; // Position tracker for setting bits
    
    for (int i = l;i <= r; i++) {
        if ( !(temp & 1) && (y & 1)) {
            sum += pow(2, pos); // If the current bit in 'temp' is 0 and the corresponding bit in 'y' is 1, set the bit in 'sum'
        }
        y >>= 1;    // Right shift 'y' by 1 to process the next bit
        temp >>= 1; // Right shift 'temp' by 1 to process the next bit
        pos++;      // Increment the position tracker
    }
    
    return x + sum; // Return the modified value of 'x'
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
