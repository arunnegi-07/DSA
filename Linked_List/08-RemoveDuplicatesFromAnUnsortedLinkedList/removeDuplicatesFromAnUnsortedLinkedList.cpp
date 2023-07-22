// TC : O(N)  SC : O(N)  --> used a HashMap to store frequencies

#include <iostream>
#include <unordered_map>
using namespace std;

// Definition of a Node in the linked list
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};
    
// Function to remove duplicates from an unsorted linked list
Node* removeDuplicates(Node* head) {
    // Create a frequency map to keep track of node data occurrences
    unordered_map<int, int> freq;
    
    // Create a new linked list to store the unique nodes (initialize with a dummy node)
    Node* ans = new Node(0); // The dummy node will be skipped in the result
    Node* tail = ans; // The tail will be used to append new unique nodes
    
    // Start traversing the original linked list
    Node* curr = head;
    while (curr != nullptr) {
        // Check if the current node's data value is a duplicate
        if (freq[curr->data] == 0) {
            // If it's the first occurrence of this data value, add it to the result list
            tail->next = curr;
            tail = tail->next;
        }
        
        // Increment the frequency count regardless of whether it's a duplicate or not
        freq[curr->data]++;
        
        // Move to the next node in the original linked list
        curr = curr->next;
    }
    
    // Terminate the result list by setting the tail's next pointer to nullptr
    tail->next = nullptr;
    
    // Return the result list (skip the dummy node by returning ans->next)
    return ans->next;
}


// Function to create a linked list from an array
Node* createLinkedList(int arr[], int n) {
    Node* head = nullptr;
    Node* tail = nullptr;
    
    for (int i = 0; i < n; i++) {
        Node* newNode = new Node(arr[i]);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    return head;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    // Sample input 1
    int arr1[] = {5, 2, 2, 4, 3, 2, 5, 6, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    Node* head1 = createLinkedList(arr1, n1);
    cout << "Original Linked List 1: ";
    printLinkedList(head1);
    
    Node* result1 = removeDuplicates(head1);
    cout << "Linked List 1 after removing duplicates: ";
    printLinkedList(result1);
    
    // Sample input 2
    int arr2[] = {1, 2, 3, 4, 4, 3, 2, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    Node* head2 = createLinkedList(arr2, n2);
    cout << "Original Linked List 2: ";
    printLinkedList(head2);
    
    Node* result2 = removeDuplicates(head2);
    cout << "Linked List 2 after removing duplicates: ";
    printLinkedList(result2);
    
    return 0;
}
