
/*
Algorithm to find the diameter of a binary tree
Let, "root" be the root node of given binary tree.
If root is NULL, return 0.
Calculate of height of left and right sub tree. Let it be leftHeight and rightHeight.
The longest path which passes through root is leftHeight + rightHeight + 1.
Recursively calculate the diameter of left and right subtree. Let it be leftDiameter and rightDiameter.
Return maximum of leftDiameter, rightDiameter and leftHeight + rightHeight + 1.
Time Complexity : O(n2)

. A binary tree diameter equals the total number of nodes on the longest path between any two leaves in it

*/

#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int data;
    struct node *left;
    struct node *right;
};
 
struct node* getNewNode(int data) {
  /* dynamically allocate memory for a new node */
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  
  /* populate data in new Node */
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
   
  return newNode;
}
 
/*
This function returns below 
            1
           / \
         2    3
        / \  / \
       4  5 6  7
      /
     8
*/
struct node* generateBTree(){
    // Root Node
    struct node* root =  getNewNode(1);
    // Level 2 nodes 
    root->left = getNewNode(2);
    root->right = getNewNode(3);
    // Level 3 nodes
    root->left->left = getNewNode(4);
    root->left->right = getNewNode(5);
    root->right->left = getNewNode(6);
    root->right->right = getNewNode(7);
    // Level 4 nodes
    root->left->left->left = getNewNode(8);
     
    return root;
 
}
/* Returns maximum of two given numbers */
int getMax(int a, int b){
    if(a >= b)
        return a;
    else
        return b;
}
/*
Returns total number of nodes(size) in a bianry tree
getHeight(root) = Maximum of (getHeight(left-subTree), getHeight(right-subTree)) + 1;
*/
int getHeight(struct node *root){
    int leftHeight, rightHeight;
    if(root == NULL)
        return 0;
    leftHeight = getHeight(root->left);
    rightHeight = getHeight(root->right);
     
    return getMax(leftHeight, rightHeight) + 1;
}
 
/* Returns the diameter of a binary tree */
int getDiameter(struct node *nodePtr) {
   /* Empty Tree  */
   if (nodePtr == NULL)
     return 0;
 
  /* Calculate the heigh of the left and right sub-tree  */
  int leftHeight = getHeight(nodePtr->left);
  int rightHeight = getHeight(nodePtr->right);
 
  /* Recursively calculate the diameter of 
     left and right sub-trees */
  int leftDiameter = getDiameter(nodePtr->left);
  int rightDiameter = getDiameter(nodePtr->right);
 
  /* diameter of a tree is maximum of 
  (left sub-tree diameter),  (right sub-tree diameter), and 
  (height of left sub-tree + height of right sub-tree + 1)*/
  return getMax(leftHeight + rightHeight + 1, 
              getMax(leftDiameter, rightDiameter));
}
 
int main() {
    struct node *root = generateBTree();    
     
    printf("Diameter of Tree = %d", getDiameter(root));
     
    getchar();
    return 0; 
}
