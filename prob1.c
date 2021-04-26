#include <stdio.h>
#include <stdlib.h>

typedef struct _list_item
{
    int value;
    struct _list_item *next;
} list_item;

void print_list(list_item *root) //function to print linked list
{
    list_item *lp = root;
    while (lp)
    {
        printf("%d  ", lp->value);
        lp = lp->next;
    }
}

//function to insert data in Inordered list
void add_ordered(list_item **root, list_item *item)
{
    //If linked list is empty
    if (*root == NULL || (*root)->value >= item->value)
    {
        item->next = *root;
        *root = item;
        return;
    }

    //Locate the node before insertion
    list_item *current = *root;
    while (current->next != NULL && current->next->value < item->value)
        current = current->next;

    item->next = current->next;
    current->next = item;
}

int main(void) //main method
{
    list_item list[4];
    list_item *root = NULL;
    list_item item;
    root = &list[0];

    list[0].value = 3;
    list[0].next = list + 1;
    list[1].value = 5;
    list[1].next = list + 2;
    list[2].value = 7;
    list[2].next = list + 3;
    list[3].value = 9;
    list[3].next = 0;
    printf("Test to add list item whose value is 6\n");
    item.value = 1;
    item.next = 0;

    //  test case is to add element in the front, middle and end of list
    add_ordered(&root, &item);

    print_list(root);

    return 0;
}
