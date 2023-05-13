// TC : O(N)  SC : O(1)

#include <bits/stdc++.h>
using namespace std;

// function to calculate the number of operations required
// to make the given array a palindrome
int bitMagic(int n, int arr[]) {
    int cnt=0;
    for(int i=0; i<n/2; i++) {
        if(arr[i]!=arr[n-1-i]) { // check if the elements at both ends are equal
            cnt++; // increment the count if they are not equal
        }
    }
    // if the count is even, return half of the count,
    // else return half of the count plus one
    return (cnt%2==0) ?  cnt/2 :  cnt/2+1;
}

int main() {
    // Sample Usage
    int n = 5;
    int arr[] = {1, 2, 3, 2, 1};
    int res = bitMagic(n, arr); // calculate the number of operations required
    cout << res << endl; // print the result
    return 0;
}
