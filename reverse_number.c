#include <stdio.h>

int reverse_number(int num) {
    int reversed = 0;
    while (num != 0) {
        int digit = num % 10;        // Extract the last digit
        reversed = reversed * 10 + digit; // Build the reversed number
        num /= 10;                  // Remove the last digit from the number
    }
    return reversed;
}

int main() {
    int num;

    // Input the number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Handle negative numbers
    int is_negative = 0;
    if (num < 0) {
        is_negative = 1;
        num = -num;  // Work with the absolute value of the number
    }

    // Reverse the digits
    int reversed = reverse_number(num);

    // If the original number was negative, make the reversed number negative
    if (is_negative) {
        reversed = -reversed;
    }

    // Output the reversed number
    printf("Reversed number: %d\n", reversed);

    return 0;
}

