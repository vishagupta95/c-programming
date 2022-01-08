#include <stdio.h>
#include <stdlib.h>  // malloc etc

/*
*
*
*  NULL pointer is usually defined as:#define NULL (void *)0
*  ASCII character '0' evaluates to 48 or 0x30.
* '\0' is defined to be a null character 
*  \0 is 0
*  0 is 48
*  In C language string is nothing but an array of char 1 byte. Each array is terminated with null character of 1 byte 
*  Integer arrays are not C-style strings, and there is no null-terminator values in them
*
*/


/* coding Guideline
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

    while (ret == 1) {
       ret = xmlTextReaderRead(reader);
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
     
 
    printf("String test  Method 1\n\n");
    
    for (i = 0; i < argc; i++)
    {
        printf("String [%d] : %s \n", i + 1, argv[i]);
    }
    
    printf("String test  Method 2\n\n");
    
    for (i = 0; i < argc; i++)
    {
        printf("A-String [%d] : %s \n", i + 1, argt[i]);
    }

    printf("String test  Method 3\n\n");

    for (i = 0; i < array[i] != '\0'; i++)
    {
        printf("array [%d] : %c\n", i + 1, array[i]);
    }

    printf("String test  Method 4\n\n");
    for (i = 0; i < array2[i] != '\0'; i++)
    {
        printf("array [%d] : %c\n", i + 1, array[i]);
    }

    printf("String test  Method 5\n\n");
    // loooping array of characters
    i = 0;
    while (*strg1 != '\0')
       printf("new array [%d] : %c\n", ++i, *strg1++);

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


double getIntegerAverage1(int x[], int argc)
{
    int i = 0;
    double j;
    for (i = 0; i < argc; i++)
    {
        j += x[i]; //imp
    }
    return (j / argc);
}

double getIntegerAverage2(int *x, int argc)
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
    printf("\\0 is %d\n", '\0');
    printf("0 is %d\n", '0');

    displayString_test();
    
    int argc = sizeof(balance) / sizeof(balance[0]);
    printf("sizeof(balance) %d \n", sizeof(balance));
    printf("sizeof(balance[0]) %d \n", sizeof(balance[0]));
    printf("argc =%d \n", argc);
    /* pass pointer to the array as an argument */
    
    avg = getIntegerAverage1(balance, argc);
    printf("Average value is: %f  \n", avg);

    avg = getIntegerAverage1(balance, argc);
    printf("Average value is: %f \n ", avg);

    avg = getIntegerAverage2(balance, argc);
    printf("Average value is: %f \n", avg);
    return 0;
}
