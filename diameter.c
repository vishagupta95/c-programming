#include <stdio.h>
#include <stdlib.h>

/*
Steps to Calculate the Diameter of a Binary Tree:
For each node, calculate:

The height of its left subtree.
The height of its right subtree.
The diameter through the node as left height + right height + 1 (where +1 counts the current node).
Recursively compute the diameter of the left and right subtrees.

The diameter of the tree is the maximum of:

The diameter of the left subtree.
The diameter of the right subtree.
The diameter passing through the current node.

Time Complexity: 
O(n), where 
n is the number of nodes in the tree. Each node is visited once.
Space Complexity: 
O(h), where 
ℎ
h is the height of the tree (due to recursion stack).

*/


// Define the structure for a tree node
struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* newNode(int value) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to calculate the height of the tree
int height(struct TreeNode* node) {
    if (node == NULL)
        return 0;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Helper function to calculate the diameter
int diameterHelper(struct TreeNode* node, int* diameter) {
    if (node == NULL)
        return 0;
    
    // Get the heights of the left and right subtrees
    int leftHeight = diameterHelper(node->left, diameter);
    int rightHeight = diameterHelper(node->right, diameter);
    
    // Update the diameter
    int currentDiameter = leftHeight + rightHeight;
    if (currentDiameter > *diameter)
        *diameter = currentDiameter;
    
    // Return the height of the current node
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Function to calculate the diameter of the tree
int diameterOfBinaryTree(struct TreeNode* root) {
    int diameter = 0;
    diameterHelper(root, &diameter);
    return diameter;
}

// Main function to test the code
int main() {
    // Constructing a simple binary tree
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Diameter of the tree: %d\n", diameterOfBinaryTree(root));
    return 0;
}

