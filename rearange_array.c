#include <stdio.h>
void printArray(int arr[], int n);
void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}
/* ensure pivot is last element */
void rearrange(int arr[], int n, int pivot)
{

    int i = -1; // Index of smaller element and indicates the right position of pivot found so far
    int j = 0;
    for (j = 0; j <= n; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[n - 1]);
}

/*

Declare an array and input the array elements.
Start traversing the array and if the current element is negative,swap 
the current element with the first positive element and continue traversing until all the elements have been encountered.
Print the rearranged array.

*/
//Rearrange positive and negative numbers in an array
void rearrange_alternate_positions(int arr[], int n)
{
    int i, j;
    j = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            if (i != j)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
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
    printf("\n\n");
}

// Driver code
int main()
{
    int arr[] = {12, 6, 10, 13, 4, 5, 16, 17, 18, 9};
    int arr1[] = {12, 6, -10, 13, 4, 5, -16, 17, 18, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrange(arr, n, 9);
    printArray(arr, n);
    rearrange_alternate_positions(arr1, n);
    printArray(arr1, n);
    return 0;
}

