#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define bool int

/*
leets Code
In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet 
is some permutation of lowercase letters.Given a sequence of words written in the alien language, and the order 
of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.
*/

int map[26];
#define INDEX(c) (('\0' == c) ? -1 : map[c - 'a'])

int mystrcmp(const char *p1, const char *p2)
{
    const char *s1 = p1;
    const char *s2 = p2;

    while (*s1 && *s2 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    //printf("mystrcmp word1: %s Index:%d word2 %s index %d  diffrence %d  \n", p1, INDEX(*s1), p2, INDEX(*s2), INDEX(*s1) - INDEX(*s2));
    return INDEX(*s1) - INDEX(*s2);
}

void makeMap(char *dict)
{
    for (int i = 0; i < 26; i++)
    {
        map[dict[i] - 'a'] = i;
    }
}

bool isAlienSorted(char **words, int wordsSize, char *order)
{
    makeMap(order);
    if (wordsSize < 2)
    {
        return true;
    }
    for (int i = 1; i < wordsSize; i++)
    {
        if (mystrcmp(words[i - 1], words[i]) > 0)
            return false;
    }
    return true;
}

int test()
{
    char str1[15];
    char str2[15];
    int ret;

    strcpy(str1, "abce");
    strcpy(str2, "abcd");

    printf("strlen of %s is %d size of str1 %d \n ", str1, strlen(str1), sizeof(str1));

    ret = strcmp(str1, str2);

    if (ret < 0)
    {
        printf("%s is less than %s \n", str1, str2);
    }
    else if (ret > 0)
    {
        printf("%s is less than %s \n", str2, str1);
    }
    else
    {
        printf("str1 is equal to str2 \n");
    }

    return (0);
}

int main()
{
    char order[] = "abcdefghijklmnopqrstuvwxyz";
    char *buff[] = {"a", "ab", "d", "f"};
    int ret;
    int wordsSize = sizeof(buff) / sizeof(buff[0]);
    // test();

    printf(" Word Count: %d \n", wordsSize);

    ret = isAlienSorted(buff, wordsSize, order);

    if (ret > 0)
    {
        printf("words are sorted lexicographicaly \n");
    }
    else
    {
        printf("words are not sorted lexicographicaly \n");
    }

  

    return 0;
}
