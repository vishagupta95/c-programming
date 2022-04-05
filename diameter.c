
/*
 *                   4
 *             7          8
 *                     1     0
 *                  3          
 *
 * Longest Path available is 7 - 4 - 8 - 1 - 3 of length 4
 *
 * Recursion method
 *
 *The depth of a node is the number of edges present in path from the root node of a tree to that node.
 * The height of a node is the number of edges present in the longest path connecting that node to a leaf node
 *
 * Calculate of height of left and right sub tree. Let it be leftHeight and rightHeight.
 * The longest path which passes through root is leftHeight + rightHeight + 1.
 * Recursively calculate the diameter of left and right subtree. Let it be leftDiameter and rightDiameter.
 * Return maximum of leftDiameter, rightDiameter and leftHeight + rightHeight + 1.
 * Time Complexity : O(n2)
    But it occupies stack space in memory and can be harder to debug because of the recursion involved.
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


/* Solution 2 Post Order Traversal

e use stacks to perform a post order traversal of the binary tree. A hash-map can be used to maintain the maximum depth at each of the nodes in the tree.

Code:
  public int diameterOfBinaryTree(TreeNode root) {

    Map<TreeNode, Integer> map = new HashMap<>();
    Stack<TreeNode> stack = new Stack<>();
    int diameter = 0;

    if (root != null)
      stack.push(root);

    while (!stack.isEmpty()) {
      TreeNode node = stack.peek();

      // Fill up stack to perform post-order traversal
      if (node.left != null && !map.containsKey(node.left)) {
        stack.push(node.left);
      } else if (node.right != null && !map.containsKey(node.right)) {
        stack.push(node.right);
      } else {

        // Process the root, once left and right sub-tree have been processed
        stack.pop();
        int leftDepth = map.getOrDefault(node.left, 0);
        int rightDepth = map.getOrDefault(node.right, 0);

        // Put the max depth at a node in the map
        map.put(node, 1 + Math.max(leftDepth, rightDepth));

        // Update the max diameter found so far
        diameter = Math.max(diameter, leftDepth + rightDepth);
      }
    }
    return diameter;
  }
Code language: Java (java)
Time Complexity: O(n)O(n)
Space Complexity: O(n)O(n)

*/
