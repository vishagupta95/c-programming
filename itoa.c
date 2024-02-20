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
#include <stdio.h>

// Function to reverse a string
void reverseString(char str[], int length) {
    int start = 0;
    int end = length - 1;

    while (start < end) {
        // Swap characters
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        // Move towards the center
        start++;
        end--;
    }
}

// Function to convert an integer to a string in base 10
void my_itoa(int num, char str[]) {
    int i = 0;
    int isNegative = 0;

    // Handle 0 explicitly, otherwise an empty string is returned
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    // Handle negative numbers
    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    // Process individual digits
    while (num != 0) {
        int rem = num % 10;
        str[i++] = rem + '0';
        num = num / 10;
    }

    // Append negative sign if the number was negative
    if (isNegative)
        str[i++] = '-';

    str[i] = '\0';  // Null-terminate the string

    // Reverse the string
    reverseString(str, i);
}

int main() {
    int num = -12345;
    char str[20]; // Assuming a reasonable size for the string buffer

    my_itoa(num, str);

    printf("Integer: %d\nString: %s\n", num, str);

    return 0;
}

