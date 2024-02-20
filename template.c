/*
 *
Creating something similar to C++ templates in C involves using void pointers and function pointers to achieve a form of genericity.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
    size_t element_size;
} Stack;

// Function to initialize the stack
void initStack(Stack* stack, size_t element_size) {
    stack->top = NULL;
    stack->element_size = element_size;
}

// Function to push an element onto the stack
void push(Stack* stack, const void* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = malloc(stack->element_size);
    if (newNode->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Copy the data to the newly allocated memory
    for (size_t i = 0; i < stack->element_size; ++i) {
        *((char*)newNode->data + i) = *((const char*)data + i);
    }

    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
void pop(Stack* stack) {
    if (stack->top != NULL) {
        Node* temp = stack->top;
        stack->top = temp->next;
        free(temp->data);
        free(temp);
    }
}

// Function to print the top element of the stack
void printTop(const Stack* stack, void (*print)(const void*)) {
    if (stack->top != NULL) {
        print(stack->top->data);
        printf("\n");
    } else {
        printf("Stack is empty\n");
    }
}

// Example print function for integers
void printInt(const void* data) {
    printf("%d", *(const int*)data);
}

// Example print function for doubles
void printDouble(const void* data) {
    printf("%f", *(const double*)data);
}

int main() {
    Stack intStack;
    initStack(&intStack, sizeof(int));

    int values[] = {1, 2, 3, 4, 5};
    for (size_t i = 0; i < sizeof(values) / sizeof(values[0]); ++i) {
        push(&intStack, &values[i]);
    }

    printf("Top of Int Stack: ");
    printTop(&intStack, printInt);

    // Pop an element from the stack
    pop(&intStack);

    printf("Top of Int Stack after pop: ");
    printTop(&intStack, printInt);

    Stack doubleStack;
    initStack(&doubleStack, sizeof(double));

    double valuesD[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    for (size_t i = 0; i < sizeof(valuesD) / sizeof(valuesD[0]); ++i) {
        push(&doubleStack, &valuesD[i]);
    }

    printf("Top of Double Stack: ");
    printTop(&doubleStack, printDouble);

    return 0;
}

#if 0 
#include <stdio.h>
#include <stdlib.h>

#define DECLARE_STACK_TYPE(type)                       \
    typedef struct type##StackNode {                   \
        type data;                                     \
        struct type##StackNode* next;                  \
    } type##StackNode;                                  \
                                                        \
    typedef struct {                                   \
        type##StackNode* top;                          \
    } type##Stack;                                      \
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
        stack->top = newNode;                           \
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
                                                        \
    void printTop##type##Stack(const type##Stack* stack) { \
        if (stack->top != NULL) {                      \
            printf("%d\n", stack->top->data);          \
        } else {                                       \
            printf("Stack is empty\n");                \
        }                                               \
    }

DECLARE_STACK_TYPE(int);
DECLARE_STACK_TYPE(double);
DECLARE_STACK_TYPE(char);

int mainx() {
    intStack int_stack;
    initIntStack(&int_stack);
    pushIntStack(&int_stack, 42);
    pushIntStack(&int_stack, 23);
    printTopIntStack(&int_stack);
    int popped_int = popIntStack(&int_stack);
    printf("Popped Int: %d\n", popped_int);
    printTopIntStack(&int_stack);

    doubleStack double_stack;
    initDoubleStack(&double_stack);
    pushDoubleStack(&double_stack, 3.14);
    pushDoubleStack(&double_stack, 2.71);
    printTopDoubleStack(&double_stack);
    double popped_double = popDoubleStack(&double_stack);
    printf("Popped Double: %f\n", popped_double);
    printTopDoubleStack(&double_stack);

    charStack char_stack;
    initCharStack(&char_stack);
    pushCharStack(&char_stack, 'A');
    pushCharStack(&char_stack, 'B');
    printTopCharStack(&char_stack);
    char popped_char = popCharStack(&char_stack);
    printf("Popped Char: %c\n", popped_char);
    printTopCharStack(&char_stack);

    return 0;
}
#endif
