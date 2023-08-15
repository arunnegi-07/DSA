// Approach 2 : Using Concept of Sliding Window
// TC : O(N)  O(1)

#include <bits/stdc++.h>
using namespace std;

int maxOnes(int a[], int n)
{
    int count1 = 0;  // Count of consecutive ones
    int count0 = 0;  // Count of consecutive zeros
    int maxlen = 0;  // Maximum length of consecutive zeros
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            count1++;  // Increment count of consecutive ones
            if (count0)
                count0--;  // If there are consecutive zeros, decrement count
        } else {
            count0++;  // Increment count of consecutive zeros
            maxlen = max(maxlen, count0);  // Update maxlen if the current count of zeros is greater
        }
    }
    // The result is the maximum of maxlen (consecutive zeros) and count1 (consecutive ones)
    return maxlen + count1;  
}

int main() {
    // Sample input 1
    int input1[] = {1, 1, 0, 0, 1, 1, 1, 0, 1};
    int N1 = 9;
    int result1 = maxOnes(input1, N1);
    cout << "Maximum number of ones after flipping zeroes (Sample 1): " << result1 << endl;

    // Sample input 2
    int input2[] = {1, 0, 0, 1, 0, 1, 0, 1, 1};
    int N2 = 9;
    int result2 = maxOnes(input2, N2);
    cout << "Maximum number of ones after flipping one zeroes (Sample 2): " << result2 << endl;

    return 0;
}
