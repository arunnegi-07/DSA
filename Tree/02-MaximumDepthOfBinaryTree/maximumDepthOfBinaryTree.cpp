// TC : O(N)  SC : O(height of tree)

#include <iostream>
#include <algorithm>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to calculate the maximum depth of a binary tree
int maxDepth(Node* root) {
    // Base case: if root is null, return depth 0
    if (!root)
        return 0;
    
    // Recursive calls to calculate the maximum depth of the left and right subtrees
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    
    // Return the maximum depth among the left and right subtrees, plus 1 for the current node
    return max(leftDepth, rightDepth) + 1;
}

int main() {
    // Create the binary tree for sample input 1
    Node* root1 = new Node(1);
    root1->left = new Node(3);
    root1->right = new Node(2);
    root1->left->left = new Node(4);
    
    // Calculate and print the maximum depth of the binary tree for sample input 1
    cout << "Maximum depth of the binary tree (Sample Input 1): " << maxDepth(root1) << endl;
    
    // Create the binary tree for sample input 2
    Node* root2 = new Node(10);
    root2->left = new Node(20);
    root2->right = new Node(30);
    root2->left->right = new Node(40);
    root2->right->right = new Node(60);
    root2->right->right->left = new Node(2);
    
    // Calculate and print the maximum depth of the binary tree for sample input 2
    cout << "Maximum depth of the binary tree (Sample Input 2): " << maxDepth(root2) << endl;
    
    return 0;
}
