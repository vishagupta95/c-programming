#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a 2D array and return a pointer to it
int** create2DArray(int rows, int cols) {
    int **array = (int **)malloc(rows * sizeof(int *));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    for (int i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * sizeof(int));
        if (array[i] == NULL) {
            printf("Memory allocation failed\n");
            for (int j = 0; j < i; j++) {
                free(array[j]);
            }
            free(array);
            return NULL;
        }
    }
    return array;
}

// Function to update the value at a specific location in the 2D array using pointers
void updateElement(int** array, int rows, int cols, int row, int col, int value) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        array[row][col] = value;
    } else {
        printf("Invalid indices\n");
    }
}

// Function to display the 2D array using pointers
void displayArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

// Function to free the memory allocated for the 2D array
void free2DArray(int** array, int rows) {
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);
}

int main() {
    int rows, cols;

    // Input the number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Allocate memory for the 2D array
    int** array = create2DArray(rows, cols);
    if (array == NULL) {
        return 1;
    }

    // Example usage
    int value = 5;
    updateElement(array, rows, cols, 1, 1, value);
    displayArray(array, rows, cols);

    // Free the allocated memory
    free2DArray(array, rows);

    return 0;
}
