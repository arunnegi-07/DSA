/*
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Problem : Distinct Difference

Given an array A[] of length N. For each index, i (1<=i<=N), find the difference between the number of distinct elements in it's left and right side in the array. 

Example:

Input:
N = 3
arr[] = {4, 3, 3}
Output: {-1, 0, 2}
Explanation: For index i=1, there are 0 distinct element in the left side of it, and 1 distinct element(3) in it's right side. So difference is 0-1 = -1. 

Similarly for index i=2, there is 1 distinct element (4) in left side of it, and 1 distinct element(3) in it's right side. So difference is 1-1 = 0.

Similarly for index i=3, there are 2 distinct elements (4 and 3) in left side of it, and 0 distinct elements in it's left side. So difference is 2-0 = 2.
                                                                                                                                                                      
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                                                                                                                                             */
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force:
// TC: O(N^2)  SC: O(N)

function to get the distinct difference between pairs of elements in an array
vector<int> getDistinctDifference(int n, int A[]) {
    // create an empty vector to store the results
    vector<int> ans;

    // create two empty unordered sets to store the elements in the pairs
    unordered_set<int> s1, s2;

    // iterate over all pairs of elements in the array
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            // add the second element in the pair to s2
            s2.insert(A[j]);
        }

        for (auto& num : s2) {
           cout << num << ' ';
        }  
        cout << endl;   
   
        // compute the distinct difference between s1 and s2 and add it to the result vector
        ans.push_back(s1.size() - s2.size());

        // clear s2 and add the first element in the pair to s1
        s2.clear();
        s1.insert(A[i]);
    }

    // return the result vector
    return ans;
}

// Approach 2: 

// function to get the distinct difference between pairs of elements in an array
vector<int> getDistinctDifference(int n, int A[]) {
    // create an empty vector to store the results
    vector<int> ans;

    // create two empty unordered sets to store the elements in the pairs
    unordered_map<int,int> left, right;
    
    // calculating frequency of each values and storing it in 'right' map
    for(int i=0;i<n;i++){
        right[A[i]]++;
    }

    for(int i=0; i<n; i++) {

        right[A[i]]--;

        if(right[A[i]] == 0) right.erase(A[i]);
        
        ans.push_back(left.size() - right.size());

        left[A[i]]++;
    }

    // return the result vector
    return ans;
}

int main() {
    // sample input
    int n = 5;
    int A[] = {1, 2, 1, 3, 2};

    // call the function and print the result
    vector<int> result = getDistinctDifference(n, A);
    for(int i=0; i<result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
