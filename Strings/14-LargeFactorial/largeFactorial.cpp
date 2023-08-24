// TC : O(A*digits)  SC : O(digits)  --> Taking space to return the result

#include <bits/stdc++.h>
using namespace std;

string LargeFactorial(int A) {
    // Step 1: Initialize the factorial string with "1".
    string factorial = "1";
    
    // Step 2: Iterate from 2 to A to calculate the factorial.
    for (int x = 2; x <= A; x++) {
        int carry = 0;
        string temp = "";

        // Step 3: Multiply each digit in the current factorial with x.
        for (int i = 0; i < factorial.size(); i++) {
            int val = (factorial[i] - '0') * x + carry;
            temp += to_string(val % 10);  // Store the ones digit of the product.
            carry = val / 10;            // Carry over the tens digit.
        }
        
        // Step 4: Add any remaining carry to the result.
        while (carry != 0) {
            temp += to_string(carry % 10);  // Store the remaining carry as a digit.
            carry /= 10;
        }
        
        // Step 5: Update the factorial string with the new result.
        factorial = temp;
    }
    
    // Step 6: Reverse the factorial string to get the correct result.
    reverse(factorial.begin(), factorial.end());
    
    // Step 7: Return the final factorial as a string.
    return factorial;
}

int main() {
    int N = 5;
    string result = LargeFactorial(N);
    
    cout << "Factorial of " << N << " is:" << result; // Output: 120
    cout << endl;
    
    N = 22;
    result = LargeFactorial(N);
    
    cout << "Factorial of " << N << " is:" << result; // Output: 1124000727777607680000
    cout << endl;
    
    return 0;
}
