// Approach 2 : TC : O(Height of BST)  SC : O(Height of BST)  --> in Worst Case 
// Now, you can see we have added those conditional checks by taking advantage of property BST and 
// reducing unnessary traversals, while in case of Approach 1 even though we know the value on left or right
// will never give us the "minimum absolute difference" still we are traversing on that side.

#include <bits/stdc++.h>
using namespace std;

// Node structure for the Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to find the least absolute difference between any node
// value of the BST and the given integer.
void helper(Node* root, int K, int& ans) {

    // Base case: reached the leaf node or empty tree
    if (root == NULL)
        return;
    
    // Update the minimum difference if the current node's value
    // is closer to the given integer than the previous minimum
    ans = min(ans,abs(root->data - K));
        
    // by adding these conditional checks we can reduce the number of unnecessary traversals
    // as it is a BST we are getting this advantage
    if (root->data > K)
        // Traverse the left subtree
        helper(root->left, K, ans);
    else if (root->data < K)
        // Traverse the right subtree
        helper(root->right, K, ans);
}

// Function to calculate the minimum difference between BST node values and K
int minDiff(Node* root, int K) {
    int ans = INT_MAX;
    helper(root, K, ans);
    return ans;
}

// Main function to test the code
int main() {
    // Create a sample BST
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    // Sample input 1: Find the minimum difference between BST node values and K=5
    int minDiff1 = minDiff(root, 5);
    cout << "Minimum difference: " << minDiff1 << endl;

    // Sample input 2: Find the minimum difference between BST node values and K=3
    int minDiff2 = minDiff(root, 3);
    cout << "Minimum difference: " << minDiff2 << endl;

    // Clean up the memory (optional)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
