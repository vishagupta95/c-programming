/*
 * Algorithm Paradigm: Backtracking 

Time Complexity: O(n*n!) Note that there are n! permutations and it requires O(n) time to print a permutation.
 you can use recursion. Here's a C program to achieve this:

c


Auxiliary Space: O(r – l)
*/
#include <stdio.h>

// Function to swap two elements in an array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print all permutations of an array
void printPermutations(int arr[], int start, int end) {
    if (start == end) {
        // Base case: When we reach the end of the array, print the permutation
        for (int i = 0; i <= end; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        // Recursive case: Generate permutations by swapping elements
        for (int i = start; i <= end; i++) {
            // Swap the current element with itself and all subsequent elements
            swap(&arr[start], &arr[i]);
            
            // Recursively generate permutations for the remaining elements
            printPermutations(arr, start + 1, end);
            
            // Restore the array to its original state (backtrack)
            swap(&arr[start], &arr[i]);
        }
    }
}

int main() {
    int arr[] = {1, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("All permutations of the array:\n");
    printPermutations(arr, 0, n - 1);

    return 0;
}

#if 0
/* Driver program to test above functions */
int main()
{
	char str[] = "ABC";
	int n = strlen(str);
	permute(str, 0, n-1);
	return 0;
}
#endif


