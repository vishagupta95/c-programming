#include <stdio.h>
#include <stdlib.h>

/*
// Define stack node for `int`
typedef struct intStackNode {
    int data;                         // Node data is of type `int`
    struct intStackNode* next;        // Pointer to the next node
} intStackNode;

// Define stack structure for `int`
typedef struct {
    intStackNode* top;                // Pointer to the top of the stack
} intStack;

// Initialize stack
void initintStack(intStack* stack) {
    stack->top = NULL;                // Set the top pointer to NULL
}

// Push value onto the stack
void pushintStack(intStack* stack, int value) {
    intStackNode* newNode = (intStackNode*)malloc(sizeof(intStackNode));  // Allocate memory
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;           // Set the data of the new node
    newNode->next = stack->top;      // Link the new node to the current top
    stack->top = newNode;            // Update the top pointer
}

// Pop value from the stack
int popintStack(intStack* stack) {
    if (stack->top != NULL) {
        intStackNode* temp = stack->top;  // Store the top node
        stack->top = temp->next;         // Update the top pointer
        int data = temp->data;           // Extract the data
        free(temp);                      // Free the memory
        return data;                     // Return the data
    } else {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
}

*/

#define DECLARE_STACK_TYPE(type)                       \
    typedef struct type##StackNode {                   \
        type data;                                     \
        struct type##StackNode* next;                  \
    } type##StackNode;                                 \
                                                        \
    typedef struct {                                   \
        type##StackNode* top;                          \
    } type##Stack;                                     \
                                                        \
    void init##type##Stack(type##Stack* stack) {       \
        stack->top = NULL;                             \
    }                                                   \
                                                        \
    void push##type##Stack(type##Stack* stack, type value) { \
        type##StackNode* newNode = (type##StackNode*)malloc(sizeof(type##StackNode)); \
        if (newNode == NULL) {                         \
            fprintf(stderr, "Memory allocation failed\n"); \
            exit(EXIT_FAILURE);                        \
        }                                               \
        newNode->data = value;                         \
        newNode->next = stack->top;                    \
        stack->top = newNode;                          \
    }                                                   \
                                                        \
    type pop##type##Stack(type##Stack* stack) {        \
        if (stack->top != NULL) {                      \
            type##StackNode* temp = stack->top;        \
            stack->top = temp->next;                   \
            type data = temp->data;                    \
            free(temp);                                \
            return data;                               \
        } else {                                       \
            fprintf(stderr, "Stack underflow\n");      \
            exit(EXIT_FAILURE);                        \
        }                                               \
    }                                                   \

// Declare stack for `int` type
DECLARE_STACK_TYPE(int)

// Main function to test the stack
int main() {
    intStack stack;
    initintStack(&stack);

    // Push elements onto the stack
    pushintStack(&stack, 10);
    pushintStack(&stack, 20);
    pushintStack(&stack, 30);

    // Pop elements from the stack
    printf("Popped: %d\n", popintStack(&stack));  // Should print 30
    printf("Popped: %d\n", popintStack(&stack));  // Should print 20
    printf("Popped: %d\n", popintStack(&stack));  // Should print 10

    // Uncomment the following line to see the stack underflow error
    // printf("Popped: %d\n", popintStack(&stack));  // Will print "Stack underflow" and exit

    return 0;
}

