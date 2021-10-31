#include <stdio.h>
#include <stdlib.h>  // malloc etc

/* coding guideline
 *
 * 1.   main and other functions should start with a curly brace on a new  line
 * 2.   Use 4 space gap after the start of function or while loop on a new  line
 * 3.   Use  single space before and after every variable  assignment 
 * 4.   Inside a for loop space immediately after first and second semicolon
 * 5.   Space after if  before bracket 
 * 6.   Space after for loop  before bracket 
 * 7.   Space after while loop  before bracket 

static void
print_element_names(xmlNode * a_node)
{
    xmlNode *cur_node = NULL;

    for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
        if (cur_node->type == XML_ELEMENT_NODE) {
            printf("node type: Element, name: %s\n", cur_node->name);
        }

        print_element_names(cur_node->children);
    }
}

int
main(int argc, char **argv)
{
    xmlDoc *doc = NULL;
    xmlNode *root_element = NULL;

    if (argc != 2)
        return(1);
*/



/* C program to demonstrate how to pass array of integer to a function*/

void displayString(char **argv,char *argt[], int argc, char *array, char array2[])
{

    int i = 0;
    char *strg1 = array;
     
 
    printf("\n");
    
    for (i = 0; i < argc; i++)
    {
        printf("String [%d] : %s \n", i + 1, argv[i]);
    }
    
    for (i = 0; i < argc; i++)
    {
        printf("A-String [%d] : %s \n", i + 1, argt[i]);
    }


    for (i = 0; i < array[i] != 0; i++)
    {
        printf("array [%d] : %c\n", i + 1, array[i]);
    }

    for (i = 0; i < array2[i] != 0; i++)
    {
        printf("array [%d] : %c\n", i + 1, array[i]);
    }

    // loooping array of characters
    i = 0;
    while (*strg1 != '\0')
       printf(" new array [%d] : %c\n", ++i, *strg1++);

}

int displayString_test()
{
    char array[] = "king";
    char *buff[] = {"aap", "bap", "cat", "dog"};
    int argc = sizeof(buff) / sizeof(buff[0]);
    printf("argc = %d\n ", argc);
    displayString(buff, buff, argc, array, array);
    return 0;
}

void display(int *argv)
{
    int i = 0;

    for (i = 0; i < argv[i] != 0; i++)
    {
        printf(" [%u] ", argv[i]);
    }
    printf("\n\n");
}

double getAverage1(int x[], int argc)
{
    int i = 0;
    double j;
    for (i = 0; i < argc; i++)
    {
        j += x[i]; //imp
    }
    return (j / argc);
}

double getAverage2(int *x, int argc)
{
    int i = 0;
    double j;
    for (i = 0; i < argc; i++)
    {
        j += x[i];
    }
    return (j / argc);
}

int main()
{

    /* an int array with 5 elements */
    int balance[] = {14, 16, 18, 20, 22};
    double avg;

    displayString_test();
    
    int argc = sizeof(balance) / sizeof(balance[0]);
    printf("sizeof(balance) %d \n", sizeof(balance));
    printf("sizeof(balance[0]) %d \n", sizeof(balance[0]));
    printf("argc =%d \n", argc);

    /* pass pointer to the array as an argument */
    display(balance);

    avg = getAverage1(balance, argc);
    printf("Average value is: %f  \n", avg);

    display(balance);
    avg = getAverage1(balance, argc);
    printf("Average value is: %f \n ", avg);
    display(balance);

    avg = getAverage2(balance, argc);
    printf("Average value is: %f \n", avg);
    display(balance);
    return 0;
}
