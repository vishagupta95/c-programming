#include <stdio.h>
#include <stdbool.h>
#include <string.h>
/*
 The program generates all unique permutations of a string using a 
  backtracking algorithm.
  Total Permutations: For a string of length n, there are 
  n! permutations.
  Duplicate Handling: The shouldSwap function adds additional checks. 
 O(n×n!).
*/

// Function to swap two characters
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Function to check if swapping str[start] with str[current] is valid
bool shouldSwap(char str[], int start, int current) {
    for (int i = start; i < current; i++) {
        if (str[i] == str[current]) {
            return false; // Duplicate found, no need to swap
        }
    }
    return true;
}

// Function to print all unique permutations of a string
void printPermutations(char str[], int start, int end) {
    if (start == end) {
        // Base case: When we reach the end of the string, print the permutation
        printf("%s\n", str);
    } else {
        // Recursive case: Generate permutations by swapping characters
        for (int i = start; i <= end; i++) {
            // Check if swapping str[start] with str[i] is valid
            if (shouldSwap(str, start, i)) {
                // Swap the current character with itself and all subsequent characters
                swap(&str[start], &str[i]);
                
                // Recursively generate permutations for the remaining characters
                printPermutations(str, start + 1, end);
                
                // Restore the string to its original state (backtrack)
                swap(&str[start], &str[i]);
            }
        }
    }
}

int main() {
    char str[] = "ABCD";
    int n = strlen(str);

    printf("All unique permutations of the string:\n");
    printPermutations(str, 0, n - 1);

    return 0;
}

