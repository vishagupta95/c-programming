#include <stdio.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26

// Trie node structure
struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    int isEndOfWord;
};

// Function to create a new TrieNode
struct TrieNode* createNode() {
    struct TrieNode* newNode = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    
    if (newNode) {
        newNode->isEndOfWord = 0;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            newNode->children[i] = NULL;
        }
    }

    return newNode;
}

// Function to insert a word into the trie
void insert(struct TrieNode* root, const char* word) {
    struct TrieNode* currentNode = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (!currentNode->children[index]) {
            currentNode->children[index] = createNode();
        }

        currentNode = currentNode->children[index];
    }

    currentNode->isEndOfWord = 1;
}

// Function to search for a word in the trie
int search(struct TrieNode* root, const char* word) {
    struct TrieNode* currentNode = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (!currentNode->children[index]) {
            return 0; // Word not found
        }

        currentNode = currentNode->children[index];
    }

    return (currentNode != NULL && currentNode->isEndOfWord);
}

int main() {
    // Example usage
    struct TrieNode* root = createNode();

    // Insert words into the trie
    insert(root, "apple");
    insert(root, "app");
    insert(root, "banana");

    // Search for words in the trie
    printf("Search for 'apple': %s\n", search(root, "apple") ? "Found" : "Not Found");
    printf("Search for 'app': %s\n", search(root, "app") ? "Found" : "Not Found");
    printf("Search for 'orange': %s\n", search(root, "orange") ? "Found" : "Not Found");

    return 0;
}

