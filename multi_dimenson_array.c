/*2d array */
#include <stdio.h>
int main()
{
    // initializing the 3-dimensional array
    int x[2][3][2] =
        {
            {{0, 1}, {2, 3}, {4, 5}},
            {{6, 7}, {8, 9}, {10, 11}}};

    // output each element's value
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {    
            printf("\n");

            for (int k = 0; k < 2; ++k)
            {
                printf(" x[%d][%d][%d] --> address [%u] ->value  [%u] ", i,j,k , &x[i][j][k], x[i][j][k]);
            }
            printf("\n ");
        }
        printf("\n ");
    }
    printf(" x %u \n", x); 
    printf(" x0 %u \n", x[0]);
    printf(" x1 %u \n", x[1]);
    return 0;
}

