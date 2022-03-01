#include  <stdio.h>
/*

There are four types of common coins in US currency:
  o) quarters (25 cents)
  o) dimes (10 cents)
  o) nickels (5 cents)
  o) pennies (1 cent)

There are 6 ways to make change for 15 cents:
  o) A dime and a nickel;
  o) A dime and 5 pennies;
  o) 3 nickels;
  o) 2 nickels and 5 pennies;
  o) A nickel and 10 pennies;
  o) 15 pennies.

How many ways are there to make change for a dollar using these common coins? (1 dollar = 100 cents).

The idea is to use recursion to solve this problem. We recur to see if the total 
can be reached by choosing the coin or not for each coin of given denominations. 
If choosing the current coin results in the solution, update the total number of ways.

For every coins 2 options take or not take it
cnt(S[],M,v)  = CNT(s[],m V-S)  + cnt(S[] , M-1 , V)

like
S = { 1,2 ,3}  v= 6  ,SIZE =3
   { 1,2,3} ,3 ,6
     if consider 3      |  in not consider 3
   {1,2,3} , 3 ,3 }       { 1,2},2,6

}

*/

int coin_count(int arr[], int size, int n){ 
    // If n is 0 then  
    // do not include any coin
    if(n==0) 
        return 1; 
      
    // If n is less than 0   
    // no solution exists 
    if(n<0) 
        return 0; 
  
    // If coins do not exist and n  
    // is greater than 0, 
    // no solution exist 
    if((size<=0)&&(n>=1)) 
        return 0; 
    return coin_count(arr,size-1,n)+coin_count(arr,size,n-arr[size-1]); 
}
int main(){ 
    int c[] = {1, 5, 10 ,25};
    int n=100;
    int size = sizeof(c)/sizeof(c[0]); 
    printf (" %d  \n",coin_count(c, size, n));
    return 0; 
}


/* method 2
Since same subproblems are called again, this problem has Overlapping Subproblems property. So the Coin Change problem has both properties (see this and this) of a dynamic programming problem. Like other typical Dynamic Programming(DP) problems, recomputations of same subproblems can be avoided by constructing a temporary array table[][] in bottom up manner.
*/


// C program for coin change problem.

int count( int S[], int m, int n )
{
    int i, j, x, y;

    // We need n+1 rows as the table is constructed
    // in bottom up manner using the base case 0
    // value case (n = 0)
    int table[n+1][m];
    
    // Fill the entries for 0 value case (n = 0)
    for (i=0; i<m; i++)
        table[0][i] = 1;

    // Fill rest of the table entries in bottom
    // up manner
    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            // Count of solutions including S[j]
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;

            // Count of solutions excluding S[j]
            y = (j >= 1)? table[i][j-1]: 0;

            // total count
            table[i][j] = x + y;
        }
    }
    return table[n][m-1];
}

// Driver program to test above function
int main_x()
{
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 4;
    printf(" %d ", count(arr, m, n));
    return 0;
}

