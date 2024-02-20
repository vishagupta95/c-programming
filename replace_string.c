#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to replace occurrences of a substring in a string
char *replace_str(const char *str, const char *orig, const char *rep) {
    // Find the first occurrence of 'orig' in 'str'
    const char *p = strstr(str, orig);

    // If 'orig' is not found, return the original string
    if (!p) {
        return strdup(str);
    }

    // Calculate the length of the resulting string
    size_t size = strlen(str) + strlen(rep) - strlen(orig) + 1;

    // Allocate dynamic memory for the buffer
    char *buffer = (char *)malloc(size);

    // Check for memory allocation failure
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Copy characters from the start of 'str' to the position just before 'orig'
    strncpy(buffer, str, p - str);
    buffer[p - str] = '\0';

    // Concatenate the replacement string 'rep'
    sprintf(buffer + (p - str), "%s%s", rep, p + strlen(orig));

    // Return the dynamically allocated result
    return buffer;
}

int main(void) {
    // Example usage
    const char *result = replace_str("Hello, world! vishal", "world", "Miami");

    // Print the result
    printf("%s\n", result);

    // Free the dynamically allocated memory
    free((void *)result);

    return 0;
}

