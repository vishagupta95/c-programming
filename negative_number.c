#include <stdio.h>

void rearrange_alternate_positions(int arr[], int n) {
    int negativeIndex = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (i != negativeIndex) {
                // Swap negative element with the element at negativeIndex
                int temp = arr[i];
                arr[i] = arr[negativeIndex];
                arr[negativeIndex] = temp;
            }
            negativeIndex++;
        }
    }
}

int main() {
    int n = 7;
    int arr[] = {9, 8, 6, -1, 9, -23, 4};

    printf("Original array : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    rearrange_alternate_positions(arr, n);

    printf("Rearranged array : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

