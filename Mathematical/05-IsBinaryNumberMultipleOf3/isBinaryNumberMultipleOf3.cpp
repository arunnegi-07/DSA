// Approach 1 : BruteForce --> Just coverting Binary to decimal and then checking if it is divisible by 3
// TC : O(|S|) SC :  O(1)

// Note : This Approach is fail for large test cases because none of the int, long long and double is able to hold the value
//            after it is converted to decimal as it is too big.

#include <iostream>
using namespace std;

// Function to check if a binary number is divisible by 3
int isDivisible(string s) {
    int decimal = 0;
    int power = 0;
    
    // Convert binary number to decimal
    for (int i = s.length() - 1; i >= 0; i--) {
        int bit = s[i] - '0'; // Convert char to integer
        decimal += bit * (1 << power); // Add weighted bit to the decimal value
        power++;
    }
    
    return (decimal % 3 == 0); // Check if decimal is divisible by 3
}

int main() {
    // Sample inputs
    string binary1 = "110";
    string binary2 = "1010";
    
    // Check if the binary numbers are divisible by 3
    bool result1 = isDivisible(binary1);
    bool result2 = isDivisible(binary2);
    
    // Output the results
    cout << binary1 << " is divisible by 3: " << result1 << endl;
    cout << binary2 << " is divisible by 3: " << result2 << endl;
    
    return 0;
}
