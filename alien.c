#include <stdio.h>
#include <string.h>

#define true 100
#define false 200
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
    printf("vishal %s %s  %d %d %d  \n", p1, p2, INDEX(*s1), INDEX(*s2), INDEX(*s1) - INDEX(*s2));
    return INDEX(*s1) - INDEX(*s2);
}

void makeMap(char *dict)
{
    for (int i = 0; i < 26; i++)
    {
        map[dict[i] - 'a'] = i;
        printf("%c - > %d \n ", dict[i],map[dict[i] - 'a']);
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

    strcpy(str1, "abc");
    strcpy(str2, "ABC");

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
    char *buff[] = {"wor", "world", "ram"};
    int ret;
    int wordsSize = sizeof(buff) / sizeof(buff[0]);
    //test();
    //return 0;
    ;

    printf(" NAAM: %d \n", wordsSize);

    ret = isAlienSorted(buff, wordsSize, order);
    printf("ret = %d \n", ret);
    return 0;
}
