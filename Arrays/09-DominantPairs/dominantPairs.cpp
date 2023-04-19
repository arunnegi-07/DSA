#include <bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
// TC : O(N^2)  SC : O(1)

int dominantPairs(int n, vector<int> &arr){
    // count variable to calculate dominant pairs
    int count = 0;
    
    // iterate over the first half of the array for 'i'
    for(int i=0;i<n/2;i++){
        // iterate over the second half of the array for 'j'
        for(int j=n/2;j<n;j++){
            // check if the pair (i, j) is dominant
            if(arr[i] >= 5*arr[j]){
                // increment the count if the pair is dominant
                count ++;
            }
        }
    }
    // return the total count of dominant pairs
    return count;
}

// Approach 2 : Using Sorting and Two Pointers
// TC : O(N)  SC : O(1)

int dominantPairs(int n,vector<int> &arr){
    // count variable to calculate dominant pairs
    int count = 0;
        
    // sorting first half 
    sort(arr.begin(), arr.begin() + n/2);
    // sorting second half
    sort(arr.begin() + n/2, arr.end());
        
    // initializing i and j to there starting positions
    int i = 0, j = n/2;
        
    // iterating over array till i < n/2 and j < n
    while(i < n/2 && j < n) {
        //  check if the pair (i, j) is dominant
        if(arr[i] >= 5*arr[j]){
            // adding all the remaining count of arr[i] from current 'i'
            count += (n/2 - i);
            // incrementing 'j' to check for other arr[j] values
            j++;
        }
        // if pair is not dominant skipping all the remaining 'arr[j]' values for current 'arr[i]'
        else{
            // incrementing 'i' and going to next 'arr[i]' value
            i++;
        }
    }
    // returning the count value which is our final answer 
    return count;
}

int main() {
    // Sample input 1:
    int n1 = 6;
    vector<int> arr1 = {2, 10, 3, 4, 9, 5};
    int count1 = dominantPairs(n1, arr1);
    cout << "Sample Input 1: n = " << n1 << ", arr = {2, 10, 3, 4, 9, 5}\n";
    cout << "Output: " << count1 << endl << endl;

    // Sample input 2: 
    int n2 = 8;
    vector<int> arr2 = {12, 1, 6, 20, 5, 8, 2, 15};
    int count2 = dominantPairs(n2, arr2);
    cout << "Sample Input 2: n = " << n2 << ", arr = {12, 1, 6, 20, 5, 8, 2, 15}\n";
    cout << "Output: " << count2 << endl << endl;

    // Sample input 3: 
    int n3 = 3;
    vector<int> arr3 = {10, 2, 3};
    int count3 = dominantPairs(n3, arr3);
    cout << "Sample Input 3: n = " << n3 << ", arr = {10, 2, 3}\n";
    cout << "Output: " << count3 << endl << endl;

    return 0;
}
