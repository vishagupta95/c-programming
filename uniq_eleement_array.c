#include <stdio.h>
int findSingle(int ar[], int ar_size) 
{ 
        // Do XOR of all elements and return 
        int res = ar[0]; 
        int i =0;
        int x=0;
        static int count;
            printf(" count %u num %u res %u \n",++count,ar[i],res);
        for (i = 1; i < ar_size; i++)  {
             x =res;    
            res = res ^ ar[i]; 
            printf(" count %u num %u xor %u res %u \n",++count,ar[i],x,res);
        }   
  
        return res; 
} 
  
// Driver code 
int main() 
{ 
        int ar[] = {2, 3, 5, 4, 5, 3, 4}; 
        int n = sizeof(ar) / sizeof(ar[0]); 
        printf( "Element occurring once is %d \n " , findSingle(ar, n)); 
        return 0; 
} 
