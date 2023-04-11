#include<bits/stdc++.h>
using namespace std;

// Approach 1 : Using Sorting
// TC : O(N*logN)  SC : O(1)

// Function to find the Kth smallest element 
int kthSmallest(int arr[], int l, int r, int K) {
    // Sort the array in non-decreasing order
    sort(arr+l, arr+r+1);
    return arr[K-1];
}


// Approach 2 : Using Min Heap (Pre-requisite : have knowledge of how MinHeap works)
// TC : O(N)  SC : O(logN)

// Function to find the Kth smallest element 
int kthSmallest(int arr[], int l, int r, int K) {
    
    // Create a min heap (priority_queue) to store the elements of the array in non-decreasing order
    priority_queue<int, vector<int>, greater<int>> pq;
    
    // Insert all the elements of the array into the min heap
    for (int i = l; i <= r; i++) {
        pq.push(arr[i]);
    }  
    
    // Remove K-1 smallest elements from the heap
    for(int i=1;i<=K-1;i++)
        pq.pop();

    // After removing K-1 elements from the heap     
    // the element at the top of the heap is the Kth smallest element 
    return pq.top();   // return that value
}


int main(){

   // Sample Input 1
    int arr1[] = {7, 10, 4, 3, 20, 15};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int k1 = 3;
    cout << "Kth smallest element for Input 1: " << kthSmallest(arr1, 0, n1-1, k1) << endl;

    // Sample Input 2
    int arr2[] = {7, 10, 4, 20, 15};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int k2 = 4;
    cout << "Kth smallest element for Input 2: " << kthSmallest(arr2, 0, n2-1, k2) << endl;

    return 0;
} 