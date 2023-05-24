// TC : O(N)  SC : O(1)

#include <iostream>
#include <vector>
using namespace std;

int getMaximum(int N, vector<int> &arr) {
    // To store total sum of given array
    long long totalSum = 0;
   
    // calculating total Sum
    for (auto i : arr) {
        totalSum += i;
    }
   
    // checking for max. number of bowls which can hold equal number of candies
    for (int bowls = N; bowls > 0; bowls--) {
        if (totalSum % bowls == 0)
            return bowls;   // returning max. number of bowls
    }
}

int main() {
    // Sample input 1
    int N1 = 4;
    vector<int> arr1 = {2, 4, 6, 8};
    int result1 = getMaximum(N1, arr1);
    cout << "Maximum divisor for sample input 1: " << result1 << endl;

    // Sample input 2
    int N2 = 6;
    vector<int> arr2 = {3, 5, 7, 9, 11, 13};
    int result2 = getMaximum(N2, arr2);
    cout << "Maximum divisor for sample input 2: " << result2 << endl;

    return 0;
}
