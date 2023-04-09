#include<bits/stdc++.h>
using namespace std;

// Approach 1 : Brute Force Approach
// TC : O(N^3)  SC : O(1)

// This function finds the sum of three integers in an array that is closest to a given target.
// The function takes an integer array A, its size N, and the target integer as input.
int closest3Sum(int A[], int N, int X) {
    int min_diff = INT_MAX; // set initial minimum difference to the maximum value an integer can hold
    int result = 0; // initialize result variable to hold the closest sum found so far
    
    // three nested loops to iterate over all possible triplets of integers in the array
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            for (int k = j+1; k < N; k++) {
                int current_sum = A[i] + A[j] + A[k]; // calculate the sum of the current triplet
                int current_diff = abs(current_sum - X); // calculate the difference between the sum and the target
                
                // update the result and minimum difference if the current sum is closer to the target than the previous closest sum
                if (current_diff < min_diff) {
                    min_diff = current_diff;
                    result = current_sum;
                }
            }
        }
    }
    
    return result; // return the closest sum found
}

// Approach 2 : Using Sorting and 2 Pointers Approach
// TC : O(N^2)  SC : O(1)

// This function finds the sum of three integers in an array that is closest to a given target.
int closest3Sum(int A[], int N, int X)
{ 
        // Sort the input array in ascending order
        sort(A,A+N);
        
        // Initialize the minimum difference and closest sum to be used later
        int min_diff = INT32_MAX;
        int closest = 0;

        // Iterate over each element in the array as the potential first element in the triplet
        for(int i=0;i<N-2;i++){
            // Use two pointers approach to find the other two elements that sum up closest to the target
            int j = i+1, k = N-1;;
            while(j<k){
                // Calculate the sum of the three elements
                int sum = A[i] + A[j] + A[k];
                
                // Check if the current sum is closer to the target than the previous closest sum
                if(abs(sum - X) < min_diff){
                       min_diff = abs(sum - X);
                       closest = sum;
                }
                
                // Move the pointers depending on the current sum relative to the target
                if(sum < X)
                    j++;
                else if(sum > X)
                    k--;
                else 
                    return closest;  // Return the closest sum if it is equal to the target
            }
        }
        
        // Return the closest sum found
        return closest;
}


int main(){
    int A[] = {7,-6,-6,10,-9,-8,2,-10,-10};
    int N = 9;
    int X = -4;
    cout << closest3Sum(A, N, X) << endl; // expected output: -4

    int A1[] = {-1, 2, 1, -4};
    int N1 = 4;
    int X1 = 1;
    cout << closest3Sum(A1, N1, X1) << endl; // expected output: 2
    
    int A2[] = {0, 0, 0};
    int N2 = 3;
    int X2 = 1;
    cout << closest3Sum(A2, N2, X2) << endl; // expected output: 0
    
    int A3[] = {10, 20, 30, 40, 50};
    int N3 = 5;
    int X3 = 100;
    cout << closest3Sum(A3, N3, X3) << endl; // expected output: 100
}