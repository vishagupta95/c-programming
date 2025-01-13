#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to search for contacts based on a partial phone number
char *solution(char *A[], char *B[], int N, char *P)
{
    // Handle edge cases
    if (N <= 0 || P == NULL || strlen(P) == 0) {
        char *dest = malloc(11); // Enough for "NO CONTACT\0"
        if (dest == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        strcpy(dest, "NO CONTACT");
        return dest;
    }

    // Calculate memory needed
    size_t total_size = 1; // For null terminator
    for (int i = 0; i < N; i++) {
        if (strstr(B[i], P)) {
            total_size += strlen(A[i]) + 1; // Name + space
        }
    }

    // Allocate memory
    char *dest = malloc(total_size);
    if (dest == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    dest[0] = '\0'; // Initialize empty string

    // Iterate through contacts
    int no_match = 1;
    for (int i = 0; i < N; i++) {
        if (strstr(B[i], P)) {
            strcat(dest, A[i]);
            strcat(dest, " ");
            no_match = 0;
        }
    }

    // Handle no match case
    if (no_match) {
        strcpy(dest, "NO CONTACT");
    } else {
        dest[strlen(dest) - 1] = '\0'; // Remove trailing space
    }

    return dest;
}

int main()
{
    // Arrays of contact names and phone numbers
    char *name[] = {"visha", "vishal", "vishal gupta", "vishalgupta95"};
    char *phone[] = {"9886983955", "9886983950", "9886983951", "9886983952"};

    int size = sizeof(name) / sizeof(name[0]);
    printf("size = %d\n", size);

    // Search for contacts
    char *result1 = solution(name, phone, size, "9886");
    printf("%s\n", result1);
    free(result1);

    // Example with no match
    char *result2 = solution(name, phone, size, "1234");
    printf("%s\n", result2);
    free(result2);

    return 0;
}

