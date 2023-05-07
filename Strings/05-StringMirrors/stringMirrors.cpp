// TC : O(|str|)   SC : O(|str|)

#include <bits/stdc++.h>
using namespace std;

// Returns the string mirror of a given string.
string stringMirror(string s) {
    string ans;
    ans.push_back(s[0]);
    
    for (int i = 1; i < s.length(); i++) {
        // If the current character is greater than the previous character, or if the
        // current character is equal to the previous character and the character two
        // positions ago is also equal to the previous character, we can add it to the prefix.
        if (s[i - 1] > s[i] || (i > 1 && s[i] == s[i - 1])) {
            ans.push_back(s[i]);
        } else {
            // If we can't add the current character to the prefix, we stop iterating
            // and return the prefix with its reverse appended to it.
            break;
        }
    }
    
    string curr = ans;
    reverse(ans.begin(), ans.end());
    return curr + ans;
}

/**
 * A sample main function that tests the stringMirror function with two inputs.
 */
int main() {
    string input1 = "abbabc";
    string input2 = "abcde";
    
    cout << "Input 1: " << input1 << endl;
    cout << "Output 1: " << stringMirror(input1) << endl;
    cout << "Input 2: " << input2 << endl;
    cout << "Output 2: " << stringMirror(input2) << endl;
    
    return 0;
}
