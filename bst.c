// C program to demonstrate insert operation in binary search tree 
#include<stdio.h> 
#include<stdlib.h> 

typedef struct node 
{ 
    int key; 
    struct node *left, *right; 
}Node;

/ Returns true if given tree is BST. 
bool isBST(Node* root, Node* l=NULL, Node* r=NULL) 
{ 
    // Base condition 
    if (root == NULL)
        return true;
    
    // if left node exist then check it has 
    // correct data or not i.e. left node's data 
    // should be less than root's data 
    if (l != NULL and root->data <= l->data)
        return false;
    
    // if right node exist then check it has 
    // correct data or not i.e. right node's data 
    // should be greater than root's data 
    if (r != NULL and root->data >= r->data)
        return false;
    
    // check recursively for every node.  
    return isBST(root->left, l, root) and
        isBST(root->right, root, r);
} 

// A utility function to create a new BST node 
struct node *newNode(int item) 
{ 
    struct node *temp = (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

// A utility function to do inorder traversal of BST 
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->key); 
        inorder(root->right); 
    } 
}

void search(NODE *root, int key)
{
    if (root == NULL)
    {
        printf("data not found \n");
        return;
    }

    if (key == root->data)
    {
        printf("data found \n");
        return;
    }
    if (key < root->data)
    {
        search(root->left, key);
    }
    else
    {
        search(root->right, key);
    }
}

* returns the total number of tree nodes */
int tnode_count(struct tnode *p)
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
 

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 

    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key); 

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

    return 0; 
} 

