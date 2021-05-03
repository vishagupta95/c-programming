#include <stdio.h>
#include <stdlib.h>  /* malloc */
#include <strings.h> /* bcopy  */

typedef struct Stack Stack;
struct Stack
{
    int counter;
    int max;
    void **container;
};

Stack *newStack(int size)
{
    /* NYI: better error checks */
    if (size < 5)
    {
        size = 5;
    }

    Stack *stack = malloc(sizeof(Stack));
    stack->container = malloc(sizeof(void **) * size);

    stack->counter = 0;
    stack->max = size;
    return stack;
}

void freeStack(Stack *stack)
{
    free(stack->container);
    free(stack);
}

int getSize(Stack *stack)
{
    return stack->counter;
}

int getMax(Stack *stack)
{
    return stack->max;
}

int isEmpty(Stack *stack)
{
    if (stack->counter == 0)
        return 1;
    return 0;
}

void **resizeContainer(Stack *stack)
{
    /* NYI: error checks */
    void **tmpContainer = malloc(sizeof(void **) * stack->max * 2);
    bcopy(stack->container, tmpContainer, sizeof(void **) * stack->max);
    stack->max *= 2;
    return tmpContainer;
}

void trace(Stack *stack)
{
    int i;
    for (i = stack->counter - 1; i >= 0; i--)
        printf("%d: %p \n", i, stack->container[i]);
}

int search(void *value, Stack *stack)
{
    int i;
    for (i = stack->counter - 1; i >= 0; i--)
    {
        if (stack->container[i] == value)
            return i;
    }
    return -1;
}

void *peek(Stack *stack)
{
    if (stack->counter > 0)
    {
        return stack->container[stack->counter - 1];
    }
    fprintf(stderr, "stack counter is 0... can't peek an empty stack.");
    return NULL;
}

void push(void *item, Stack *stack)
{
    if (stack->counter == stack->max)
        stack->container = resizeContainer(stack);

    stack->container[stack->counter] = item;
    stack->counter++;
}

void *pop(Stack *stack)
{
    if (stack->counter > 0)
    {
        stack->counter--;
        return stack->container[stack->counter];
    }
    fprintf(stderr, "stack counter is 0... can't pop an empty stack.");
    return NULL;
}

int main(void)
{
    Stack *intStack = newStack(10);

    int x = 100, y = 200, z = 300;

    if (isEmpty(intStack))
    {
        printf("The stack is empty.\n");
    }
    else
    {
        printf("The stack is not empty.\n");
    }

    push(&x, intStack);
    push(&y, intStack);
    push(&z, intStack);

    if (isEmpty(intStack))
    {
        printf("The stack is empty.\n");
    }
    else
    {
        printf("The stack is not empty.\n");
    }

    trace(intStack);

    printf("\nPopping %d\n", *(int *)pop(intStack));
    printf("\nPopping %d\n", *(int *)pop(intStack));
    printf("\nPopping %d\n", *(int *)pop(intStack));

    Stack *stringStack = newStack(4);

    char *hello = "Hello world!";
    char *goodbye = "Goodbye cruel world!";
    push(hello, stringStack);
    push(goodbye, stringStack);
    printf("We popped: %s\n", (char *)pop(stringStack));
    printf("We popped: %s\n", (char *)pop(stringStack));

    freeStack(intStack);
    freeStack(stringStack);
    return 0;
}
