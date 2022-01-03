#include <stdio.h>
#include <stdlib.h>
/*
The '0' has an ASCII value of 48. so, we have to add its value to the integer value to convert it into the desired character. The program is as below:
NULL byte is represented by '\0' or '0' (zero) or NULL. A
*/

int main () {
   int a, b;
   int number=7;  
   char charValue=number+'0';
   printf("The value is :%c",charValue);

   a = abs(5);
   printf("value of a = %d\n", a);

   b = abs(-10);
   printf("value of b = %d\n", b);
   
   return(0);
}
