# include <stdio.h>
# include <limits.h>
/*
When the sum of the series above equals 100, we get x = 13.651, which rounds up to 14. This means 
that we should start from floor 14 (which is our x) and then move up x-1 (13) floors to floor 27
if the egg doesn break and then move up x-2 (12) floors to floor 39 and so on if the egg still does not break.

This is the number of drops required as we move up the floors in the building:
 Drop    Floor 
#1  14
#2  27
#3  39
#4  50
#5  60
#6  69
#7  77
#8  84
#9  90
#10 95
#11 99
#12 100

*/

// A utility function to get maximum of two integers
int max(int a, int b) { return (a > b)? a: b; }

/* Function to get minimum number of trails needed in worst
  case with n eggs and k floors */
int eggDrop(int n, int k)
{
    /* A 2D table where entery eggFloor[i][j] will represent minimum
       number of trials needed for i eggs and j floors. */
    int eggFloor[n+1][k+1];
    int res;
    int i, j, x;

    // We need one trial for one floor and0 trials for 0 floors
    for (i = 1; i <= n; i++)
    {
        eggFloor[i][1] = 1;
        eggFloor[i][0] = 0;
    }

    // We always need j trials for one egg and j floors.
    for (j = 1; j <= k; j++)
        eggFloor[1][j] = j;

    // Fill rest of the entries in table using optimal substructure
    // property
    for (i = 2; i <= n; i++)  // floor Count 
    {
        for (j = 2; j <= k; j++)  // Egg count
        {
            eggFloor[i][j] = INT_MAX;
            for (x = 1; x <= j; x++)
            {
		
                res = 1 + max(eggFloor[i-1][x-1], eggFloor[i][j-x]);
            	               
                if (res < eggFloor[i][j])
                    eggFloor[i][j] = res;
		
            }
        }
    }

    return eggFloor[n][k];
}

/* Driver program to test to pront printDups*/
int main()
{
    int n = 3, k = 100;
    printf ("\nMinimum number of trials in worst case with %d eggs and "
             "%d floors is %d \n", n, k, eggDrop(n, k));
    return 0;
}
