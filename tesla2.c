#include <stdio.h>

double square(volatile double *value) {
    // Check if the pointer is not NULL for safety
    if (value != NULL) {
        // Calculate the square of the value
        double squareValue = (*value) * (*value);

        // Return the result
        return squareValue;
    } else {
        // Handle the case where the pointer is NULL (optional)
        fprintf(stderr, "Error: NULL pointer passed to square function\n");
        return 0.0;  // Return a default value or handle the error as needed
    }
}

int main() {
    volatile double inputValue = 5.0;
    double result = square(&inputValue);

    printf("The square of %.2f is %.2f\n", inputValue, result);

    return 0;
}

