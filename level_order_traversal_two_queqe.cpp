/*

METHOD 3: Using Two Queues
We can insert the first level in first queue and print it and while popping from the first queue
 insert its left and right nodes into the second queue. Now start printing the second queue and before popping insert its left and 
right child nodes into the first queue. Continue this process until both the queues become empty.


*/

#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *left, *right;  
};

// Utility Function to create new node of Binary Tree
Node *newNode( int data )
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// function to print level order using two Queues
void LevelOrder(Node* root)
{
    queue<Node *> q1, q2;
    
    if( root == NULL)
        return;     
    q1.push(root);        //Pushing first level node into first queue 
    
    // Executing loop till both the queues become empty
    
    while( !q1.empty() || !q2.empty() )
    {
        while( !q1.empty() )
        {
            //pushing left child of current node on first queue into second queue
            if(q1.front()-> right != NULL)
                q2.push(q1.front()-> left);
            
            //pushing right child of currrent node on first queue into second queue
            if(q1.front()-> right != NULL)
                q2.push(q1.front()-> right);
            
            cout<< q1.front()->data <<" ";
            q1.pop();
        }
        cout<< " \n ";
        
        while( !q2.empty() )
        {
             //pushing left child of current node in second queue into first queue
            if(q2.front()-> left != NULL)
                q1.push(q2.front()-> left);
            
            //pushing right child of current node in second queue into first queue
            if(q2.front()-> right != NULL)
                q1.push(q2.front()-> right);
            
            cout<< q2.front()->data << " ";
            q2.pop();        
        }
        cout << "\n";
    }  
}   

//driver function
int main() {
    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->right = newNode(6); 
  
    LevelOrder(root); 
    return 0; 
}
