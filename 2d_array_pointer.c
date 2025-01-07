#include <stdio.h>
#include <stdlib.h>

/* Each element of the array can be accessed using pointer arithmetic. For example, the 
 * element at position [i][j] can be accessed as *(*(array + i) + j) or simply array[i][j]
   Key Points to Emphasize
   Memory is allocated in two stages: pointers first, then rows.
   Rows are not guaranteed to be contiguous.
   Pointer arithmetic or array[i][j] can be used for element access.
   Freeing memory requires reversing the allocation order.

*/

// Function to initialize a 2D array with default values
int** initialize2DArray(int rows, int cols, int defaultValue) {
    int** array = (int**)malloc(rows * sizeof(int*)); // Allocate memory for row pointers
    if (array == NULL) {
        perror("Failed to allocate memory for rows");
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        array[i] = (int*)malloc(cols * sizeof(int)); // Allocate memory for each row
        if (array[i] == NULL) {
            perror("Failed to allocate memory for a row");
            for (int k = 0; k < i; k++) {
                free(array[k]); // Free previously allocated rows
            }
            free(array);
            return NULL;
        }

        for (int j = 0; j < cols; j++) {
            array[i][j] = defaultValue; // Initialize elements with the default value
        }
    }
    return array;
}

// Function to update an element of the 2D array using pointers
void updateElementPointer(int** array, int rows, int cols, int row, int col, int value) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        array[row][col] = value; // Update the element using array indexing
    } else {
        printf("Invalid indices: row=%d, col=%d\n", row, col);
    }
}

// Function to print a 2D array using pointers
void print2DArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]); // Access the element using array indexing
        }
        printf("\n");
    }
}

// Function to free the memory allocated for the 2D array
void free2DArray(int** array, int rows) {
    for (int i = 0; i < rows; i++) {
        free(array[i]); // Free memory for each row
    }
    free(array); // Free memory for the row pointers
}

int main() {
    int rows = 3, cols = 3, defaultValue = 0;

    // Initialize the 2D array
    int** array = initialize2DArray(rows, cols, defaultValue);
    if (array == NULL) {
        return 1; // Exit if memory allocation failed
    }

    printf("Initial Array:\n");
    print2DArray(array, rows, cols);

    // Update elements in the array
    updateElementPointer(array, rows, cols, 1, 1, 42);
    updateElementPointer(array, rows, cols, 2, 2, 99);

    printf("\nUpdated Array:\n");
    print2DArray(array, rows, cols);

    // Free the allocated memory
    free2DArray(array, rows);

    return 0;
}

