// TC : O(Height of the BST)   SC : O(Height of the BST)

#include <iostream>

// Structure for a node in the Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree
Node* LCA(Node* root, int n1, int n2)
{
    // If the current node's value is greater than both n1 and n2,
    // the LCA must be in the left subtree of the current node.
    if (root->data > n1 && root->data > n2) {
        return LCA(root->left, n1, n2);
    }
    // If the current node's value is less than both n1 and n2,
    // the LCA must be in the right subtree of the current node.
    else if (root->data < n1 && root->data < n2) {
        return LCA(root->right, n1, n2);
    }
    // If the current node's value is between n1 and n2 (inclusive),
    // then the current node is the LCA.
    else {
        return root;
    }
}

int main()
{
    // Create a Binary Search Tree
    //      10
    //     /   \
    //    5     15
    //   / \   /  \
    //  2   7 12  20
    Node* root = new Node{10, nullptr, nullptr};
    root->left = new Node{5, nullptr, nullptr};
    root->right = new Node{15, nullptr, nullptr};
    root->left->left = new Node{2, nullptr, nullptr};
    root->left->right = new Node{7, nullptr, nullptr};
    root->right->left = new Node{12, nullptr, nullptr};
    root->right->right = new Node{20, nullptr, nullptr};

    // Manually set n1 and n2 for testing the LCA function
    int n1 = 2, n2 = 12;

    // Find the Lowest Common Ancestor (LCA) of the given nodes
    Node* lcaNode = LCA(root, n1, n2);

    // Display the value of the LCA node
    std::cout << "Lowest Common Ancestor (LCA) of " << n1 << " and " << n2 << " is: " << lcaNode->data << std::endl;

    return 0;
}
