// Approach 1 : BruteForce Method
// TC : O(|S|^3)  SC : O(1)

#include <iostream>
#include <string>
using namespace std;

// Function to check if a substring is a palindrome
bool isPalindrome(int start, int end, string S) {
    while (start < end) {
        if (S[start] != S[end])
            return false;
        start++;
        end--;
    }
    return true;
}

// Function to find the longest palindrome in a string
string longestPalin(string S) {
    string ans;

    for (int start = 0; start < S.length(); start++) {
        for (int end = start; end < S.length(); end++) {
            // Check if the current substring is a palindrome
            if (isPalindrome(start, end, S) && (end - start + 1) > ans.length()) {
                // If it is a palindrome and its length is greater than the current longest palindrome, update the answer
                ans = "";
                ans += S.substr(start, end - start + 1);
            }
        }
    }
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
