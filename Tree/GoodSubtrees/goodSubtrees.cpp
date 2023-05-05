#include <iostream>
#include <unordered_set>

using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

int ans; // variable to store the answer

// helper function that returns an unordered set containing the nodes of the subtree rooted at 'root'
// and also recursively calls itself on the left and right subtrees
// the parameter 'k' represents the threshold for the size of the subtree
unordered_set<int> help(Node* root, int k) {
    // base case: empty tree
    if (root == nullptr) return unordered_set<int>();

    // recursively call the helper function on the left and right subtrees
    unordered_set<int> l = help(root->left, k);
    unordered_set<int> r = help(root->right, k);

    // merge the sets of nodes from the left and right subtrees and add the root node
    unordered_set<int> total;
    for (auto x : l) total.insert(x);
    for (auto x : r) total.insert(x);
    total.insert(root->data);

    // if the size of the set of nodes in the subtree rooted at 'root' is less than or equal to 'k',
    // increment the answer variable
    if (total.size() <= k) ans++;

    // return the set of nodes in the subtree rooted at 'root'
    return total;
}

// function that counts the number of subtrees in the given binary tree whose size is less than or equal to 'k'
int goodSubtrees(Node* root, int k) {
    // initialize the answer variable to 0
    ans = 0;

    // call the helper function on the root node
    help(root, k);

    // return the final answer
    return ans;
}

int main() {
    // example 1
    /*
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
    */
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);
    int k1 = 3;
    cout << "Number of subtrees with size less than or equal to " << k1 << " in example 1: " << goodSubtrees(root1, k1) << endl;

    // example 2
    /*
             1
           /   \
          2     3
         / \     \
        4   5     6
             \
              7
    */
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->left->right->right = new Node(7);
    root2->right->right = new Node(6);
    int k2 = 4;
    cout << "Number of subtrees with size less than or equal to " << k2 << " in example 2: " << goodSubtrees(root2, k2) << endl;

    return 0;
}
