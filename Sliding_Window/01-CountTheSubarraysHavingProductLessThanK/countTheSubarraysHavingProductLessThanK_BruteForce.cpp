// Appraoch 1 : BruteForce Method --> Checking all Sub Arrays.
// TC : O(N^2)  SC : O(1)

#include <bits/stdc++.h>
using namespace std;

int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
    int count = 0;

    // Iterate through each possible subarray
    for (int i = 0; i < n; i++) {
        int product = 1;

        // Calculate product of subarray starting from index i
        for (int j = i; j < n; j++) {
            product *= a[j];

            // Check if product is less than k
            if (product < k)
                count++;
            else
                break; // Break out of the inner loop if product exceeds k
        }
    }

    return count;
}

int main() {
    int n, k;
    n = 4;
    k = 10;
    vector<int> a = {1, 2, 3, 4};
    int result = countSubArrayProductLessThanK(a, n, k);
    cout << "Output: " << result << endl;

    n = 7;
    k = 100;
    vector<int> b = {1, 9, 2, 8, 6, 4, 3};
    result = countSubArrayProductLessThanK(b, n, k);
    cout << "Output: " << result << endl;

    return 0;
}
