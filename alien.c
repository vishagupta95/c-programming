#include <stdbool.h>
#include <string.h>

bool isAlienSorted(char **words, int wordsSize, char *order) {
    int mapping[26]; // Mapping of the alien alphabet to English alphabet

    // Create the mapping
    for (int i = 0; i < 26; i++) {
        mapping[order[i] - 'a'] = i;
    }

    // Function to compare two words based on the alien alphabet
    int compareWords(char *word1, char *word2) {
        int len1 = strlen(word1);
        int len2 = strlen(word2);
        int minLen = len1 < len2 ? len1 : len2;

        for (int i = 0; i < minLen; i++) {
            int char1 = mapping[word1[i] - 'a'];
            int char2 = mapping[word2[i] - 'a'];
            if (char1 < char2) {
                return -1;  // word1 is smaller than word2
            } else if (char1 > char2) {
                return 1;  // word1 is greater than word2
            }
        }

        // If all characters are equal till the length of the shorter word, 
        // the shorter word should come first.
        if (len1 < len2) {
            return -1;
        } else if (len1 > len2) {
            return 1;
        }
        return 0;  // words are equal
    }

    // Compare each consecutive pair of words
    for (int i = 0; i < wordsSize - 1; i++) {
        if (compareWords(words[i], words[i + 1]) > 0) {
            return false;  // words[i] is greater than words[i + 1]
        }
    }

    return true;  // All words are in sorted order
}
#include <stdio.h>

int main() {
    char *words[] = {"apple", "app"};
    int wordsSize = 2;
    char *order = "abcdefghijklmnopqrstuvwxyz";
    bool result = isAlienSorted(words, wordsSize, order);
    printf("Is sorted: %s\n", result ? "True" : "False");
    return 0;
}

