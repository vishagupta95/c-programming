#include <stdio.h>

void swapHighestBitsInByte(unsigned char *bytePtr) {
    if (bytePtr != NULL) {
        // Extract the higher and lower nibbles
        unsigned char higherNibble = (*bytePtr & 0xF0) >> 4;
        unsigned char lowerNibble = *bytePtr & 0x0F;

        // Swap the highest bits in each nibble
        *bytePtr = (lowerNibble << 4) | higherNibble;
    } else {
        // Handle the case where the pointer is NULL (optional)
        fprintf(stderr, "Error: NULL pointer passed to swapHighestBitsInByte function\n");
    }
}

int main() {
    unsigned char byte = 0xAB;  // Example byte

    // Call the function to swap highest bits in each nibble using a pointer
    swapHighestBitsInByte(&byte);

    // Print the original and swapped bytes
    printf("Original byte: 0x%X\n", byte);

    return 0;
}

