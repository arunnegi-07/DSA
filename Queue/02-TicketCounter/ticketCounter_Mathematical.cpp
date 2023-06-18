// Approach 2 : Based on Designing Mathematical formula by just analyzing the Problem 
//  TC : O(N)  SC : O(1)

// Note : For Intuition behind this Approach see attached file "IntuitionApproach2" and also make
//        sure you got the problem understanding, if not refer file "ProblemExplaination"


#include <bits/stdc++.h>
using namespace std;

int distributeTicket(int N, int K) {
    int m = N / K;  // Calculating the total number of groups possible
    int r = N % K;  // There may be a chance that some people are left after forming the groups,
                    // so we find those and store them in 'r'
        
    // Case 1: If the total number of groups is even
    if (m % 2 == 0) {
        // Also, if none of the persons are left
        if (r == 0)
            // This will be the last person to get a ticket in that case
            return ((m / 2) * K + 1);
        // If there are still people left, the last person to get a ticket will be given as
        return (m / 2) * K + r;
    }
    // Case 2: If the total number of groups is odd, same cases are here
    else {
        if (r == 0)
            return N - ((m / 2) * K);
        return N - ((m / 2) * K + r - 1);
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
