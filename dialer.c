#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *solution(char *A[], char *B[], int N, char *P)
{
    static char array[1024] ={};
    char *dest = &array[0];
    memset(dest, 0, sizeof(2048));
    int no_match = 1;

    for (int i = 0; i < N; i++)
    {
        if (strstr(B[i], P))
        {
            strcat(dest, A[i]);
            strcat(dest, " ");
            no_match = 0;
        }
    }

    if (no_match == 1)
    {
        strcpy(dest, "NO CONTACT");
    }

    return dest;
}

int main()
{
    char *name[] = {"visha", "vishal", "vishal gupta", "vishalgupta95"};
    char *name2[] = {"rishi", "vishal", "vishal gupta", "vishalgupta957"};
    char *phone[] = {"9886983955", "9886983950", "9886983951", "9886983952"};
    int argc = sizeof(name) / sizeof(name[0]);
    printf("argc = %d\n ", argc);
    printf("%s \n",solution(name, phone, argc, "9886"));
    printf("%s \n",solution(name2, phone, argc, "9886"));
    return 0;
}
