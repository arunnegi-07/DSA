#include <bits/stdc++.h>
using namespace std;

// TC : O(1)  SC : O(1)

// This Function checks if valid string exists or not
int solve(int a, int b, int c) {
    int max_value = max(a, max(b, c));  // calculate the maximum value among the three
    int remCharacter;  // initialize variable to keep count of remaining characters
    
    // determine which integer is the maximum value and calculate remCharacter accordingly
    if (max_value == a) {
        remCharacter = b + c;
    } else if (max_value == b) {
        remCharacter = a + c;
    } else {
        remCharacter = a + b;
    }
    
    // check if the maximum value is odd or even and calculate the return value accordingly
    if (max_value % 2) {
        if (remCharacter >= max_value/2) {
            return a + b + c;
        } else {
            return -1;
        }
    } else {
        if (remCharacter+1 >= max_value/2) {
            return a + b + c;
        } else {
            return -1;
        }
    }
}

// Sample Inputs
// Input: a = 1, b = 2, c = 3; Output: 6
// Input: a = 4, b = 3, c = 1; Output: 8
// Input: a = 5, b = 5, c = 5; Output: 15
int main() {
    cout << solve(1, 2, 3) << endl;
    cout << solve(4, 3, 1) << endl;
    cout << solve(5, 5, 5) << endl;
    return 0;
}
