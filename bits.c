#include <stdio.h>
#include <stdlib.h>


/* XOR
XOR Operation Rules:
For each bit pair (A, B), the XOR result (A ^ B) follows these rules:

0 ^ 0 = 0 (Both bits are the same, result is 0)
0 ^ 1 = 1 (Bits are different, result is 1)
1 ^ 0 = 1 (Bits are different, result is 1)
1 ^ 1 = 0 (Both bits are the same, result is 0)
*/

#define BIT_SET(n, p) (n |= (1 << p))
#define BIT_CLR(n, p) (n &= ~(1 << p))
#define BIT_RESET(n, p) (n ^= (1 << p))

#define NIBBLE_CHANGE(x) (((x & 0x0F) << 4) | ((x & 0xF0) >> 4))
#define SWAP_INT32(x) (((x) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | ((x) << 24))

void print_binary(unsigned int num) {
    int i;
    printf ("\nBinary print :");
    for (i = sizeof(num) * 8 - 1; i >= 0; i--) {
        (num & (1 << i)) ? printf("1") : printf("0");
    }
    printf ("\n");
}

void test_swap_int32()
{
    unsigned int x = 0x12345678;
    unsigned int swapped_x = SWAP_INT32(x);
    printf("Original x = %x, Swapped x = %x\n", x, swapped_x);
}

void test_fd_macros()
{
    unsigned int n = 0xFFFFFFFF;
    printf("\nTesting BIT_SET, BIT_CLR, BIT_RESET on n = %x\n", n);
    print_binary(n);

    BIT_SET(n, 2);  // Set bit 2
    printf("After BIT_SET(2): %x\n", n);
    print_binary(n);

    BIT_CLR(n, 3);  // Clear bit 3
    printf("After BIT_CLR(3): %x\n", n);
    print_binary(n);

    BIT_RESET(n, 4);  // Reset bit 4
    printf("After BIT_RESET(4): %x\n", n);
    print_binary(n);
}

void test_nibble_change()
{
    unsigned char data = 0x23;
    unsigned char changed_data = NIBBLE_CHANGE(data);
    printf("\n NIBBLE change Original data = %x, Changed data = %x\n", data, changed_data);
}

void set_bit_count_old()
{
    unsigned int n = 0xF;
    unsigned int cnt = 0;
    while (n)
    {
        if (n & 0x01) cnt++;
        n >>= 1;
    }
    printf("\nset_bit_count_old result: %u\n", cnt);
}

void set_bit_count()
{
    unsigned int n = 39;
    unsigned int count = 0;

    while (n)
    {
        count++;
        n = n & (n - 1);
    }
    printf("set_bit_count result: %u\n", count);
}

unsigned int reverseBits(unsigned int num)
{
    unsigned int NO_OF_BITS = sizeof(num) * 8;
    unsigned int reverse_num = 0, i, temp;

    for (i = 0; i < NO_OF_BITS; i++)
    {
        temp = (num & (1 << i));
        if (temp)
            reverse_num |= (1 << ((NO_OF_BITS - 1) - i));
    }

    return reverse_num;
}

unsigned int mod_bits(unsigned int x, unsigned int pos, unsigned int val)
{
    unsigned int mask = 1 << pos;
    return ((x & ~mask) | ((val << pos) & mask));
}

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


// Function to count the number of 1s in the binary representation of a number
int countSetBits(unsigned int n) {
    int count = 0;
    while (n) {
        count += n & 1;  // Increment count if the last bit is 1
        n >>= 1;          // Right shift n to check the next bit
    }
    return count;
}

// Function to find the number of bits required to convert a to b
int bitsRequiredToConvert(unsigned int a, unsigned int b) {
    // XOR a and b to get the positions where bits differ
    unsigned int xor = a ^ b;
    
    // Count the number of 1s in the XOR result (bits that are different)
    return countSetBits(xor);
}

int main1() {
    unsigned int a = 29;  // Example integer a (binary: 11101)
    unsigned int b = 15;  // Example integer b (binary: 01111)

    printf("Number of bits required to convert %u to %u: %d\n", a, b, bitsRequiredToConvert(a, b));

    return 0;
}


//C Code to Swap Odd and Even Bits:
unsigned int swapOddEvenBits(unsigned int n) {
    // Mask for even bits (0x55555555): binary pattern 01010101010101010101010101010101
    unsigned int evenBits = n & 0xAAAAAAAA; // Mask for odd bits (binary pattern 10101010101010101010101010101010)
    unsigned int oddBits = n & 0x55555555;

    // Right shift the even bits and left shift the odd bits
    evenBits >>= 1;
    oddBits <<= 1;

    // Combine the even and odd bits
    return (evenBits | oddBits);
}

int main2() {
    unsigned int n = 23;  // Example number, binary: 10111

    printf("Before swapping bits: %u (binary: %b)\n", n, n);
    
    n = swapOddEvenBits(n);

    printf("After swapping odd and even bits: %u (binary: %b)\n", n, n);

    return 0;
}

// C function that sets the bits between positions i and j in N to the bits of M:
void setBitsInRange(int *N, int M, int i, int j) {
    // Create a mask to clear bits between i and j in N
    int mask = ((1 << (j - i + 1)) - 1) << i;
    
    // Clear the bits in N between i and j and set the bits from M
    *N = (*N & ~mask) | ((M << i) & mask);
}

int main3() {
    int N = 1024;  // Example value for N
    int M = 19;    // Example value for M
    int i = 2;     // Start bit position
    int j = 6;     // End bit position

    printf("Before setting bits:\nN = %d\n", N);
    
    // Set bits between i and j in N to M
    setBitsInRange(&N, M, i, j);

    printf("After setting bits between position %d and %d in N to M:\nN = %d\n", i, j, N);

    return 0;
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
    print_binary(num1);
    set_bit_count_from_void(input1); // Count and print the transitions for input1


    printf("Input: 0x%lX\n", num2);
    print_binary(num2);
    set_bit_count_from_void(input2); // Count and print the transitions for input2

    printf("Input: 0x%lX\n", num3);
    print_binary(num3);
    set_bit_count_from_void(input3); // Count and print the transitions for input3


    test_swap_int32();      // Test the SWAP_INT32 macro
    test_fd_macros();       // Test BIT_SET, BIT_CLR, BIT_RESET macros
    test_nibble_change();   // Test NIBBLE_CHANGE macro

    set_bit_count_old();    // Test set_bit_count_old
    set_bit_count();        // Test set_bit_count

    unsigned int num = 0xFFFFEEEE;
    unsigned int reversed_num = reverseBits(num);  // Test reverseBits
    printf("Original num = %x, Reversed num = %x\n", num, reversed_num);
    print_binary(num);
    print_binary(reversed_num);

    unsigned int mod_result = mod_bits(num, 8, 1); // Test mod_bits
    printf("Original num = %x, Modified num = %x\n", num, mod_result);
    print_binary(num);
    print_binary(mod_result);

    main1();
    main2();
    main3();
    return 0;
}

