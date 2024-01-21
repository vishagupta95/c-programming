#include <stdio.h>

int main() {
    // Declare a 3D array with dimensions 2x3x4
    int myArray[2][3][4] = {
        {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
        {{13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}}
    };

    // Declare a pointer to int
    int (*ptr)[3][4];

    // Point the pointer to the first 2D array (first "slice") of the 3D array
    ptr = myArray;

    // Access and print the elements using pointers
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 4; ++k) {
                printf("%d ", *(*(*(ptr + i) + j) + k));
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}


int arr[3][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
int (*ptr)[3][4];  // Declare the pointer
ptr = &arr;        // Assign the address of arr to ptr

// Accessing elements:
printf("%d\n", (*ptr)[1][2]);  // Prints 7 (accessing element in row 2, column 3)


#include <stdio.h>
#include <stdlib.h>

// Function to create a generic multidimensional array
void* createArray(int dimensions, int* sizes) {
    // Calculate the total size of the array
    int totalSize = 1;
    for (int i = 0; i < dimensions; ++i) {
        totalSize *= sizes[i];
    }

    // Allocate memory for the array
    void* array = malloc(totalSize * sizeof(int));

    return array;
}

// Function to access elements of the generic multidimensional array
int getElement(void* array, int dimensions, int* sizes, int* indices) {
    int index = 0;
    int multiplier = 1;

    // Calculate the index in the 1D array based on the multidimensional indices
    for (int i = dimensions - 1; i >= 0; --i) {
        index += indices[i] * multiplier;
        multiplier *= sizes[i];
    }

    // Access and return the element
    return *((int*)array + index);
}

// Function to set elements of the generic multidimensional array
void setElement(void* array, int dimensions, int* sizes, int* indices, int value) {
    int index = 0;
    int multiplier = 1;

    // Calculate the index in the 1D array based on the multidimensional indices
    for (int i = dimensions - 1; i >= 0; --i) {
        index += indices[i] * multiplier;
        multiplier *= sizes[i];
    }

    // Set the element
    *((int*)array + index) = value;
}

int main() {
    // Define the dimensions and sizes of the array
    int dimensions = 3;
    int sizes[] = {2, 3, 4};

    // Create a generic multidimensional array
    void* myArray = createArray(dimensions, sizes);

    // Access and set elements of the array
    for (int i = 0; i < sizes[0]; ++i) {
        for (int j = 0; j < sizes[1]; ++j) {
            for (int k = 0; k < sizes[2]; ++k) {
                int indices[] = {i, j, k};
                setElement(myArray, dimensions, sizes, indices, i * sizes[1] * sizes[2] + j * sizes[2] + k + 1);
            }
        }
    }

    // Print the elements of the array
    for (int i = 0; i < sizes[0]; ++i) {
        for (int j = 0; j < sizes[1]; ++j) {
            for (int k = 0; k < sizes[2]; ++k) {
                int indices[] = {i, j, k};
                printf("%d ", getElement(myArray, dimensions, sizes, indices));
            }
            printf("\n");
        }
        printf("\n");
    }

    // Free the allocated memory
    free(myArray);

    return 0;
}


