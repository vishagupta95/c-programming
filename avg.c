#include <stdio.h>
#include <string.h>  // malloc etc
#include <stdlib.h>  // malloc etc

/* C program to demonstrate how to pass array of integer to a function*/

void displayString(char **argv,char *argt[], int argc, char *array, char array2[])
{

    int i = 0;
    char *strg1 = array;

    printf("strlen of array is %d  \n" ,strlen(array));    
 
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
    char array[] = "vishal  gupta";
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
