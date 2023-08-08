// Approach 2 : Optimized --> Using Map to store fractions so that we can complement of each in O(1) and reduce T.C
// TC : O(N*logN)   SC : O(N)

// Note : Refer to "Intuition" file attached to get proper Intuition behind this Optimization.

#include <bits/stdc++.h>
using namespace std;

// Recursive function to find the greatest common divisor (GCD) of two integers.
int gcd_recursive(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd_recursive(b, a % b);
    }
}

// Function to count pairs of fractions that sum to 1.
int countFractions(int n, int numerator[], int denominator[]) {

    // Converting every fraction to its simplest form  --> it takes O(N*logN)
    for (int i = 0; i < n; i++) {
        int g = gcd_recursive(numerator[i], denominator[i]);
        
        // Dividing both numerator and denominator by their GCD to simplify the fraction.
        numerator[i] /= g;
        denominator[i] /= g;
    }
    
    int count = 0;  // Initialize a count to keep track of pairs of fractions that sum to 1.
    unordered_map<int, unordered_map<int, int>> mp;  // Create a hash map to store frequency of pairs.

    // Loop through each fraction --> it takes O(N)
    for (int i = 0; i < n; i++) {                   
        int deno = denominator[i];  // Get the denominator of the current fraction.
        int num = numerator[i];     // Get the numerator of the current fraction.
        
        auto it = mp.find(deno);  // Find the denominator in the outer hash map.

        if (it != mp.end()) {
            unordered_map<int, int> &temp = it->second;  // Get the inner hash map for the current denominator.

            // Check if there's a fraction with a complementing numerator that sums to 1.
            if (temp.find(deno - num) != temp.end()) {
                count += temp[deno - num];  // Increment the count with the frequency of complementing fractions.
            }
        }
        
        // Add the current fraction to the hash map, updating the frequency of its numerator.
        mp[deno][num]++;
    }

    return count;  // Return the count of pairs of fractions that sum to 1.
}

int main() {
    // Sample input 1
    int n1 = 4;
    int numerator1[] = {1, 2, 2, 8};
    int denominator1[] = {2, 4, 6, 12};
    int result1 = countFractions(n1, numerator1, denominator1);
    cout << "Sample Input 1: " << result1 << " pairs of fractions sum to 1." << endl;

    // Sample input 2
    int n2 = 5;
    int numerator2[] = {3, 1, 12, 81, 2};
    int denominator2[] = {9, 10, 18, 90, 5};
    int result2 = countFractions(n2, numerator2, denominator2);
    cout << "Sample Input 2: " << result2 << " pairs of fractions sum to 1." << endl;

    return 0;
}