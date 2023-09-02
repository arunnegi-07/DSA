// TC : O(N)  SC : O(N)

#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

// Function to count the maximum number of leaf nodes that can be visited within the given budget.
int getCount(Node* root, int budget) {
    if (!root) {
        return 0; // If the tree is empty, there are no leaf nodes to visit.
    }
    
    queue<pair<Node*, int>> q;
    q.push({root, 1}); // Start from the root at level 1
    int count = 0; // Initialize the count of visited leaf nodes to 0
    
    while (!q.empty()) {
        Node* node = q.front().first; // Get the current node from the queue
        int level = q.front().second; // Get the level of the current node
        q.pop();
        
        // If the current node is a leaf node, check if the budget allows visiting it.
        if (!node->left && !node->right) {
            if (budget >= level) {
                count++; // Increment the count of visited leaf nodes
                budget -= level; // Decrement the budget by the level of the leaf node visited
            } else {
                break; // If the budget is not sufficient, stop visiting further leaf nodes.
            }
        }
        
        // Enqueue child nodes with their respective levels.
        if (node->left) {
            q.push({node->left, level + 1}); // Enqueue the left child with an increased level.
        }
        if (node->right) {
            q.push({node->right, level + 1}); // Enqueue the right child with an increased level.
        }
    }
    
    return count; // Return the count of visited leaf nodes.
}

int main() {
    // Example 1:
    Node* root1 = new Node(10);
    root1->left = new Node(8);
    root1->right = new Node(2);
    root1->left->left = new Node(3);
    root1->right->left = new Node(3);
    root1->right->right = new Node(6);
    root1->right->left->right = new Node(4);

    int budget1 = 8;
    cout << "Output 1: " << getCount(root1, budget1) << " visited leaf nodes" << endl; // Output: 2

    // Example 2:
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->right->left = new Node(6);
    root2->right->right = new Node(7);

    int budget2 = 5;
    cout << "Output 2: " << getCount(root2, budget2) << " visited leaf nodes" << endl; // Output: 1

    return 0;
}
