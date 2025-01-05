#include <stdio.h>
#include <stdint.h>

// Function to demonstrate casting of void* to various types
void demonstrate_casts(void *ptr1, void *ptr2, void *ptr3, void *ptr4) {
    // Cast ptr1 to int*
    int *int_ptr = (int *)ptr1;
    printf("As int*: %p, dereferenced value: %d\n", int_ptr, *int_ptr);

    // Cast ptr2 to unsigned long
    unsigned long ulong_value = (unsigned long)ptr2;
    printf("As unsigned long: %lu\n", ulong_value);

    // Cast ptr3 to char*
    char *char_ptr = (char *)ptr3;
    printf("As char*: %p, dereferenced value: %c\n", char_ptr, *char_ptr);

    // Cast ptr4 to int and interpret as an integer value
    int int_value = (int)(uintptr_t)ptr4; // Safe conversion using uintptr_t
    printf("As int (interpreted pointer value): %d\n", int_value);
}

int main() {
    // Example 1: An integer variable
    int x = 42;
    void *void_ptr1 = &x;

    // Example 2: A memory address as unsigned long (example purpose)
    unsigned long address = 0x7ffee5366abc;
    void *void_ptr2 = (void *)address;

    // Example 3: A character variable
    char y = 'A';
    void *void_ptr3 = &y;

    // Example 4: An integer value interpreted as a pointer
    void *void_ptr4 = (void *)(uintptr_t)123456; // Example pointer value

    // Call function to demonstrate casting
    demonstrate_casts(void_ptr1, void_ptr2, void_ptr3, void_ptr4);

    return 0;
}

