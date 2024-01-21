#include <stdio.h>

// Define a macro for the size of the arrays
#define ARR_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

// Declare global arrays
float arrX[] = {1.0, 2.0, 3.0, 4.0, 5.0};
float arrY[] = {10.0, 20.0, 30.0, 40.0, 50.0};

// Function prototype
float interpolate(float val);

int main() {
    // Example usage:

    // Interpolate at x = 2.5
    float result1 = interpolate(2.5);
    printf("Interpolation at x=2.5: %f\n", result1);

    return 0;
}

float interpolate(float val) {
    // Check if val is within the range covered by arrX
    if (val <= arrX[0] || val > arrX[ARR_SIZE(arrX) - 1]) {
        return -1; // Return -1 for values outside the range
    } else {
        // Find the two points between which val lies
        int i = 0;
        while (arrX[i] < val) {
            i++;
        }

        // Linear interpolation formula for val
        float x0 = arrX[i - 1], x1 = arrX[i];
        float y0 = arrY[i - 1], y1 = arrY[i];

        return y0 + (y1 - y0) * (val - x0) / (x1 - x0);
    }
}

