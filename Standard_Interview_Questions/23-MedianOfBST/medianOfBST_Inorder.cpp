// Approach 1 : Using property of BST --> Inorder traversal is sorted order of Nodes.
// TC : O(N)  SC : O(N)

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Function to perform inorder traversal of the BST and store node values in a vector
void inOrder(Node* root, vector<int>& sortedNodes) {
    if (root == nullptr)
        return;

    inOrder(root->left, sortedNodes);
    sortedNodes.push_back(root->data);
    inOrder(root->right, sortedNodes);
}

// Function to find the median of the BST
float findMedian(Node* root) {
    if (root == nullptr) {
        return 0.0;  
    }

    vector<int> sortedNodes;
    
    inOrder(root, sortedNodes);  // Finding Sorted Order and storing in "sortedNodes"

    int size = sortedNodes.size();

    // If number of nodes is odd, return the middle element
    // If number of nodes is even, return the average of the two middle elements
    return size % 2 ? (sortedNodes[size / 2])  * 1.0 : ((sortedNodes[size / 2 - 1]) + (sortedNodes[size / 2]) * 0.5);
}

// Helper function to insert nodes into a BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

int main() {
    // Sample BST 1
    Node* root1 = nullptr;
    root1 = insert(root1, 6);
    root1 = insert(root1, 3);
    root1 = insert(root1, 8);
    root1 = insert(root1, 1);
    root1 = insert(root1, 4);
    root1 = insert(root1, 7);
    root1 = insert(root1, 9);

    cout << "Median of BST 1: " << findMedian(root1) << endl;

    // Sample BST 2
    Node* root2 = nullptr;
    root2 = insert(root2, 6);
    root2 = insert(root2, 3);
    root2 = insert(root2, 8);
    root2 = insert(root2, 1);
    root2 = insert(root2, 4);
    root2 = insert(root2, 7);

    cout << "Median of BST 2: " << findMedian(root2) << endl;

    return 0;
}
