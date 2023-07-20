// Approach 3 : Expand from Middle
// TC : O(|S|^2)  SC : O(1)

// Note : Another Approach could be a Dynamic Programming Approach having TC : O(|S|^2) and SC : O(|S|^2)

#include <iostream>
#include <string>
using namespace std;

// Function to get sub string after checking for longest Palindrome for every iteration
// It is being called from longestPalin() function.
static string getSubstr(string s, int start, int end) {
    int n = s.length();
    while (start >= 0 && end < n) {
        if (s[start] == s[end]) {
            start--;
            end++;
        } else {
            break;
        }
    }
    return s.substr(start + 1, end - start - 1); // 1st parameter is a start index and 2nd is length
}
    
// Function to find the longest palindromic substring in string S
string longestPalin (string S) {
    int n = S.length();
    int len = 0;
    string ans = "";

    for (int i = 0; i < n; i++) {
        string curr = getSubstr(S, i, i); // Considering Odd Palindrome
        // if Palindrome we found is having length greater than previously found Palindrome
        // we make necessary updations
        if (curr.length() > len) {
            ans = curr;
            len = curr.length();
        }
            
        // same in case of Even Palindrome
        curr = getSubstr(S, i, i + 1); // Considering Even Palindrome
        if (curr.length() > len) {
            ans = curr;
            len = curr.length();
        }
    }
        
    // Finally returning the answer
    return ans;
}

int main() {
    // Sample input 1
    string input1 = "babad";
    cout << "Input: " << input1 << endl;
    string result1 = longestPalin(input1);
    cout << "Longest Palindrome: " << result1 << endl;

    // Sample input 2
    string input2 = "cbbd";
    cout << "Input: " << input2 << endl;
    string result2 = longestPalin(input2);
    cout << "Longest Palindrome: " << result2 << endl;

    return 0;
}
