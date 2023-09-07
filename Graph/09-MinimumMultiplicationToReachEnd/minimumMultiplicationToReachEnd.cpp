// TC : O(10^5)  SC : O(10^5)
// Just the simple variation of Dijkstra's Algorithm

#include <bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int>& arr, int start, int end) {
    // Base case: If the start and end values are the same, no multiplications needed.
    if (start == end) {
        return 0;
    }

    // Create a queue to perform breadth-first search (BFS).
    queue<pair<int, int>> q;
    q.push({start, 0});  // Initialize the queue with the start value and 0 steps.
    
    // Create a distance array to store the minimum steps to reach each possible value.
    vector<int> dist(100000, 1e9);  // Initialize with a large value.
    dist[start] = 0;  // The distance to the start value is 0.
    
    int mod = 100000;  // The constant for the modulo operation.

    // Start BFS traversal.
    while (!q.empty()) {
        int node = q.front().first;  // Current value from the queue.
        int steps = q.front().second;  // Steps taken to reach this value.
        q.pop();  // Remove the current value from the queue.

        // Iterate through each number in the 'arr' array for multiplication.
        for (auto it : arr) {
            int num = (it * node) % mod;  // Calculate the new value after multiplication and modulo operation.

            // Check if taking this step reduces the number of steps to reach 'num'.
            if (steps + 1 < dist[num]) {
                dist[num] = steps + 1;  // Update the minimum steps to reach 'num'.
                
                // If 'num' is the 'end' value, return the total steps taken.
                if (num == end) {
                    return steps + 1;
                }

                // Otherwise, add 'num' to the queue with updated steps.
                q.push({num, steps + 1});
            }
        }
    }

    // If it's not possible to reach the 'end' value, return -1.
    return -1;
}


int main() {
    // Sample Input 1
    vector<int> arr1 = {2, 5, 7};
    int start1 = 3;
    int end1 = 30;
    int result1 = minimumMultiplications(arr1, start1, end1);
    cout << "Minimum Steps for Sample Input 1: " << result1 << endl;  // Output: 2
    
    // Sample Input 2
    vector<int> arr2 = {3, 4, 65};
    int start2 = 7;
    int end2 = 66175;
    int result2 = minimumMultiplications(arr2, start2, end2);
    cout << "Minimum Steps for Sample Input 2: " << result2 << endl;  // Output: 4

    return 0;
}
