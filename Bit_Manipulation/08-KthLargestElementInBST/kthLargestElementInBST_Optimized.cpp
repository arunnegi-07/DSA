// Optimized Approach --> Not taking extra space, calculating result while inorder traversal
// TC : O(N)  SC : O(H) --> stack space

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Utility function to find the Kth largest element in a Binary Search Tree (BST).
// This function performs a reverse in-order traversal to find the Kth largest element.
void kthLargestUtil(Node* root, int k, int& count, int& result) {
    // Base case: If the current node is NULL or the Kth largest element is found,
    // return without further processing.
    if (!root || count >= k) {
        return;
    }

    // Traverse the right subtree first (reverse in-order traversal).
    kthLargestUtil(root->right, k, count, result);

    // Increment the count to keep track of the number of nodes visited.
    count++;

    // Check if the current node is the Kth largest element.
    if (count == k) {
        result = root->data; // Store the Kth largest element in the 'result' variable.
        return; // Return to stop further processing.
    }

    // Continue with the left subtree.
    kthLargestUtil(root->left, k, count, result);
}

// Function to find the Kth largest element in a BST.
int kthLargest(Node* root, int k) {
    int count = 0; // Initialize a counter to keep track of nodes visited.
    int result = -1; // Initialize the result variable.
    
    // Call the utility function to find the Kth largest element.
    kthLargestUtil(root, k, count, result);

    return result; // Return the Kth largest element found.
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
