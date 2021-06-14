/*
First insert the root and a null element into the queue. This null element acts as a delimiter.
 Next pop from the top of the queue and add its left and right nodes to the end of the queue and 
then print the top of the queue. Continue this process till the queues become empty.
*/

// code goes here!
#include <iostream>
#include <queue>
using namespace std;

// node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;    
};

// Utility function to create new node to binary tree 

Node* newNode(int data)
{
    Node* temp = new Node;
    temp-> data =  data;
    temp-> left =  NULL;
    temp-> right=  NULL;
    return temp;
}

// LevelOrder using single Queue

void LevelOrderQ( Node* root)
{
    if(root == NULL)  return; 
    
    queue< Node * > q;              //create empty Queue
    
    q.push(root);                   //enqueue root
    
    while(q.empty() == false)
    {
        // Print front of queue and remove it from queue
        
        Node* node = q.front();
        cout<< node->data << " ";
        q.pop();
        
        //enqueue Left child
        
        if(node->left != NULL)
            q.push(node->left);
        
        //enqueue right child
        
        if(node->right != NULL)
            q.push(node->right);
    }
}

int main() {
    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
  
    cout << "Level Order traversal of binary tree is \n"; 
    LevelOrderQ(root); 
    return 0; 
}
