#include <stdio.h>
#include <stdlib.h>

/*
Height of a node is the no of edges we travel between the root node and node , 
while traveling in top down manner. Height of root node is 0.

Level of a binary tree start from root node with value 0 . Everytime we move from top side of the tree towards 
the bottom side we increase the level by one.

          10--- > level 0
      20          19   level 1
   5
1      6                level 3    ( height is 3
          
*/
//
//For example, left skewed binary tree shown   with 5 nodes has height 5-1 = 4 and binary tree shown in Figure 1(b) 
//with 5 nodes has height floor(log25) = 2.

/* A binary tree node has data, pointer to left child and a pointer to right child */

struct node {
	int data;
	struct node* left;
	struct node* right;
};

/* Method 1 : recursion ,Time Complexity: O(n)  */

/* Compute the "maxDepth" of a tree -- the number of
	nodes along the longest path from the root node
	down to the farthest leaf node.*/
int maxDepth(struct node* node)
{
	if (node == NULL)
	     return -1;
	else {
		/* compute the depth of each subtree */
		int lDepth = maxDepth(node->left);
		int rDepth = maxDepth(node->right);

		/* use the larger one */
		if (lDepth > rDepth)
			return (lDepth + 1);
		else
			return (rDepth + 1);
	}
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct node* newNode(int data)
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
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printf("Height of regular  binary tree with max 3 levels is %d \n", maxDepth(root));

  
	struct node* root1 = newNode(1);
	root1->left = newNode(2);
	root1->left->left = newNode(3);
	root1->left->left->left = newNode(4);
	root1->left->left->left->left = newNode(5);
	root1->left->left->left->left->left = newNode(6);
	printf("Height of skewed binary tree with 6 nodes from level 0 root to level 5 is %d \n", maxDepth(root1));


	return 0;
}
