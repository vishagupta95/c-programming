#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 *
 * strlen: Returns the length of the given byte string not including null terminator;
 *
 * char s[]="help";
 * strlen(s) should return 4.
 * sizeof: Returns the length of the given byte string, include null terminator;
 *
 * char s[]="help";
 * sizeof(s) should return 5
 *
 * strcpy(ptr2, ptr1) is equivalent to while(*ptr2++ = *ptr1++)
 *
 * where as strdup is equivalent to
 *
 * ptr2 = malloc(strlen(ptr1)+1);
 * strcpy(ptr2,ptr1);
 */
int main()
{
    char source[] = "GeeksForGeeks";

    // A copy of source is created dynamically
    // and pointer to copy is returned.
    char* target = strdup(source);

    printf("%s", target);
    return 0;
}

