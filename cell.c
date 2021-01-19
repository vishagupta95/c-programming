#include<stdio.h>

int *check(int arr[], int days)
{
    int outer = 0;
    int ind = 0;
    int dupArr[8];

    for (outer = 0; outer < days; outer++)
    { //Number of days to simulate

        for (ind = 0; ind < 8; ind++)
        { //Traverse the whole array
            //cells on the ends have single adjacent cell, so the other adjacent cell can be assumsed to be always inactive

            if (ind == 0)
            {
                if (arr[ind + 1] == 0)
                    dupArr[ind] = 0;
                else
                    dupArr[ind] = 1;
            }
            else if (ind == 7)
            {

                if (arr[ind - 1] == 0)
                    dupArr[ind] = 0;
                else
                    dupArr[ind] = 1;
            }
            else
            {
                if ((arr[ind - 1] == arr[ind + 1]))
                { // if its neighbours are both active or both inactive, the cell becomes inactive the next day
                    dupArr[ind] = 0;
                }
                else //otherwise it becomes active the next day
                    dupArr[ind] = 1;
            }
        }

        printf(" \n inside function days = %u \n", outer + 1);
        for (ind = 0; ind < 8; ind++)
        {
            arr[ind] = dupArr[ind]; //Copying the altered array to original array, so that we can alter it n number of times.
            printf("%d", arr[ind]);
        }

        printf("\n");
    }
    return &arr[0];
    ;
}

int main()
{
    int days = 2, arr[8] = {1, 0, 0, 0, 0, 1, 0, 0};
    int *ptr;
    int i = 0;
    printf(" **** start ***** \n");
    for (i = 0; i < 8; i++)
        printf("%d", arr[i]);
    printf("\n");

    ptr = check(arr, days);
    printf(" **** final ***** \n");
    for (i = 0; i < 8; i++)
        printf("%d", ptr[i]);
    printf("\n");
}
