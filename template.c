#include <stdio.h>
#include <stdlib.h>

/*
typedef struct intStackNode {
    int data;
    struct intStackNode* next;
} intStackNode;

typedef struct {
    intStackNode* top;
} intStack;

void initintStack(intStack* stack) {
    stack->top = NULL;
}

void pushintStack(intStack* stack, int value) {
    intStackNode* newNode = (intStackNode*)malloc(sizeof(intStackNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
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

