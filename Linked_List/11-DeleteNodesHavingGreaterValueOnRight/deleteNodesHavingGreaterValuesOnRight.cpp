// TC : O(N)  SC : O(1)
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) : data(data), next(NULL) {}
};

Node* reverseLinkedList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

Node* compute(Node* head) {
    // Step 1: Reverse the linked list
    head = reverseLinkedList(head);

    // Initialize two pointers: current and maxNode, both initially at the head
    Node* current = head;
    Node* maxNode = head;

    while (current != NULL && current->next != NULL) {
        // Step 2: Compare the value of the next node with the maxNode
        if (current->next->data < maxNode->data) {
            // If the next node has a smaller value, remove it by updating the next pointer
            current->next = current->next->next;
        } else {
            // If the next node has a larger or equal value, update maxNode and move to the next node
            current = current->next;
            maxNode = current;
        }
    }

    // Step 3: Reverse the linked list again to restore the original order
    head = reverseLinkedList(head);
    return head;
}


// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Example 1
    Node* head1 = new Node(12);
    head1->next = new Node(15);
    head1->next->next = new Node(10);
    head1->next->next->next = new Node(11);
    head1->next->next->next->next = new Node(5);
    head1->next->next->next->next->next = new Node(6);
    head1->next->next->next->next->next->next = new Node(2);
    head1->next->next->next->next->next->next->next = new Node(3);

    Node* result1 = compute(head1);
    cout << "Output 1: "; printList(result1);  // Output: 15 11 6 3

    // Example 2
    Node* head2 = new Node(10);
    head2->next = new Node(20);
    head2->next->next = new Node(30);
    head2->next->next->next = new Node(40);
    head2->next->next->next->next = new Node(50);
    head2->next->next->next->next->next = new Node(60);

    Node* result2 = compute(head2);
     cout << "Output 2: "; printList(result2);  // Output: 60

    return 0;
}
