/* Approach 2 : Digit-by-Digit Multiplication and Accumulation" approach
    TC : O(N*N)  SC : O(digits in result)  --> Taking space to return the result

    Note : Refer to 'Intuition' file Attached to see the detailed explaination of this approach.
                                                                                                                                                                                                                                                                                                                            */

#include <bits/stdc++.h>
using namespace std;

vector<int> factorial(int N) {
    vector<int> res;        // Initialize the result vector to store the factorial digits
    res.push_back(1);       // Start with the factorial of 1
    
    for (int x = 2; x <= N; x++) {
        int carry = 0;      // Initialize carry for multiplication
        
        for (int i = 0; i < res.size(); i++) {
            int val = res[i] * x + carry;   // Multiply current digit with x and add carry
            res[i] = val % 10;              // Store the last digit in the result vector
            carry = val / 10;               // Update carry for next iteration
        }
        
        while (carry != 0) {
            res.push_back(carry % 10);      // Store remaining carry digits in the result
            carry /= 10;                    // Reduce carry
        }
    }
    
    reverse(res.begin(), res.end());       // Reverse the result vector to get correct order
    return res;                            // Return the vector containing factorial digits
}

int main() {
    int N = 5;
    vector<int> result = factorial(N);
    
    cout << "Factorial of " << N << " is: ";
    for (int digit : result) {
        cout << digit;  // Output: 120
    }
    cout << endl;
    
    N = 22;
    result = factorial(N);
    
    cout << "Factorial of " << N << " is: ";
    for (int digit : result) {
        cout << digit;  // Output: 1124000727777607680000
    }
    cout << endl;
    
    return 0;
}
