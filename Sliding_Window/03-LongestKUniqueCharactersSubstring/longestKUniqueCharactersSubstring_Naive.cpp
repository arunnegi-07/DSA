// Approach : Naive Approach --> Checking all Substrings
// TC : O(|S|*|S|)  SC : O(|S|)

#include <buts/stdc++.h>
using namespace std;

// Function to find the length of the longest substring with exactly K distinct characters
int longestKSubstr(string S, int K) {
    int maxLength = -1;  // Initialize with -1 to handle the case where no valid substring is found.

    // Iterate through all possible starting indices of the substring
    for (int start = 0; start < S.length(); ++start) {
        unordered_set<char> charSet; // A set to store unique characters in the current substring
        
        // Iterate through all possible ending indices of the substring
        for (int end = start; end < S.length(); ++end) {
            charSet.insert(S[end]); // Add the character at the current end position to the set
            
            // If the size of the set (number of unique characters) is equal to K
            if (charSet.size() == K) {
                maxLength = max(maxLength, end - start + 1); // Update the maximum length
            }

            // If more than K unique characters, break the inner loop
            if (charSet.size() > K) {
                break;
            }
        }
    }

    return maxLength; // Return the maximum length of the substring
}

int main() {
    string S = "aabacbebebe";
    int K = 3;
    int result = longestKSubstr(S, K);
    cout << "Output: " << result << endl;

    S = "aaaa";
    K = 2;
    result = longestKSubstr(S, K);
    cout << "Output: " << result << endl;

    return 0;
}
