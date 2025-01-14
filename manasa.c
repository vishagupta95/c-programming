#include <stdio.h>
#include <stdlib.h>

/*
Manasa is playing a game with stones. She has a sequence of n stones, numbered from 1 to n, where the first stone has a value of 0. 
Each subsequent stone can have a value derived from the previous stone by adding either a or b to its value. 
The task is to determine the value of the last stone after n-1 steps.

You are given the following input:

n: the number of stones (an integer).
a and b: the possible values that can be added to the value of the previous stone.

*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int i;
    int n, a, b, t;
    int arr[1000] = {0};

    t = 1;
    n = 3;  // Example input
    a = 2;  // Example input
    b = 3;  // Example input

    while (t--) {
        for (i = 0; i < n; i++) {
            if (a == b) {
                printf("%d ", a * (n - 1));
                break;
            } else if (a > b) {
                arr[i] = (b * (n - 1 - i)) + (a * i);
            } else {
                arr[i] = (a * (n - i - 1)) + (b * i);
            }
        }

        // Sort the array to ensure the results are in ascending order
        qsort(arr, n, sizeof(int), compare);

        // Print unique values
        for (i = 0; i < n; i++) {
            if (i == 0 || arr[i] != arr[i - 1]) {
                printf("%d ", arr[i]);
            }
        }

        printf("\n");
    }

    return 0;
}


// Function to calculate possible values of the last stone
void stones(int n, int a, int b) {
    int i, result;
    // Array to store possible values
    int values[n];
    
    // Calculate all possible values of the last stone
    for (i = 0; i < n; i++) {
        result = i * a + (n - 1 - i) * b;
        values[i] = result;
    }
    
    // Sort the array in ascending order
    for (i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (values[i] > values[j]) {
                // Swap the values
                int temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }
    
    // Print the result
    for (i = 0; i < n; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
}

int main() {
    int n, a, b;
    
    // Reading input
    scanf("%d %d %d", &n, &a, &b);
    
    // Call the stones function to print the result
    stones(n, a, b);
    
    return 0;
}

