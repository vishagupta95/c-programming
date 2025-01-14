#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char* data;  // Stores a string
    struct Node* next;
};

// Function declarations
void insert_at_begin(struct Node** head, const char* data);
void insert_at_end(struct Node** head, const char* data);
void delete_from_begin(struct Node** head);
void delete_from_end(struct Node** head);
void display(struct Node* head);
void reverse(struct Node** head);
void merge(struct Node* first, struct Node* second, struct Node** merged);
void sorted_insert(struct Node** head, struct Node* newNode);
struct Node* new_node(const char* data);
char* strdup_custom(const char* str);  // Custom strdup function

// Main function
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* merged_list = NULL;

    // Predefined array of strings
    const char* data_list1[] = {"Apple", "Banana", "Grape", "Cherry", "Mango"};
    const char* data_list2[] = {"Pineapple", "Peach", "Plum"};

    // Insert strings from predefined arrays into list1
    for (int i = 0; i < sizeof(data_list1) / sizeof(data_list1[0]); i++) {
        insert_at_end(&list1, data_list1[i]);
    }

    // Insert strings from predefined arrays into list2
    for (int i = 0; i < sizeof(data_list2) / sizeof(data_list2[0]); i++) {
        insert_at_end(&list2, data_list2[i]);
    }

    // Display the original lists
    printf("List 1: ");
    display(list1);
    printf("List 2: ");
    display(list2);

    // Merge the two lists
    merge(list1, list2, &merged_list);
    printf("Merged list: ");
    display(merged_list);

    // Sort the merged list
    printf("Sorted merged list: ");
    struct Node* sorted_merged_list = NULL;
    struct Node* current = merged_list;
    while (current != NULL) {
        struct Node* newNode = new_node(current->data);
        sorted_insert(&sorted_merged_list, newNode);
        current = current->next;
    }
    display(sorted_merged_list);

    return 0;
}

// Function to create a new node
struct Node* new_node(const char* data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = strdup_custom(data);  // Use custom strdup function
    temp->next = NULL;
    return temp;
}

// Custom strdup function to duplicate a string
char* strdup_custom(const char* str) {
    size_t len = strlen(str) + 1;  // +1 for the null terminator
    char* copy = (char*)malloc(len);
    if (copy) {
        memcpy(copy, str, len);  // Copy the string into the new memory
    }
    return copy;
}

// Insert at the beginning
void insert_at_begin(struct Node** head, const char* data) {
    struct Node* temp = new_node(data);
    temp->next = *head;
    *head = temp;
}

// Insert at the end
void insert_at_end(struct Node** head, const char* data) {
    struct Node* temp = new_node(data);
    if (*head == NULL) {
        *head = temp;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
}

// Delete from the beginning
void delete_from_begin(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp->data);  // Free the string memory
    free(temp);
    printf("Deleted from the beginning\n");
}

// Delete from the end
void delete_from_end(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {  // Only one node in the list
        *head = NULL;
    } else {
        prev->next = NULL;
    }

    free(current->data);  // Free the string memory
    free(current);
    printf("Deleted from the end\n");
}

// Display the list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Reverse the list
void reverse(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Merge two lists
void merge(struct Node* first, struct Node* second, struct Node** merged) {
    struct Node* temp = NULL;

    // If one of the lists is empty, return the other list
    if (first == NULL) {
        *merged = second;
        return;
    } else if (second == NULL) {
        *merged = first;
        return;
    }

    // Set the merged list's head
    if (strcmp(first->data, second->data) <= 0) {
        *merged = first;
        first = first->next;
    } else {
        *merged = second;
        second = second->next;
    }

    temp = *merged;
    while (first != NULL && second != NULL) {
        if (strcmp(first->data, second->data) <= 0) {
            temp->next = first;
            first = first->next;
        } else {
            temp->next = second;
            second = second->next;
        }
        temp = temp->next;
    }

    // Attach the remaining nodes
    if (first != NULL) {
        temp->next = first;
    } else {
        temp->next = second;
    }
}

// Insert a node into a sorted list
void sorted_insert(struct Node** head, struct Node* newNode) {
    // Special case for the head end
    if (*head == NULL || strcmp((*head)->data, newNode->data) >= 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Locate the node before the point of insertion
    struct Node* current = *head;
    while (current->next != NULL && strcmp(current->next->data, newNode->data) < 0) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

