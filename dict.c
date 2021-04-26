#include <stdio.h>
#include <stdbool.h>

struct entry
{
    char word[15];
    char definition[50];
};

bool equalStrings(char s1[], char s2[])
{
    bool areEqual = false;
    int i = 0;

    while(s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i++;

    if(s1[i] == '\0' && s2[i] == '\0')
        areEqual = true;
    else
        areEqual = false;

    return areEqual;
}

int compareStrings(char s1[], char s2[])
{
    int i = 0, answer;

    while(s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i++;

    if(s1[i] < s2[i])
        answer = -1;
    else if(s1[i] == s2[i])
        answer = 0;
    else 
        answer = 1;

    return answer;
}

int lookup (struct entry dictionary[], char search[],int entries)
{
    int low = 0;
    int high = entries - 1;
    int mid, result;

    while (low <= high)
    {
        mid = (low + high) / 2;
        result = compareStrings (dictionary[mid].word, search);

        if(result == -1)
            low = mid + 1;
        else if(result == 1)
            high = mid - 1;
        else 
            return mid;
    }

    return -1;
}



int main()
{
    struct entry dictionary[100] = 
    {
        {"aardvark", "a burrowing African mammal" },
        {"acumen", " a bottomless pit  "},
        {"addle", "to become confused "},
        {"agar", "a jelly made from seaweed" },
        {"affix", "to append; attach"}
    };

    char word[15];
    int entries = 10;
    int entry;

    printf("Enter word: ");
    scanf("%14s", word);
    entry = lookup (dictionary, word, entries);

    if(entry != -1)
        printf("%s\n", dictionary[entry].definition);
    else
        printf("Sorry, the word %s is not in my dictionary.\n", word);

    return 0;

}