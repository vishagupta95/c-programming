#include <stdio.h>
#include <string.h>
#include <math.h>

void reverse_str(char *s, int len) {
    int i, j;
    char c;

    for (i = 0, j = len-1; i < j; ++i, --j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

char* my_itoa(int n, char *s) {
    int i = 0, sign = n;

    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse_str(s, i);
    return s;
}
