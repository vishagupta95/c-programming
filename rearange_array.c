#include  <stdio.h>
void swap(int *x, int *y)
{
  int t = *x;
  *x = *y;
  *y = t;
}
void rearrange(int arr[], int n ,int pivot) 
{ 
    int j = 0 , i =1; 
    for (; i < n; i++) { 
        if (arr[i] < pivot) { 

                if( i != j)
                swap(&arr[i], &arr[j]); 
            j++; 
        } 
    } 
} 

// A utility function to print an array 
void printArray(int arr[], int n) 
{
    int i = 0;    
    for (; i < n; i++) 
        printf("%d ", arr[i]); 
} 

// Driver code 
int main() 
{ 
    int arr[] = { 10,6,12, 13, 4, 5, 16, 17, 18, 9 }; 
    // pivot is first element 
    int n = sizeof(arr) / sizeof(arr[0]); 
    rearrange(arr, n , 10); 
    printArray(arr, n); 
    return 0; 
} 

