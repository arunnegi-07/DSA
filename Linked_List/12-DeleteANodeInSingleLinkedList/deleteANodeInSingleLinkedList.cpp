// TC : O(N)  SC : O(1)

#include <iostream>

// Define the structure for a singly linked list node
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

// Function to delete the xth node from the linked list
ListNode* deleteNode(ListNode* head, int x) {
    // Special case: if x is 1, delete the head node
    if (x == 1) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // Traverse the list to find the (x-1)th node
    ListNode* prev = head;
    for (int i = 1; i < x - 1 && prev != nullptr; i++) {
        prev = prev->next;
    }

    // Check if x is out of bounds
    if (prev == nullptr || prev->next == nullptr) {
        return head; // x is greater than the length of the list
    }

    // Delete the xth node
    ListNode* temp = prev->next;
    prev->next = prev->next->next;
    delete temp;

    return head;
}

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Create a sample linked list: 1 -> 5 -> 2 -> 9
    ListNode* head = new ListNode(1);
    head->next = new ListNode(5);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(9);

    // Print the original linked list
    std::cout << "Original Linked List: ";
    printList(head);

    int x = 2; // Delete the 2nd node
    head = deleteNode(head, x);

    // Print the modified linked list
    std::cout << "Modified Linked List: ";
    printList(head);

    return 0;
}
