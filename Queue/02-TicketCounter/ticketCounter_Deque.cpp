// Approach 1 : Using Doubly Ended Queue i.e Deque
//  TC : O(N)  SC : O(N)

// Note : Please see ProblemExplaination file attached in order to get the problem more clearly as problem statement
//        is not so much clear about what problem is actually asking.


#include <bits/stdc++.h>
using namespace std;

// Function to distribute tickets using a doubly ended queue (deque)
int distributeTicket(int N, int K) {
    deque<int> dq;
    
    // Inserting values 1 to N into the deque
    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }
    
    // Flags to keep track of chances for front and back
    bool frontChance = true, backChance = false;
    
    while (1) {
        // If the deque size is less than or equal to K, return the back element if it's the front's chance
        // Otherwise, return the front element
        if (dq.size() <= K) {
            if (frontChance) {
                return dq.back();
            }
            return dq.front();
        }
        
        // If the deque size is greater than K, remove K elements from the front and update the flags
        if (dq.size() > K) {
            for (int i = 0; i < K; i++) {
                dq.pop_front();
                frontChance = false;
                backChance = true;
            }
        }
        
        // If the deque size is still greater than K, remove K elements from the back and update the flags
        if (dq.size() > K) {
            for (int i = 0; i < K; i++) {
                dq.pop_back();
                frontChance = true;
                backChance = false;
            }
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
