// Approach 1 : BruteForce --> Just coverting Binary to decimal and then checking if it is divisible by 3
// TC : O(|S|) SC :  O(1)

// Note : This Approach is fail for large test cases because none of the int, long long and double is able to hold the value
//            after it is converted to decimal as it is too big.

#include <iostream>
using namespace std;

// Function to check if a binary number is divisible by 3
int isDivisible(string s) {
    int sum = 0;    // to store the reduced sum of a given binary number to check if it is divisible by 3 or not
    int pos = 0;     // Just to keep track of position of power of 2 as we want to know when to add 1 or 2
    
    // traversing given string 
    for (int i = s.length()-1; i >= 0; i--) {
        // if position is odd we add '1' to sum (I have started 'pos' from '0' and assuming it as odd)
        if (pos % 2 == 0) {
            sum += s[i]*1;
        // if position is even we add '2' to sum
        } else {
            sum += s[i]*2;
        }
        // increasing position value
        pos++;
    }
    // finally if sum is divisble by '3' means given number was also divisble by 3
    return sum % 3 == 0 ? 1 : 0;
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
