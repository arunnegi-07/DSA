// TC : O(N1+N2+N3)  SC : O(1)
#include<bits/stdc++.h>
using namespace std;

long long maxSum(long long sum1, long long sum2, long long sum3) {
    // Returns the maximum of three values
    return max(sum1, max(sum2, sum3));
}

int maxEqualSum(int N1, int N2, int N3, vector<int>& S1, vector<int>& S2, vector<int>& S3) {
    // Calculate the sum of each stack
    long long sum1 = accumulate(S1.begin(), S1.end(), 0LL);
    long long sum2 = accumulate(S2.begin(), S2.end(), 0LL);
    long long sum3 = accumulate(S3.begin(), S3.end(), 0LL);

    // If the sum of all the stacks is equal, then it will be the maximum equal sum
    if (sum1 == sum2 && sum1 == sum3) {
        return sum1;
    }

    // Initialize pointers for each stack
    int ptr1 = 0, ptr2 = 0, ptr3 = 0;

    // Iterate until we reach the end of any stack
    while (ptr1 < S1.size() && ptr2 < S2.size() && ptr3 < S3.size()) {
        // Find the maximum sum among the current sums of the stacks
        long long maxSumValue = maxSum(sum1, sum2, sum3);

        // If the maximum sum corresponds to the first stack
        if (maxSumValue == sum1) {
            sum1 -= S1[ptr1];  // Remove the top element from the first stack
            ptr1++;  // Move the pointer to the next element
        }
        // If the maximum sum corresponds to the second stack
        else if (maxSumValue == sum2) {
            sum2 -= S2[ptr2];  // Remove the top element from the second stack
            ptr2++;  // Move the pointer to the next element
        }
        // If the maximum sum corresponds to the third stack
        else {
            sum3 -= S3[ptr3];  // Remove the top element from the third stack
            ptr3++;  // Move the pointer to the next element
        }

        // If the sums of all the stacks become equal, return the sum
        if (sum1 == sum2 && sum1 == sum3) {
            return sum1;
        }
    }

    // If we cannot obtain an equal sum by removing elements, return 0
    return 0;
}

int main() {
    // Sample Input 1
    int N1 = 3, N2 = 4, N3 = 2;
    vector<int> S1 = {4, 2, 3};
    vector<int> S2 = {1, 1, 2, 3};
    vector<int> S3 = {1, 4};

    int result1 = maxEqualSum(N1, N2, N3, S1, S2, S3);
    cout << "Sample Input 1: " << result1 << endl;

    // Sample Input 2
    int N4 = 2, N5 = 1, N6 = 3;
    vector<int> S4 = {4, 7};
    vector<int> S5 = {10};
    vector<int> S6 = {1, 2, 3};

    int result2 = maxEqualSum(N4, N5, N6, S4, S5, S6);
    cout << "Sample Input 2: " << result2 << endl;

    return 0;
}
