// TC : O(N)  SC : O(1)

#include <iostream>

struct Node {
    int data;
    Node* next;
};

int getNthFromLast(Node* head, int n) {
    // Step 1: Find length of the given Linked list
    Node* ptr = head;
    int len = 0;

    while (ptr != nullptr) {
        len++;
        ptr = ptr->next;
    }

    // Step 2: Finding position of the actual Node from the start
    int pos = len - n;

    // Case to handle if the given position from the end is not possible
    if (pos < 0)
        return -1;

    // Step 3: Traversing and returning the actual Node
    ptr = head;

    while (pos--) {
        ptr = ptr->next;
    }

    // Finally, returning the answer
    return ptr->data;
}

int main() {
    // Sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node{1, nullptr};
    Node* second = new Node{2, nullptr};
    Node* third = new Node{3, nullptr};
    Node* fourth = new Node{4, nullptr};
    Node* fifth = new Node{5, nullptr};

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    int n1 = 2;
    int n2 = 4;

    int result1 = getNthFromLast(head, n1);
    int result2 = getNthFromLast(head, n2);

    std::cout << "Result 1: " << result1 << std::endl;
    std::cout << "Result 2: " << result2 << std::endl;

    // Clean up the memory
    delete fifth;
    delete fourth;
    delete third;
    delete second;
    delete head;

    return 0;
}
