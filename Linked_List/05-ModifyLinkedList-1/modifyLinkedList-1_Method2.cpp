// TC : O(N)  SC : O(N) --> Taking extra array space

#include <iostream>
#include <vector>

struct Node {
    int data;
    Node* next;
};

int getNthFromLast(Node* head, int n) {
    // Step 1: Traverse the linked list and store elements in a vector
    std::vector<int> elements;
    Node* ptr = head;

    while (ptr != nullptr) {
        elements.push_back(ptr->data);
        ptr = ptr->next;
    }

    // Step 2: Calculate the position of the desired node from the end
    int pos = elements.size() - n;

    // Case to handle if the given position from the end is not possible
    if (pos < 0)
        return -1;

    // Step 3: Retrieve the actual node value from the vector
    return elements[pos];
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
