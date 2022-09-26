// C program to demonstrate insert operation in binary search tree 
#include<stdio.h> 
#include<stdlib.h> 
#include <limits.h>
#include <stdbool.h>

#define nullptr ((void*)0)

typedef struct node 
{ 
    int data; 
    struct node *left, *right; 
}Node;

void mirror_tree(Node* root) {
  
  if (root == NULL) {
    return;
  }

  // We will do a post-order traversal of the binary tree.

  if (root->left != nullptr) {
    mirror_tree(root->left);
  }

  if (root->right != nullptr) {
    mirror_tree(root->right);
  }

  // Let's swap the left and right nodes at current level.

  Node* temp = root->left;
  root->left = root->right;
  root->right = temp;
}

bool isBST(Node* node, int min, int max) {
    // Base case. An empty tree is a BST.
    if (node == NULL)
        return true;
    // Checking if a key is outside the permitted range.
    if (node -> data < min)
        return false;
  if (node -> data > max)
        return false;
    // Sending in updates ranges to the right and left subtree
    return isBST(node -> right, node -> data, max) &&  
  isBST(node -> left, min, node -> data);    
}



// A utility function to create a new BST node 
struct node *newNode(int item) 
{ 
    struct node *temp = (struct node *)malloc(sizeof(struct node)); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

// A utility function to do inorder traversal of BST 
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->data); 
        inorder(root->right); 
    } 
}

void search(Node *root, int data)
{
    if (root == NULL)
    {
        printf("data not found \n");
        return;
    }

    if (data == root->data)
    {
        printf("data found \n");
        return;
    }
    if (data < root->data)
    {
        search(root->left, data);
    }
    else
    {
        search(root->right, data);
    }
}

/* returns the total number of tree nodes */
int tnode_count(struct node *p)
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
 

/* A utility function to insert a new node with given data in BST */
struct node* insert(struct node* node, int data) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(data); 

    /* Otherwise, recur down the tree */
    if (data < node->data) 
        node->left = insert(node->left, data); 
    else if (data > node->data) 
        node->right = insert(node->right, data); 

    /* return the (unchanged) node pointer */
    return node; 
} 

// Driver Program to test above functions 
int main() 
{ 
    /* Let us create following BST 
            50 
        /    \ 
        30   70 
        / \ / \ 
    20 40 60 80 */
    struct node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 

    // print inoder traversal of the BST 
    inorder(root); 
    if(isBST(root, INT_MIN, INT_MAX)){
          printf("This binary tree is a BST.\n");
    } else {
          printf("This binary tree is not BST.\n");
    }
    return 0; 
} 

