#include <stdio.h>
#include <stdlib.h>

/*
Height of a node is the no of edges we travel between the root node and node , 
A tree with only root node has height 0 
A tree with only  2 node has height 1 
and a tree with zero nodes would be considered as empty. An empty tree has height of -1.


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
	     return 0;
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

/* Method 2 : Iterative ,Time Complexity: O(n)  */
// Iterative function to calculate the height of a given binary tree
// by doing level order traversal on the tree
int height(Node* root)
{
    // empty tree has a height of 0
    if (root == nullptr) {
        return 0;
    }
 
    // create an empty queue and enqueue the root node
    list<Node*> queue;
    queue.push_back(root);
 
    Node* front = nullptr;
    int height = 0;
 
    // loop till queue is empty
    while (!queue.empty())
    {
        // calculate the total number of nodes at the current level
        int size = queue.size();
 
        // process each node of the current level and enqueue their
        // non-empty left and right child
        while (size--)
        {
            front = queue.front();
            queue.pop_front();
 
            if (front->left) {
                queue.push_back(front->left);
            }
 
            if (front->right) {
                queue.push_back(front->right);
            }
        }
 
        // increment height by 1 for each level
        height++;
    }
 
    return height;
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
