#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Helper function to compare two words using the mapping
int compare(char *word1, char *word2, int mapping[]) {
    while (*word1 != '\0' && *word2 != '\0') {
        if (mapping[*word1 - 'a'] < mapping[*word2 - 'a']) {
            return -1;
        } else if (mapping[*word1 - 'a'] > mapping[*word2 - 'a']) {
            return 1;
        }
        word1++;
        word2++;
    }

    if (*word1 == '\0' && *word2 != '\0') {
        return -1;
    } else if (*word1 != '\0' && *word2 == '\0') {
        return 1;
    }

    return 0;
}

// Function to check if words are sorted in alien language
bool isAlienSorted(char **words, int wordsSize, char *order) {
    int mapping[26]; // Mapping of the alien alphabet to English alphabet

    // Create the mapping
    for (int i = 0; i < 26; i++) {
        mapping[order[i] - 'a'] = i;
    }

    // Check if words are sorted
    for (int i = 0; i < wordsSize - 1; i++) {
        if (compare(words[i], words[i + 1], mapping) > 0) {
            return false;
        }
    }

    return true;
}

int main() {
    char *words[] = {"hello", "leetcode"};
    int wordsSize = 2;
    char order[] = "hlabcdefgijkmnopqrstuvwxyz";

    if (isAlienSorted(words, wordsSize, order)) {
        printf("The words are sorted in the alien language.\n");
    } else {
        printf("The words are not sorted in the alien language.\n");
    }

    return 0;
}

