#include <stdio.h>
#include <stdlib.h>

/*
1>The height of a binary tree is equal to the largest number of edges from the root to the most distant leaf node.
note: edge is a line which join 2 nodes so 2 nodes create 1 edge
2>A tree with only root node has height 0 
3>A tree with only  1 node has height 1 
4>tree with zero nodes would be considered as empty. An empty tree has height of -1.
5>left skewed binary tree shown  with 5 nodes has height 5
6)the height is h  is O(logn)
7) A binary tree node has data, pointer to left child and a pointer to right child */
/* Method 1 : recursion ,Time Complexity: O(n)  */
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a tree node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to find the maximum depth of the tree
int maxDepth(struct node* node) {
    if (node == NULL)
        return 0;
    else {
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
        return (lDepth > rDepth ? lDepth : rDepth) + 1;
    }
}

// Driver code
int main() {
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Maximum depth of the tree is: %d\n", maxDepth(root));
    return 0;
}

