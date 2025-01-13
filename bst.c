// C program to demonstrate insert operation in binary search tree
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

/*
Time Complexity for Important Binary Tree Functions:
1. Height of Binary Tree: O(n), where n is the number of nodes.
2. Level Order Traversal: O(n), where n is the number of nodes.
3. In-order Traversal: O(n), where n is the number of nodes.
4. Insert in Binary Search Tree: O(h), where h is the height of the tree.
5. Check if Tree is BST: O(n), where n is the number of nodes.
6. Mirror Binary Tree: O(n), where n is the number of nodes.
7. Count Total Nodes: O(n), where n is the number of nodes.

in-order traversal of a Binary Search Tree (BST) produces the elements in sorted order.

BST node deletion
Base Case: If the root is NULL, return NULL.
Traverse: Move left or right depending on the key comparison.
Deletion Cases:
Node with no child: Directly remove the node.
Node with one child: Replace the node with its child.
Node with two children: Replace the node with its in-order successor, then delete the successor node.
In-order Traversal: Used to verify the correctness of the BST after deletio
*/

// Function to create a new node
Node *newNode(int item) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to calculate the height of the binary tree
int height(Node *node) {
    if (node == NULL)
        return 0;
    int left_height = height(node->left);
    int right_height = height(node->right);
    return 1 + (left_height > right_height ? left_height : right_height);
}

// Function to perform level-order traversal using a queue
void levelOrder(Node *root) {
    if (root == NULL) {
        return;
    }

    // Queue to hold nodes at each level
    Node **queue = (Node **)malloc(100 * sizeof(Node *)); // Assuming max 100 nodes
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node *current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }

        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }

    free(queue);
    printf("\n");
}

// Function to perform in-order traversal
void inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d \n", root->data);
        inOrder(root->right);
    }
}

// Find the minimum value node in the right subtree
Node* findMin(Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Delete a node from the BST
Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root; // Tree is empty
    }

    // Traverse the tree
    if (key < root->data) {
        root->left = deleteNode(root->left, key); // Key is in the left subtree
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key); // Key is in the right subtree
    } else {
        // Found the node to delete
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the in-order successor (smallest in the right subtree)
        Node* temp = findMin(root->right);

        // Replace the current node's data with the in-order successor's data
        root->data = temp->data;

        // Delete the in-order successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}


// Function to insert a new node with given data in BST
Node *insert(Node *node, int data) {
    if (node == NULL) 
        return newNode(data);

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }

    return node;
}

// Function to check if a binary tree is a BST
bool isBST(Node *node, int min, int max) {
    if (node == NULL)
        return true;

    if (node->data < min || node->data > max)
        return false;

    return isBST(node->left, min, node->data) && isBST(node->right, node->data, max);
}

// Function to mirror a binary tree
void mirror_tree(Node *root) {
    if (root == NULL) {
        return;
    }

    mirror_tree(root->left);
    mirror_tree(root->right);

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

// Function to count total nodes in the binary tree
int tnode_count(Node *node) {
    if (node == NULL)
        return 0;
    return 1 + tnode_count(node->left) + tnode_count(node->right);
}

// Function to calculate the maximum of two numbers
int max(int a, int b) {
    return (a >= b) ? a : b;
}

// a time complexity of diamater is O(n)2 recursson  
// because the height function is called repeatedly.
// Function to calculate the diameter of the tree
int diameter(Node* node) {
    if (node == NULL) {
        return 0;
    }

    // Height of left and right subtrees
    int lheight = height(node->left);
    int rheight = height(node->right);

    // Diameter of left and right subtrees
    int ldiameter = diameter(node->left);
    int rdiameter = diameter(node->right);

    // Return the maximum of:
    // 1. Diameter through the current node
    // 2. Left diameter
    // 3. Right diameter
    return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}


// Driver program to test the functions
int main() {
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("In-order traversal:\n");
    inOrder(root);

    printf("\nLevel-order traversal:\n");
    levelOrder(root);

    printf("\nHeight of the binary tree: %d\n", height(root));
    printf("Diameter of the tree: %d\n", diameter(root));
 
    if (isBST(root, INT_MIN, INT_MAX)) {
        printf("This binary tree is a BST.\n");
    } else {
        printf("This binary tree is not a BST.\n");
    }

    printf("Total number of nodes: %d\n", tnode_count(root));

     // Delete nodes
    root = deleteNode(root, 20);
    printf("In-order traversal after deleting 20: ");
    inOrder(root);
    printf("\n");

    root = deleteNode(root, 30);
    printf("In-order traversal after deleting 30: ");
    inOrder(root);
    printf("\n");

    root = deleteNode(root, 50);
    printf("In-order traversal after deleting 50: ");
    inOrder(root);
    printf("\n");

    return 0;
}

