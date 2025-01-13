#include <stdio.h>
#include <stdlib.h>

/*

In a 2D array, the main array holds pointers to each row. This is why we declare array as int**
2D array is essentially an array of arrays.
Address of Rows: The addresses of each row (&array[i]) may not be contiguous, as the rows are allocated separately.
n = rows × cols, which represents the total number of elements in the 2D array.
The nested loops iterate over each element exactly once, resulting in O(n) iterations.
spae comlexity 0(1)

*/

// Function to initialize a 2D array dynamically
int** initialize2DArray(int rows, int cols, int defaultValue) {
    int** array = malloc(rows * sizeof(int*));  // Allocate memory for rows
    if (array == NULL) {  // Check if malloc failed for rows allocation
        printf("Memory allocation failed for rows.\n");
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        array[i] = malloc(cols * sizeof(int));  // Allocate memory for each row
        if (array[i] == NULL) {  // Check if malloc failed for individual row
            printf("Memory allocation failed for row %d.\n", i);
            // Free already allocated rows and return NULL
            for (int j = 0; j < i; j++) {
                free(array[j]);
            }
            free(array);
            return NULL;
        }
        
        // Initialize with the default value using pointer arithmetic
        for (int j = 0; j < cols; j++) {
            *(*(array + i) + j) = defaultValue;
        }
    }
    return array;
}

// Function to update an element of the 2D array using pointers
void updateElementPointer(int** array, int rows, int cols, int row, int col, int value) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        *(*(array + row) + col) = value;  // Update using pointer arithmetic
    } else {
        printf("Invalid indices: row=%d, col=%d\n", row, col);  // Error handling
    }
}

// Function to print a 2D array using pointers
void print2DArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(*(array + i) + j));  // Access using pointer arithmetic
        }
        printf("\n");
    }
}

// Function to deallocate the 2D array
void free2DArray(int** array, int rows) {
    for (int i = 0; i < rows; i++) {
        free(array[i]);  // Free each row
    }
    free(array);  // Free the array of pointers
}

int main() {
    int rows = 3, cols = 4;
    int defaultValue = 0;
    
    // Initialize a 2D array with default value
    int** array = initialize2DArray(rows, cols, defaultValue);
    
    // Check if memory allocation was successful
    if (array == NULL) {
        return 1;  // Return non-zero value indicating failure
    }

    // Update an element using pointer arithmetic
    updateElementPointer(array, rows, cols, 1, 2, 100);  // Set element at (1, 2) to 100
    
    // Print the updated array using pointer arithmetic
    print2DArray(array, rows, cols);
    
    // Free the allocated memory
    free2DArray(array, rows);
    
    return 0;
}

