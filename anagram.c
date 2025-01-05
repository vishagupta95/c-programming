#include <stdio.h>
#include <string.h>

// Function to check if two strings are anagrams
int areAnagrams(const char *str1, const char *str2) {
    int count[256] = {0}; // Assuming ASCII characters

    // Lengths of both strings should be the same for them to be anagrams
    if (strlen(str1) != strlen(str2)) {
        return 0; // Not anagrams
    }

    // Count occurrences of characters in the first string
    for (int i = 0; str1[i] != '\0'; i++) {
        count[(int)str1[i]]++;
    }

    // Subtract occurrences of characters in the second string
    for (int i = 0; str2[i] != '\0'; i++) {
        count[(int)str2[i]]--;
    }

    // If the strings are anagrams, all counts should be zero
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return 0; // Not anagrams
        }
    }

    return 1; // Anagrams
}

int main() {
    char str1[100], str2[100];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    if (areAnagrams(str1, str2)) {
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are not anagrams.\n");
    }

    return 0;
}
#if 0

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool are_anagrams(string str1, string str2) {
    // If the lengths of the two strings are different, they cannot be anagrams
    if (str1.length() != str2.length()) {
        return false;
    }

    // Sort both strings
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    // Compare the sorted strings
    return str1 == str2;
}

int main() {
    string str1 = "listen";
    string str2 = "silent";

    if (are_anagrams(str1, str2)) {
        cout << "'" << str1 << "' and '" << str2 << "' are anagrams." << endl;
    } else {
        cout << "'" << str1 << "' and '" << str2 << "' are not anagrams." << endl;
    }

    return 0;
}
#endif
