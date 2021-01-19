// C++ program to print largest contiguous array sum 
#include<stdio.h> 
#include<limits.h> 
/* We alays belived all sum is the max sub array,excpept we encouber large negative number */


int maxSubArraySum(int a[], int size) 
{
    int max_so_far = INT_MIN, max_ending_here = 0; 

    for (int i = 0; i < size; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        printf("count %2d  current val %2d max_ending_here %2d  %d ",i,a[i],max_ending_here,INT_MIN);

        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here; 
            printf(",max_so_far_change%2d ",max_so_far);
        }    

        if (max_ending_here < 0) {
            printf(",max_ending_here negative %2d ",max_ending_here);
            max_ending_here = 0; 
        }

        printf("\n");    
    } 
    return max_so_far; 
} 

/*Driver program to test maxSubArraySum*/
int main() 
{ 
    int a[] = {10, 10, 10, -31,20,-20,20}; 
    printf("%d %d \n",INT_MIN,INT_MAX); 
    int n = sizeof(a)/sizeof(a[0]); 
    int max_sum = maxSubArraySum(a, n); 
    printf( "Maximum contiguous sum is  %u \n",max_sum); 
    return 0; 
} 

