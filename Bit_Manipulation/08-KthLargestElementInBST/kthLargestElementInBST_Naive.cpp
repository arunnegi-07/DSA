// Naive Approach --> Taking extra O(N) space to store Inorder Traversal
// TC : O(N)  SC : O(N) + O(H) --> stack space

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Function to perform an inorder traversal of a binary search tree (BST)
// and store the elements in the 'inorder' vector in ascending order.
void inorderTraversal(Node *root, vector<int> &inorder) {
    // Base case: If the root is NULL, return (no node to process).
    if (root == NULL)
        return;

    // Recursively traverse the left subtree.
    inorderTraversal(root->left, inorder);

    // Store the current node's data in the 'inorder' vector.
    inorder.push_back(root->data);

    // Recursively traverse the right subtree.
    inorderTraversal(root->right, inorder);
}

// Function to find the Kth largest element in a BST.
int kthLargest(Node *root, int K) {
    // Create an empty vector to store elements in ascending order.
    vector<int> inorder;

    // Perform an inorder traversal of the BST to populate the 'inorder' vector.
    inorderTraversal(root, inorder);

    // Check if K is greater than the number of elements in the BST.
    if (K > inorder.size()) {
        return -1; // Kth largest doesn't exist in this BST.
    } else {
        // Calculate the index of the Kth largest element in the 'inorder' vector.
        int index = inorder.size() - K;

        // Return the Kth largest element.
        return inorder[index];
    }
}


int main() {
    // Example 1
    Node* root1 = new Node(4);
    root1->left = new Node(2);
    root1->right = new Node(9);
    int k1 = 2;
 
    cout << "Example 1: Kth largest = " << kthLargest(root1, k1) << endl;

    // Example 2
    Node* root2 = new Node(9);
    root2->right = new Node(10);
    int k2 = 1;

    cout << "Example 2: Kth largest = " << kthLargest(root2, k2) << endl;

    return 0;
}
