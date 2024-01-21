#include <stdio.h>
#include <stdlib.h>

// Function to create a 2D array and set values
int** createAndSetArray(int rows, int cols) {
    // Allocate memory for the 2D array
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Set values in the 2D array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j; // important
        }
    }

    return matrix;
}

// Function to set value at a specific location in the 2D array
void setValue(int **matrix, int rows, int cols, int row, int col, int value) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        matrix[row][col] = value;
    } else {
        printf("Invalid location\n");
    }
}

// Function to retrieve value from a specific location in the 2D array
int getValue(int **matrix, int rows, int cols, int row, int col) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        return matrix[row][col];
    } else {
        printf("Invalid location\n");
        return -1; // Return a default value or handle the error accordingly
    }
}

// Function to print values in the 2D array
void printArray(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free memory allocated for the 2D array
void freeArray(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int rows = 3;
    int cols = 4;

    // Create and set values in the 2D array
    int **matrix = createAndSetArray(rows, cols);

    // Print values in the original array
    printf("Original Array:\n");
    printArray(matrix, rows, cols);

    // Set value at a specific location
    setValue(matrix, rows, cols, 1, 2, 99);

    // Retrieve and print value from the modified location
    int retrievedValue = getValue(matrix, rows, cols, 1, 2);
    printf("\nValue at location (1, 2): %d\n", retrievedValue);

    // Print values in the modified array
    printf("\nModified Array:\n");
    printArray(matrix, rows, cols);

    // Free allocated memory
    freeArray(matrix, rows);

    return 0;
}

