// Approach 1 : BruteForce Method
// TC : O(N*N)  SC : O(N)

#include <string>
#include <unordered_map>

std::string FirstNonRepeating(const std::string& A) {
    std::unordered_map<char, int> count;  // Map to store character counts
    std::string result;  // Result string to store the first non-repeating characters

    for (char ch : A) {
        count[ch]++; // Increment the count of the character

        char firstNonRepeating = '#'; // Initialize with '#' as default

        // Find the first non-repeating character
        for (char c : A) {
            if (count[c] == 1) {
                firstNonRepeating = c;
                break;
            }
        }

        result += firstNonRepeating; // Append the first non-repeating character to the result
    }

    return result;
}
