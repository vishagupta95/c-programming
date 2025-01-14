// C program to demonstrate insert operation in binary search tree
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

/*

For balanced binary trees:

The height (h) is approximately O(log n), where n is the number of nodes.
Operations like insertion, deletion, and search are more efficient due to the logarithmic height, typically requiring O(log n) time.
For skewed binary trees:

The height (h) can approach n (the total number of nodes).
This results in linear time complexity (O(n)) for operations that depend on the tree's height, 
as the tree essentially behaves like a linked list in the worst-case scenario.

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

typedef struct node {
    int data;
    struct node *left, *right;
} Node;


// Function to create a new node
Node *newNode(int item) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to free the memory allocated for the tree
void freeTree(Node* root) {
    if (root == NULL)
        return;
    
    freeTree(root->left);
    freeTree(root->right);
    free(root);
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

// Function to print nodes at a specific level
void printLevel_OLD(Node* root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        printLevel_OLD(root->left, level - 1);
        printLevel_OLD(root->right, level - 1);
    }
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

void print_preorder(Node * tree)
{
    if (tree)
    {
        printf("%d\n",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

}

void print_inorderx(Node * tree)
{
    if (tree)
    {
        print_inorderx(tree->left);
        printf("%d\n",tree->data);
        print_inorderx(tree->right);
    }
}

/* returns the total number of tree nodes */
int tnode_count(Node *p)
{   
    if (p == NULL) 
        return 0;
    else    
    {
        if (p->left == NULL && p->right == NULL)
            return 1;
        else
            return (1 + (tnode_count(p->left) + tnode_count(p->right)));
    }
}   

void print_postorder(Node * tree)
{
    if (tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\n",tree->data);
    }
}

//insert 2d
void insertOther(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = (Node *)malloc(sizeof(Node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insertOther(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insertOther(&(*tree)->right, val);
    }

}

// Driver program to test the functions
int main() {
    Node *root = NULL;
    Node *root1 = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    insertOther(&root1, 9);
    insertOther(&root1, 10);
    insertOther(&root1, 15);
    insertOther(&root1, 6);
    insertOther(&root1, 12);
    insertOther(&root1, 17);
    insertOther(&root1, 2);

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

