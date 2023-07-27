// TC : O(N)  SC : O(N)


#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to return list containing elements of right view of binary tree.
vector<int> rightView(Node* root) {
    // Same code as provided earlier
    // ...
}

// Helper function to create a binary tree from a given array
Node* createBinaryTree(const vector<int>& arr, int index) {
    Node* newNode = nullptr;
    if (index < arr.size()) {
        if (arr[index] == -1) {
            // For a null node represented by -1 in the array
            return nullptr;
        }

        // Create a new node with the value from the array
        newNode = new Node(arr[index]);

        // Recursively create left and right subtrees
        newNode->left = createBinaryTree(arr, 2 * index + 1);
        newNode->right = createBinaryTree(arr, 2 * index + 2);
    }
    return newNode;
}

// Helper function to delete the binary tree after use to prevent memory leaks
void deleteBinaryTree(Node* root) {
    if (!root) {
        return;
    }
    deleteBinaryTree(root->left);
    deleteBinaryTree(root->right);
    delete root;
}

int main() {
    // Example usage
    vector<int> arr = {1, 2, 3, -1, 5, -1, 4};
    Node* root = createBinaryTree(arr, 0);

    vector<int> result = rightView(root);

    // Display the right view of the binary tree
    cout << "Right view of the binary tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Don't forget to delete the binary tree after use
    deleteBinaryTree(root);

    return 0;
}
