#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a 2D array and return a pointer to it
int** create2DArray(int rows, int cols) {
    int **array = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * sizeof(int));
    }
    return array;
}

// Function to update the value at a specific location in the 2D array using pointers
void updateElement(int** array, int rows, int cols, int row, int col, int *value) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        *(*(array + row) + col) = *value;
    } else {
        printf("Invalid indices\n");
    }
}

// Function to display the 2D array using pointers
void displayArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(*(array + i) + j));
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

    // Create a 2D array
    int **matrix = create2DArray(rows, cols);

    // Input values for the 2D array using pointer to updateElement function
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value;
            scanf("%d", &value);
            updateElement(matrix, rows, cols, i, j, &value);
        }
    }

    // Display the 2D array using pointer to displayArray function
    printf("Matrix:\n");
    displayArray(matrix, rows, cols);

    // Free the memory allocated for the 2D array
    free2DArray(matrix, rows);

    return 0;
}

