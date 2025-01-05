#include <stdio.h>

// Function to count set bits with the condition that the previous bit was 0
void set_bit_count_from_void(void *input)
{
    // Dereference void* to get the actual value
    unsigned long n = *(unsigned long*)input;
    int cnt = 0;   // Counter for the bit transitions
    int prev_bit = 0; // Initialize previous bit as 0

    // Loop to count the number of set bits where previous bit is 0
    while (n)
    {
        // Check if current bit is 1 and the previous bit was 0
        if ((n & 0x01) == 1 && prev_bit == 0)
        {
            cnt++; // Increment count on the transition from 0 to 1
        }

        // Update the previous bit
        prev_bit = n & 0x01;

        // Right shift n by 1 bit (divide by 2) to move to the next bit
        n >>= 1;
    }

    // Print the count of set bits with the required condition
    printf("Number of transitions (0 to 1): %d\n", cnt);
}

int main()
{
    // Example inputs to test the function
    unsigned long num1 = 0x111111111;     // Example input: 111111111 (Binary: 111111111)
    unsigned long num2 = 0xA5A5A5A5A5A5A5A5; // Example input: 10101010 (Binary: 101010)
    unsigned long num3 = 0;                // Input: 0 (Binary: 0)

    void *input1 = &num1;
    void *input2 = &num2;
    void *input3 = &num3;

    // Testing inputs
    printf("Input: 0x%lX\n", num1);
    set_bit_count_from_void(input1); // Count and print the transitions for input1

    printf("Input: 0x%lX\n", num2);
    set_bit_count_from_void(input2); // Count and print the transitions for input2

    printf("Input: 0x%lX\n", num3);
    set_bit_count_from_void(input3); // Count and print the transitions for input3

    return 0;
}

