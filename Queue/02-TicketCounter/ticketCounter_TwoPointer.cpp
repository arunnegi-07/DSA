// Approach 3 : Two Pointers Approach
//  TC : O(N)  SC : O(1)

// Note : Just dry run all the 4 examples in "IntuitionApproach2" file you will easily get this approach.

#include <bits/stdc++.h>
using namespace std;


int distributeTicket(int N, int K) {
    int left = 1, right = N;  // Initialize left and right pointers

    // Loop until left pointer is less than or equal to right pointer
    while (left <= right) {
        if (left + K <= right) {
            // If the distance between left and right pointers is greater than or equal to K,
            // move the left pointer by K steps
            left += K;
        } else {
            // If the distance between left and right pointers is less than K,
            // return the current value of the right pointer as it is the last person to get a ticket
            return right;
        }

        if (right - K >= left) {
            // If the distance between left and right pointers is greater than or equal to K,
            // move the right pointer by K steps
            right -= K;
        } else {
            // If the distance between left and right pointers is less than K,
            // return the current value of the left pointer as it is the last person to get a ticket
            return left;
        }
    }
}

int main() {
    // Sample input 1
    int N1 = 7;  // Total number of tickets
    int K1 = 3;  // Number of tickets to be distributed at a time
    
    int ticket1 = distributeTicket(N1, K1);
    cout << "Ticket 1: " << ticket1 << endl;

    // Sample input 2
    int N2 = 10;  // Total number of tickets
    int K2 = 5;   // Number of tickets to be distributed at a time
    
    int ticket2 = distributeTicket(N2, K2);
    cout << "Ticket 2: " << ticket2 << endl;

    return 0;
}
