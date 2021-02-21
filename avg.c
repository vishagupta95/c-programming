#include <stdio.h>

void display(int *ptr, int count)
{
    int i = 0;

    for (i = 0; i < count; i++)
    {
        printf(" [%u] ", *ptr);
        ptr++;
    }
    printf("\n\n");
}

double getAverage1(int x[5], int count)
{
    int i = 0;
    double j;
    for (i = 0; i < count; i++)
    {
        j += x[i];
    }
    return (j / count);
}

double getAverage2(int *x, int count)
{
    int i = 0;
    double j;
    for (i = 0; i < count; i++)
    {
        j += x[i];
    }
    return (j / count);
}

int main()
{

    /* an int array with 5 elements */
    int balance[5] = {1000, 2, 3, 17, 50};
    double avg;
    int count = sizeof(balance) / sizeof(balance[0]);
    printf("count =%d \n", count);

    /* pass pointer to the array as an argument */
    display(balance, count);

    avg = getAverage1(balance, count);
    printf("Average value is: %f  \n", avg);

    display(balance, count);
    avg = getAverage1(balance, count);
    printf("Average value is: %f \n ", avg);
    display(balance, count);

    avg = getAverage2(balance, count);
    printf("Average value is: %f \n", avg);
    display(balance, count);
    return 0;
}
