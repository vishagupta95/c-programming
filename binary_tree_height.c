#include <stdio.h>
#include <stdlib.h>

/*
1>Height of a node is the no of edges we travel between the root node and node , 
2>A tree with only root node has height 0 
3>A tree with only  2 node has height 1 
4>tree with zero nodes would be considered as empty. An empty tree has height of -1.
5>left skewed binary tree shown  with 5 nodes has height 5-1 = 4 

* A binary tree node has data, pointer to left child and a pointer to right child */

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}nodeX;

/* Method 1 : recursion ,Time Complexity: O(n)  */

/* Compute the "maxDepth" of a tree -- the number of
	nodes along the longest path from the root node
	down to the farthest leaf node.*/

int maxDepth(struct node* node) {
     
     if (node == NULL)
        return -1;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
     
        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}

 
/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct node* newnode(int data)
{
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}


int main()
{
	struct node* root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);

	printf("Height of regular  binary tree with max 3 levels is %d \n", maxDepth(root));

  
	struct node* root1 = newnode(1);
	root1->left = newnode(2);
	root1->left->left = newnode(3);
	root1->left->left->left = newnode(4);
	root1->left->left->left->left = newnode(5);
	root1->left->left->left->left->left = newnode(6);
	printf("Height of skewed binary tree with 6 nodes from level 0 root to level 5 is %d \n", maxDepth(root1));


	return 0;
}
