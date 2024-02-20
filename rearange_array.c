#include <stdio.h>

// Function to rearrange array based on a pivot
void rearrangeArray(int arr[], int n, int pivot) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        // Find the first element from the left that is greater than the pivot
        while (arr[left] <= pivot) {
            left++;
        }

        // Find the first element from the right that is less than or equal to the pivot
        while (arr[right] > pivot) {
            right--;
        }

        // Swap elements at left and right indices
        if (left <= right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            // Move indices towards the center
            left++;
            right--;
        }
    }
}

int main() {
    int n = 10;
    int arr[] = {8, 4, 12, 10, 5, 6, 2, 7, 3, 9};
    int pivot = 6;

    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Call the function to rearrange based on the pivot
    rearrangeArray(arr, n, pivot);

    printf("\nRearranged Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

