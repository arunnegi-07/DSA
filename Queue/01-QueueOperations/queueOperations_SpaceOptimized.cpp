/* Approach 1 
   TC : O(N*M) --> if we also consider the part which is already provided by the code.
                   else if we consider only the functions we have to write then it is O(N), 
                   but overall including the main function content it is O(N*M).
   
   SC : O(1)  --> By making minor changes to our code, we have optimized the space complexity. 
                  Our new approach involves taking the front value from the queue, removing it, 
                  and then pushing it back to the queue. This results in a different ordering of 
                  the elements in the queue, but since we are only calculating frequencies, the 
                  change in ordering does not affect the outcome.            
                                                                                                                        */
#include<bits/stdc++.h>
using namespace std;

// Function to insert an element into the queue
void insert(queue<int> &q, int k){
    q.push(k);
}

// Function to find frequency of an element return the frequency of k
int findFrequency(queue<int> &q, int k){
    int freq = 0;
    queue<int> tempQueue = q;
          
    while(!tempQueue.empty()){
        int val = tempQueue.front();
        tempQueue.pop();
        
        if(val == k){
            freq++;
        }
    }
    return freq;
}

int main() {
    // Sample Input 1
    int N1 = 8; // Number of elements to insert
    int valArray1[] = {1, 2, 3, 4, 5, 2, 3, 1};
    int M1 = 5; // Number of elements to find frequency
    int freqVal1[] = {1, 3, 2, 9, 10};  // elements whose frequency we want to calculate  
    queue<int> q1;

    // Inserting elements into the queue
    for(int i = 0; i < N1; i++){
        insert(q1, valArray1[i]);
    }

    // Finding frequency of each element
    for(int i = 0; i < M1; i++){
        int element = freqVal1[i]; // Elements after insertion
        int frequency = findFrequency(q1, element);
        cout << frequency << endl;
    }

    // Sample Input 2
    int N2 = 6; // Number of elements to insert
    int valArray2[] = {1, 2, 1, 1, 1, 4};
    int M2 = 4; // Number of elements to find frequency
    int freqVal2[] = {1, 5, 4, 3};  // elements whose frequency we want to calculate  
    queue<int> q2;

    // Inserting elements into the queue
    for(int i = 0; i < N2; i++){
        insert(q2, valArray2[i]);
    }

    // Finding frequency of each element
    for(int i = 0; i < M2; i++){
        int element = freqVal2[i]; // Elements after insertion
        int frequency = findFrequency(q2, element);
        cout << frequency << endl;
    }

    return 0;
}
