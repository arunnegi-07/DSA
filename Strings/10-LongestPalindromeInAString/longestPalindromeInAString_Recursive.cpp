// Approach 2 : Another BruteForce but Recursive Method
// TC : O(|S|^3)  SC : O(|S|)

#include <iostream>
#include <string>
using namespace std;

// Helper Function to check if any SubString is a Palindrome or not
bool isPalindrome(const string& str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
    }
    return true;
}
    
// Helper which Recursively check for Longest Palindromic SubString
string longestPalinUtil(const string& S, int start, int end) {
    // Base case no. 1 --> returns empty string if start index become greater then end, means string has become empty
    // It is also useful if String we got in starting is itslef empty i.e S = "", then it will return "" as answer
    if (start > end)
        return "";
        
    // Base case no. 2 --> if String length is '1' it means start == end, so it is already a Palidrome
    // So, no need to check so simply return it 
    // it is also helpful in beginning as if in starting itself S = "a" (let's say), so it return "a" as answer
    if (start == end)
        return S.substr(start, 1);
    
    // Base case no. 3 --> So if length is greater than "1" then we will check it if it is Palindrome
    // if it is a Palindrome just return it back, else make recursive calls further 
    if (isPalindrome(S, start, end))
        return S.substr(start, end - start + 1);
    
    // Recursive call to find the longest palindromic substring excluding the last character
    string palindrome1 = longestPalinUtil(S, start, end - 1);  
    // Recursive call to find the longest palindromic substring excluding the first character
    string palindrome2 = longestPalinUtil(S, start + 1, end); 
        
    // Compare the lengths of the palindromic substrings obtained from the recursive calls
    if (palindrome1.length() >= palindrome2.length())
        return palindrome1;  // Return the longer palindromic substring
    else
        return palindrome2;  // Return the longer palindromic substring
}
    
// Function to find the longest palindromic substring in string S
string longestPalin(string S) {
    // Call the helper function with start and end indices
    return longestPalinUtil(S, 0, S.length() - 1);  
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
