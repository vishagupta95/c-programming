include <stdio.h>
#include <stdlib.h>
 
// A Linked List Node
struct Node
{
    int data;
    struct Node* next;
};
 
// Helper function to print a given linked list
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d —> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}
 
// Helper function to insert a new node at the beginning of the linked list
void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
 
// Helper function to return a new node of the linked list
struct Node* newNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
 
// Function to insert a given node at its correct sorted position into
// a given list sorted in increasing order
void sortedInsert(struct Node** head, struct Node* newNode)
{
    // special case for the head end
    if (*head == NULL || (*head)->data >= newNode->data)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
 
    // locate the node before the point of insertion
    struct Node* current = *head;
    while (current->next != NULL && current->next->data < newNode->data) {
        current = current->next;
    }
 
    newNode->next = current->next;
    current->next = newNode;
}
 
int main(void)
{
    // input keys
    int keys[] = {2, 4, 6, 8};
    int n = sizeof(keys)/sizeof(keys[0]);
 
    // points to the head node of the linked list
    struct Node* head = NULL;
 
    // construct a linked list
    for (int i = n-1; i >= 0; i--) {
        push(&head, keys[i]);
    }
 
    sortedInsert(&head, newNode(5));
    sortedInsert(&head, newNode(9));
    sortedInsert(&head, newNode(1));
 
    // print linked list
    printList(head);
 
    return 0;
}

