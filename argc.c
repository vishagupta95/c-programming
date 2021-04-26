#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{ 
   int sum = 0, i; 
 
   for (i=1; i< argc; i++) 
      sum += atoi(argv[i]); /* could have used *++argv */
 
   printf("%d\n", sum); 
   return 0; 
} 