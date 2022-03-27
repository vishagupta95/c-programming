#include <stdio.h>
#include <stdlib.h>

//Rearrange positive and negative numbers in an array
void rearrange_alternate_positions(int input[], int n)
{
   int *negative = malloc(sizeof(int) * n); 
   int *positive = malloc(sizeof(int) * n); 
   int negativeIndex = 0; 
   int positiveIndex = 0; 
   int zero = 0; 
   int i, temp; 

   for (i = 0; i < n; i++) 
   { 
    if (input[i] < 0) 
        negative[negativeIndex++] = input[i]; 
    else if (input[i] > 0) 
        positive[positiveIndex++] = input[i];
    else 
        zero++; 
 } 

for (i = 0; i < negativeIndex; i++) 
     input[i] = negative[i]; /* copy negative elements */ 

for (temp = 0; temp < zero; temp++, i++) 
     input[i] = 0; /* copy zeroes */ 

for (temp = 0; temp < positiveIndex; temp++, i++) 
    input[i] = positive[temp]; /* copy the positive elements */ 
    free(negative);
    free(positive);

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
    int arr[] = {12, 6, -10, 13, 4, -5, -16, 17, 18, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrange_alternate_positions(arr, n);
    printArray(arr, n);
    return 0;
}

