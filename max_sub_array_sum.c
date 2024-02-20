#include <stdio.h>
#include <limits.h>

// Kadane's Algorithm for Maximum Subarray Sum
int maxSubArraySum(int a[], int size) {
    int max_so_far = INT_MIN; // Maximum sum of subarray ending at the current index
    int max_ending_here = 0;  // Current sum of subarray ending at the current index

    for (int i = 0; i < size; i++) {
        // Add the current element to the current subarray sum
        max_ending_here += a[i];

        // Update max_so_far if the current subarray sum is greater
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }

        // Reset the current subarray sum to 0 if it becomes negative
        if (max_ending_here < 0) {
            max_ending_here = 0;
        }
    }

    return max_so_far;
}

int main() {
    int a[] = {10, 10, 10, -31, 20, -20, 20};
    printf("INT_MIN: %d, INT_MAX: %d \n", INT_MIN, INT_MAX);

    int n = sizeof(a) / sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);

    printf("Maximum contiguous sum is %d\n", max_sum);

    return 0;
}

