#include <stdio.h>
#include <string.h>

/* -----------------------------------------------------------------------------
 * Question 2: implment a function to reverse a string
 * input: str
 * output: str
 * return value: 0 for success, none zero for error
 */

unsigned int my_strlen(char *p)
{
    unsigned int count = 0;
    while (*p != '\0')
    {
        count++;
        p++;
    }
    return count;
}

// Function to reverse a C-string without using pointers arithmetic
void reverse_str(char *str)
{
    // get length of the string
    int n = my_strlen(str);
    printf(" vishal %d \n",n);

    // start swapping characters from both ends of the string
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        char ch = str[i];
        str[i] = str[j];
        str[j] = ch;
    }
}
//dd

int main()
{
    char buf[80];
    strcpy(buf, "vishal");
    reverse_str(buf);
    printf("The reversed string is: %s\n", buf);
    return 0;
}
