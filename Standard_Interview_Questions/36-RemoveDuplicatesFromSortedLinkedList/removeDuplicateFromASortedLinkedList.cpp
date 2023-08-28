// TC  : O(N)  SC : O(1)

#include <iostream>

// Definition of a singly linked list node
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Function to remove duplicates from a sorted linked list
Node* removeDuplicates(Node* head) {
    // Create a dummy node to serve as the new head of the list
    Node* dummy = new Node(-1);
    Node* tail = dummy; // Initialize tail to the dummy node

    Node* ptr = head; // Initialize a pointer to traverse the original list
    while (ptr) {
        if (tail->data != ptr->data) {
            // If the current node's data is different from the tail's data,
            // add it to the new list and update the tail
            tail->next = ptr;
            tail = tail->next;
        }
        ptr = ptr->next; // Move to the next node in the original list
    }
    tail->next = nullptr; // Set the next of the last node to nullptr
    return dummy->next; // Return the new head of the deduplicated list
}

// Function to print a linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Sample input 1: 1 -> 1 -> 2 -> 3 -> 3
    Node* head1 = new Node(1);
    head1->next = new Node(1);
    head1->next->next = new Node(2);
    head1->next->next->next = new Node(3);
    head1->next->next->next->next = new Node(3);

    std::cout << "Original List 1: ";
    printList(head1);

    Node* deduplicated1 = removeDuplicates(head1);

    std::cout << "Deduplicated List 1: ";
    printList(deduplicated1);

    // Sample input 2: 1 -> 1 -> 1 -> 1 -> 1
    Node* head2 = new Node(1);
    head2->next = new Node(1);
    head2->next->next = new Node(1);
    head2->next->next->next = new Node(1);
    head2->next->next->next->next = new Node(1);

    std::cout << "Original List 2: ";
    printList(head2);

    Node* deduplicated2 = removeDuplicates(head2);

    std::cout << "Deduplicated List 2: ";
    printList(deduplicated2);

    return 0;
}
