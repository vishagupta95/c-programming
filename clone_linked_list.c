#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 *
 * strlen: Returns the length of the given byte string not including null terminator;
 *
 * char s[]="help";
 * strlen(s) should return 4.
 * sizeof: Returns the length of the given byte string, include null terminator;
 *
 * char s[]="help";
 * sizeof(s) should return 5
 *
 * strcpy(ptr2, ptr1) is equivalent to while(*ptr2++ = *ptr1++)
 *
 * where as strdup is equivalent to
 *
 * ptr2 = malloc(strlen(ptr1)+1);
 * strcpy(ptr2,ptr1);
 */



struct link
{
    char *buf;
    struct link *next;
};

struct link *dup_list(struct link *list)
{

    struct link *current = list; // used to iterate over the original list
    struct link *dup = NULL;     // head of the new list
    struct link *tail = NULL;    // point to the last node in a new list
   
    while (current != NULL)
    {
        // special case for the first new node
        if (dup == NULL)
        {
            dup = (struct link *)malloc(sizeof(struct link));
            dup->buf = (char*)malloc(strlen(current->buf) +1); 
            strcpy(dup->buf, current->buf);
            dup->next = NULL;
            tail = dup;
        }
        else
        {
            tail->next = (struct link *)malloc(sizeof(struct link));
            tail = tail->next;
            tail->buf = (char*)malloc(strlen(current->buf) +1);
            strcpy(tail->buf, current->buf);
            tail->next = NULL;
        }
        current = current->next;
    }

    return dup;
}

void free_list(struct link **list)
{
    struct link *tmp = *list;
    struct link *ptr = *list;

    while (ptr!= NULL)
    {
        tmp = ptr;
        ptr = ptr->next;
        free(tmp->buf);
        tmp->buf = NULL;
        free(tmp);
        tmp = NULL;
    }
    
    *list = NULL;
}

void print_list(const struct link *list)
{
    while (list != NULL)
    {
        printf(" %s \n", list->buf);
        list = list->next;
    }
}

int main()
{

    struct link *l1, *l2, *l3;

    l1 = (struct link *)malloc(sizeof(struct link));
    l2 = (struct link *)malloc(sizeof(struct link));
    l3 = (struct link *)malloc(sizeof(struct link));

    l1->buf = strdup("Ottawa, Ontario");
    l2->buf = strdup("Ontario, Canada");
    l3->buf = strdup("Canada, North America");

    l1->next = l2;
    l2->next = l3;
    l3->next = NULL;

    print_list(l1);

    struct link *dup = dup_list(l1);

    printf("Content of the original list:");
    print_list(l1);

    printf("content of the duplicated list:");
    print_list(dup);

    free_list(&dup);
    free_list(&l1);

    printf("After doing free list:");
    print_list(l1);

    return 0;
}
