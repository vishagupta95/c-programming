#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/*
ascii code  48  0   (number zero)        
ascii code  49  1   (number one)        
ascii code  50  2   (number two)        
ascii code  51  3   (number three)        
ascii code  52  4   (number four)        
ascii code  53  5   (number five)        
ascii code  54  6   (number six)        
ascii code  55  7   (number seven)        
ascii code  56  8   (number eight)        
ascii code  57  9   (number nine)        
ascii code  58  :   (Colon)        
ascii code  59  ;   (Semicolon)        
ascii code  60  <   (Less-than sign )        
ascii code  61  =   (Equals sign)        
ascii code  62  >   (Greater-than sign ; Inequality)        
ascii code  63  ?   (Question mark)        
ascii code  64  @   (At sign)        
ascii code  65  A   (Capital A )        
ascii code  66  B   (Capital B 

int charToInt(char c){
    int num = 0;

    //Substract '0' from entered char to get
    //corresponding digit
    num = c - '0';

    return num;
}


int int_toCHar(void)
{
    int number=71;

    char charValue = number+'0';
    printf("The character value is :%c",charValue);

    return 0;


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
    
    /* A zero is same "0" string in all base */
    if (n == 0) {
        s[i] = '0';
        s[i + 1] = '\0';
        return s;
    }

    while (n != 0) {
        s[i++] = abs(n % 10) + '0';
        n = n/10;
    }

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
     
    printf("String : %s \n", my_itoa_new(i, charArray));
    printf("String : %s \n", my_itoa(i, charArray, b));
    return 0;
}
