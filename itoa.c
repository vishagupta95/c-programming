#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int abs_test () {
   int a, b;

   a = abs(5);
   printf("value of a = %d\n", a);

   b = abs(-10);
   printf("value of b = %d\n", b);
  
  /*
value of a = 5
value of b = 10
*/ 
   return(0);
}


/*
'0' refers to the character zero, which has an ASCII value of 48. 
'\0' refers to the null character (ASCII value 0)

*/

void reverse_str(char *s, int len) {
    int i, j;
    char c;

    for (i = 0, j = len-1; i < j; ++i, --j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

char* my_itoa_new(int n, char *s) {
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

char* my_itoa(int num, char* str, int base)
{
    int i = 0;
    bool isNegative = false;
  
    /* A zero is same "0" string in all base */
    if (num == 0) {
        str[i] = '0';
        str[i + 1] = '\0';
        return str;
    }
  
    /* negative numbers are only handled if base is 10 
       otherwise considered unsigned number */
    if (num < 0 && base == 10) {
        isNegative = true;
        num = -num;
    }
  
    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'A' : rem + '0';
        num = num/base;
    }
  
    /* Append negative sign for negative numbers */
    if (isNegative){
        str[i++] = '-';
    }
  
    str[i] = '\0';
 
    reverse_str(str, i);
  
    return str;
}


 
int main() {
    int i, b;
    char charArray[128];
    printf("Enter a number and base\n");
    scanf("%d %d", &i, &b);
     
    printf("String : %s", my_itoa(i, charArray, b));
    return 0;
}
