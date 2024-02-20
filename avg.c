#include <stdio.h>
#include <stdlib.h>  // malloc etc

/* Function declarations */
void display(int *argv);
double getAverage1(int x[], int argc);
double getAverage2(int *x, int argc);

/* Function to display arrays and strings */
void displayString(char **argv, char *argt[], int argc, char *array, char array2[])
{
    int i = 0;
    char *strg1 = array;

    printf("\n");

    // Display strings in argv and argt arrays
    for (i = 0; i < argc; i++)
    {
        printf("String [%d] : %s \n", i + 1, argv[i]);
    }

    for (i = 0; i < argc; i++)
    {
        printf("A-String [%d] : %s \n", i + 1, argt[i]);
    }

    // Display characters in the 'array' array
    for (i = 0; array[i] != 0; i++)
    {
        printf("array [%d] : %c\n", i + 1, array[i]);
    }

    // Display characters in the 'array2' array (Note: array[i] should be array2[i])
    for (i = 0; array2[i] != 0; i++)
    {
        printf("array2 [%d] : %c\n", i + 1, array2[i]);
    }

    // Loop through the characters in the 'strg1' array
    i = 0;
    while (*strg1 != '\0')
        printf("new array [%d] : %c\n", ++i, *strg1++);
}

/* Function definitions */
void display(int *argv)
{
    int i = 0;

    // Display integers in the 'argv' array
    for (i = 0; argv[i] != 0; i++)
    {
        printf(" [%u] ", argv[i]);
    }
    printf("\n\n");
}

double getAverage1(int x[], int argc)
{
    int i = 0;
    double j = 0; // Initialize j to zero

    // Sum up the elements in the array
    for (i = 0; i < argc; i++)
    {
        j += x[i];
    }

    // Return the average
    return (j / argc);
}

double getAverage2(int *x, int argc)
{
    int i = 0;
    double j = 0; // Initialize j to zero

    // Sum up the elements in the array
    for (i = 0; i < argc; i++)
    {
        j += x[i];
    }

    // Return the average
    return (j / argc);
}

int main()
{
    /* An int array with 5 elements */
    int balance[] = {14, 16, 18, 20, 22};
    double avg;

    char array[] = "king";
    char *buff[] = {"aap", "bap", "cat", "dog"};
    int argc_buff = sizeof(buff) / sizeof(buff[0]);

    printf("argc_buff = %d\n ", argc_buff);

    displayString(buff, buff, argc_buff, array, array);

    int argc_balance = sizeof(balance) / sizeof(balance[0]);
    printf("sizeof(balance) %lu\n", sizeof(balance));     // Changed format specifier to %lu for size_t
    printf("sizeof(balance[0]) %lu\n", sizeof(balance[0])); // Changed format specifier to %lu for size_t
    printf("argc_balance = %d\n", argc_balance);

    /* Pass pointer to the array as an argument */
    display(balance);

    // Calculate and display the average using array notation
    avg = getAverage1(balance, argc_balance);
    printf("Average value is: %f\n", avg);

    display(balance);

    // Calculate and display the average using pointer notation
    avg = getAverage2(balance, argc_balance);
    printf("Average value is: %f\n", avg);

    display(balance);

    return 0;
}

