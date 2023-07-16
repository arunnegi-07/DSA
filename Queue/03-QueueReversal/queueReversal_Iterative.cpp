// Approach 2 : Iterative Method 
// TC : O(N)  SC : O(N)

#include <iostream>
#include <queue>
using namespace std;

// Function to reverse the elements of a queue recursively
queue<int> rev(queue<int> q)
{
    stack<int> st;
        
    // step 1 : pop elements from queue and push into stack
    while(!q.empty()){
        int val = q.front();   
        st.push(val);
        q.pop();
    }
        
    // step 2 : popping from stack and pushing back into queue
    while(!st.empty()){
        int val = st.top();   
        q.push(val);
        st.pop();
    }
        
    return q;
}

// Function to reverse a queue and return the reversed queue
queue<int> rev(queue<int> q)
{
    reverseQueue(q);
    return q;
}

int main()
{
    queue<int> inputQueue;

    // Sample Input 1
    cout << "Sample Input 1:" << endl;
    inputQueue.push(1);
    inputQueue.push(2);
    inputQueue.push(3);
    inputQueue.push(4);
    
    queue<int> tempQueue = inputQueue;
    cout << "Original Queue: ";
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << " ";
        tempQueue.pop();
    }

    cout << endl;

    // Reverse the queue
    queue<int> reversedQueue = rev(inputQueue);

    cout << "Reversed Queue: ";
    while (!reversedQueue.empty()) {
        cout << reversedQueue.front() << " ";
        reversedQueue.pop();
    }

    cout << endl;

    // Sample Input 2
    cout << "Sample Input 2:" << endl;
    inputQueue.push(10);
    inputQueue.push(20);
    inputQueue.push(30);
    inputQueue.push(40);
    inputQueue.push(50);
    
    tempQueue = inputQueue;
    cout << "Original Queue: ";
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << " ";
        tempQueue.pop();
    }

    cout << endl;

    // Reverse the queue
    reversedQueue = rev(inputQueue);

    cout << "Reversed Queue: ";
    while (!reversedQueue.empty()) {
        cout << reversedQueue.front() << " ";
        reversedQueue.pop();
    }

    cout << endl;

    return 0;
}
