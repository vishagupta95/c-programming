#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*

// CPP program to illustrate strstr()
#include <string.h>
#include <stdio.h>

int main()
{
    // Take any two strings
    char s1[] = "Fun with STL";
    char s2[] = "STL";
    char* p;

    // Find first occurrence of s2 in s1
    p = strstr(s1, s2);

    // Prints the result
    if (p) {
        strcpy(p, "Strings");
        printf("%s", s1);
    } else
        printf("String not found\n");

    return 0;
}

*/

#include <stdio.h>
#include <string.h>

// Structure to store phone book entries
struct PhoneEntry {
    char name[50];
    char phoneNumber[15]; // Assuming phone numbers are up to 15 characters long
};

// Function to search for a phone number by name
const char* findPhoneNumber(const char* name, struct PhoneEntry phoneBook[], int size) {
    for (int i = 0; i < size; i++) {
        if (strstr(phoneBook[i].name, name) != NULL) {
            return phoneBook[i].phoneNumber;
        }
    }
    return "Not Found"; // Return this if the name is not found
}

int main() {
    // Create a simple phone book with a few entries
    struct PhoneEntry phoneBook[] = {
        {"Alice", "123-456-7890"},
        {"Bob", "456-789-1230"},
        {"Charlie", "789-123-4560"},
    };

    int size = sizeof(phoneBook) / sizeof(phoneBook[0]);

    // Prompt the user for a name and look up the phone number
    char searchName[50];
    printf("Enter a name to find the associated phone number: ");
    scanf("%s", searchName);

    const char* phoneNumber = findPhoneNumber(searchName, phoneBook, size);

    if (strcmp(phoneNumber, "Not Found") == 0) {
        printf("Name not found in the phone book.\n");
    } else {
        printf("Phone number for %s: %s\n", searchName, phoneNumber);
    }

    return 0;
}

