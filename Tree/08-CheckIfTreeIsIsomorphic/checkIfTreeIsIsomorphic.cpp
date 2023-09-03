// TC : O(min(M, N)),  where M and N are the sizes of the two trees.
// TC : O(min(H1, H2)),  where H1 and H2 are the heights of the two trees.

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to check if two binary trees are isomorphic
bool isIsomorphic(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2) {
        return true; // Both trees are empty, so they are isomorphic
    }
    if (!root1 || !root2) {
        return false; // One tree is empty while the other is not, so they are not isomorphic
    }
    
    // Check if the current nodes have the same value
    if (root1->val != root2->val) {
        return false;
    }
    
    // Check for isomorphism recursively
    // There are two possibilities for isomorphism:
    // 1. The left subtrees of both trees are isomorphic, and the right subtrees are isomorphic.
    // 2. The left subtrees of both trees are isomorphic, and the right subtrees after flipping are isomorphic.
    return (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right)) ||
           (isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left));
}

int main() {
    // Create the first tree
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    
    // Create the second tree
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(2);
    root2->right->left = new TreeNode(4);
    
    if (isIsomorphic(root1, root2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}
