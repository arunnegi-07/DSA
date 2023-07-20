// TC : O(N)  SC : O(N)

#include <iostream>
#include <unordered_map>
using namespace std;

char nonrepeatingCharacter(string S) {
    // Unordered map to store the count of each character in the string
    unordered_map<char, int> char_count;

    // Count the occurrences of each character in the string
    for (char ch : S) {
        char_count[ch]++;
    }

    // Iterate through the string again to find the first non-repeating character
    for (char ch : S) {
        if (char_count[ch] == 1) {
            return ch;
        }
    }

    // If no non-repeating character is found, return '$'
    return '$';
}

int main() {
    // Example 1
    string S1 = "hello";
    cout << nonrepeatingCharacter(S1) << endl; // Output: 'h'

    // Example 2
    string S2 = "zxvczbtxyzvy";
    cout << nonrepeatingCharacter(S2) << endl; // Output: 'c'

    return 0;
}
