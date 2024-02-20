#include <stdio.h>
#include <stdlib.h>

// Structure to represent a generic multidimensional array
typedef struct {
    int dimensions; // Number of dimensions
    int *sizes;      // Array containing sizes for each dimension
    void *data;      // Pointer to the data array
} GenericArray;

// Function to initialize a generic multidimensional array
GenericArray initArray(int dimensions, int *sizes, size_t elementSize) {
    GenericArray array;
    array.dimensions = dimensions;

    // Allocate memory for the sizes array and copy the sizes
    array.sizes = (int *)malloc(dimensions * sizeof(int));
    for (int i = 0; i < dimensions; i++) {
        array.sizes[i] = sizes[i];
    }

    // Calculate total number of elements
    int totalElements = 1;
    for (int i = 0; i < dimensions; i++) {
        totalElements *= sizes[i];
    }

    // Allocate memory for the data array
    array.data = malloc(totalElements * elementSize);

    return array;
}

// Function to access an element in a generic multidimensional array
void *getElement(GenericArray *array, int index1, int index2, size_t elementSize) {
    // Calculate the linear index
    int indices[] = {index1, index2};
    int linearIndex = 0;
    int multiplier = 1;
    for (int i = array->dimensions - 1; i >= 0; i--) {
        linearIndex += indices[i] * multiplier;
        multiplier *= array->sizes[i];
    }

    // Calculate the memory offset and return the pointer to the element
    size_t offset = linearIndex * elementSize;
    return (char *)(array->data) + offset;
}

// Function to free memory allocated for a generic multidimensional array
void freeArray(GenericArray *array) {
    free(array->sizes);
    free(array->data);
}

int main() {
    // Define dimensions and sizes for a 2x3 array
    int dimensions = 2;
    int sizes[] = {2, 3};

    // Initialize a generic array of integers
    GenericArray intArray = initArray(dimensions, sizes, sizeof(int));

    // Assign values to elements
    for (int i = 0; i < sizes[0]; i++) {
        for (int j = 0; j < sizes[1]; j++) {
            int *element = getElement(&intArray, i, j, sizeof(int));
            *element = i * 10 + j;
        }
    }

    // Print the elements
    for (int i = 0; i < sizes[0]; i++) {
        for (int j = 0; j < sizes[1]; j++) {
            int *element = getElement(&intArray, i, j, sizeof(int));
            printf("%3d ", *element);
        }
        printf("\n");
    }

    // Free the memory
    freeArray(&intArray);

    return 0;
}

