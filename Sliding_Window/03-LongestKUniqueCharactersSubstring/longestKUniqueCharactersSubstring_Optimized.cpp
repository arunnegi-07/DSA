// Approach : Sliding Window Method
// TC : O(|S|)  SC : O(|S|)

// Problem is easy to understand by the comments written.

#include <buts/stdc++.h>
using namespace std;

// Function to find the length of the longest substring with exactly K distinct characters
int longestKSubstr(string S, int K) {
   int longestKSubstr(string S, int K) {
        if (K <= 0) {
            return -1;
        }
    
        unordered_map<char, int> char_count; // Unordered map to keep track of character counts
        int max_length = -1; // Initialize max_length to -1
        int left = 0, right = 0; // Initialize left and right pointers
    
        while (right < S.length()) {
            // Expand the window by moving the right pointer
            char_count[S[right]]++;
    
            // If the number of unique characters exceeds K, shrink the window
            while (char_count.size() > K) {
                char left_char = S[left];
                char_count[left_char]--;
                if (char_count[left_char] == 0) {
                    char_count.erase(left_char);
                }
                left++;
            }
    
            // Check if the current window size is the longest
            if (char_count.size() == K) {
                max_length = max(max_length, right - left + 1);
            }
    
            // Move the right pointer to expand the window
            right++;
        }
    
        return max_length;
    }
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
