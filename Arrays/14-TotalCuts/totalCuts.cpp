#include <bits/stdc++.h>
using namespace std;

int totalCuts(int N, int K, int A[]) {
    // Initialize arrays to store maximum and minimum values on the left and right side of each index
    int right[N], left[N];

    // Calculate the maximum value on the left side of each index
    left[0] = A[0];
    for (int i = 1; i < N; i++) {
        left[i] = max(left[i-1], A[i]);
    }

    // Calculate the minimum value on the right side of each index
    right[N-1] = A[N-1];
    for (int i = N-2; i >= 0; i--) {
        right[i] = min(right[i+1], A[i]);
    }

    // Check all possible cuts and count the ones that satisfy the conditions
    int ans = 0;
    for (int i = 0; i < N-1; i++) {
        if (left[i] + right[i+1] >= K) {
            ans++;
        }
    }

    return ans;
}

int main() {
    // Sample input 1
    int N1 = 5;
    int K1 = 5;
    int A1[N1] = {3, 1, 7, 5, 9};
    int ans1 = totalCuts(N1, K1, A1);
    cout << "Sample Input 1: " << endl;
    cout << "N = " << N1 << ", K = " << K1 << endl;
    cout << "A = ";
    for (int i = 0; i < N1; i++) {
        cout << A1[i] << " ";
    }
    cout << endl;
    cout << "Number of valid cuts = " << ans1 << endl;
    cout << endl;

    // Sample input 2
    int N2 = 6;
    int K2 = 8;
    int A2[N2] = {1, 2, 3, 4, 5, 6};
    int ans2 = totalCuts(N2, K2, A2);
    cout << "Sample Input 2: " << endl;
    cout << "N = " << N2 << ", K = " << K2 << endl;
    cout << "A = ";
    for (int i = 0; i < N2; i++) {
        cout << A2[i] << " ";
    }
    cout << endl;
    cout << "Number of valid cuts = " << ans2 << endl;
    cout << endl;

    return 0;
}
