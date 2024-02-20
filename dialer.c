#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to search for contacts based on a partial phone number
char *solution(char *A[], char *B[], int N, char *P)
{
    // Allocate memory dynamically for the result array
    char *dest = malloc(1024);
    if (dest == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the array with zeros
    memset(dest, 0, 1024);

    // Flag to check if there is any matching contact
    int no_match = 1;

    // Iterate through the contacts
    for (int i = 0; i < N; i++)
    {
        // Check if the partial phone number is found in the current contact
        if (strstr(B[i], P))
        {
            // Concatenate the contact name to the result array
            strcat(dest, A[i]);
            strcat(dest, " ");
            no_match = 0;
        }
    }

    // If no matching contact is found, set the result to "NO CONTACT"
    if (no_match == 1)
    {
        strcpy(dest, "NO CONTACT");
    }

    // Return the dynamically allocated result array
    return dest;
}

int main()
{
    // Arrays of contact names and phone numbers
    char *name[] = {"visha", "vishal", "vishal gupta", "vishalgupta95"};
    char *name2[] = {"rishi", "vishal", "vishal gupta", "vishalgupta957"};
    char *phone[] = {"9886983955", "9886983950", "9886983951", "9886983952"};

    // Calculate the size of the arrays
    int size = sizeof(name) / sizeof(name[0]);

    // Print the size of the arrays
    printf("size = %d\n", size);

    // Search for contacts with a partial phone number and print the result
    char *result1 = solution(name, phone, size, "9886");
    printf("%s \n", result1);
    
    char *result2 = solution(name2, phone, size, "9886");
    printf("%s \n", result2);

    // Free the dynamically allocated memory
    free(result1);
    free(result2);

    return 0;
}

