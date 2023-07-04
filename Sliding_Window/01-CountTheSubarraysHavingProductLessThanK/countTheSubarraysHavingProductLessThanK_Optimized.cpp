// Approach 2 : Optmized using concept of Sliding Window.
// TC : O(N)  SC : O(1)

// Note : Refer to attached 'Intuition' file to get proper explaination behind this approach.

#include <bits/stdc++.h>
using namespace std;

int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
    int start = 0; // Start pointer for the sliding window
    int end = 0; // End pointer for the sliding window
    
    long long product = 1; // Product of elements in the current subarray
    int count = 0; // Count of subarrays with product less than k
    
    while (end < n) {
        product *= a[end]; // Multiply the product by the element at the end pointer
        
        // Shrink the window from the left if product exceeds or equals k
        while (product >= k && start < end) {
            product /= a[start]; // Divide the product by the element at the start pointer
            start++; // Move the start pointer to the right
        }
        
        // Check if product is less than k
        if (product < k) {
            count += end - start + 1; // Add the length of the current subarray to the count
        }
        
        end++; // Move the end pointer to the right to expand the window
    }
    
    return count;
}

int main() {
    // Sample Input 1
    vector<int> nums1 = {1, 2, 3, 4};
    int n1 = nums1.size();
    long long k1 = 10;
    
    int result1 = countSubArrayProductLessThanK(nums1, n1, k1);
    cout << "Sample Input 1: " << result1 << endl; // Expected Output: 7
    
    // Sample Input 2
    vector<int> nums2 = {1, 9, 2, 8, 6, 4, 3};
    int n2 = nums2.size();
    long long k2 = 100;
    
    int result2 = countSubArrayProductLessThanK(nums2, n2, k2);
    cout << "Sample Input 2: " << result2 << endl; // Expected Output: 16
    
    return 0;
}
