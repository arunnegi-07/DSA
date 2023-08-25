// Used Two Pointer Approach
// TC : O(N)  SC : O(1)

#include <iostream>
using namespace std;

// Function to check if a given string is a palindrome
int isPalindrome(string S)
{
    // Initialize two pointers, 'start' at the beginning of the string
    // and 'end' at the end of the string
    int start = 0, end = S.size() - 1;
    
    // Continue checking characters until 'start' is less than 'end'
    while (start < end) {
        // If characters at the 'start' and 'end' positions are different,
        // return 0 (indicating it's not a palindrome)
        if (S[start] != S[end])
            return 0;
        
        // Move the 'start' pointer to the right and the 'end' pointer to the left
        start++;
        end--;
    }
    
    // If the loop completes without returning 0, the string is a palindrome,
    // so return 1 to indicate that
    return 1;
}

int main()
{
    // Sample input 1: A palindrome string
    string input1 = "racecar";
    if (isPalindrome(input1))
        cout << input1 << " is a palindrome." << endl;
    else
        cout << input1 << " is not a palindrome." << endl;

    // Sample input 2: A non-palindrome string
    string input2 = "hello";
    if (isPalindrome(input2))
        cout << input2 << " is a palindrome." << endl;
    else
        cout << input2 << " is not a palindrome." << endl;

    return 0;
}
