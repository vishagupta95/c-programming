#include <stdio.h>
#include <stdlib.h>  // malloc etc

/* C program to demonstrate how to pass array of integer to a function*/

void displayString(char **argv, int argc, char *array, char array2[])
{
    int i = 0;
 
    printf("\n");
    
    for (i = 0; i < argc; i++)
    {
        printf("String [%d] : %s \n", i + 1, argv[i]);
    }

    for (i = 0; i < array[i] != 0; i++)
    {
        printf("array [%d] : %c\n", i + 1, array[i]);
    }

    for (i = 0; i < array2[i] != 0; i++)
    {
        printf("array [%d] : %c\n", i + 1, array[i]);
    }
}

int displayString_test()
{
    char array[] = "king";
    char *buff[] = {"aap", "bap", "cat", "dog"};
    int argc = sizeof(buff) / sizeof(buff[0]);
    printf("argc = %d\n ", argc);
    displayString(buff, argc, array, array);
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