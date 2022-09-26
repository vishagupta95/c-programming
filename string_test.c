#include <stdio.h>
#include<stdio.h>                                                                                                                                     
#include<string.h> 
#define MAX 100 

void sortStrings(char arr[][MAX], int n)  
{ 
    char temp[MAX]; 

    // Sorting strings using bubble sort 
    for (int j=0; j<n-1; j++) 
    {   
        for (int i=j+1; i<n; i++) 
        {   
            if (strcmp(arr[j], arr[i]) > 0)  
            {
                strcpy(temp, arr[j]); 
                strcpy(arr[j], arr[i]); 
                strcpy(arr[i], temp); 
            }   
        }   
    }   
}

int test() 
{ 
    char arr[][MAX] = {"GeeksforGeeks","Quiz","Practice","Gblogs","Coding"}; 
    int n = sizeof(arr)/sizeof(arr[0]); 

    sortStrings(arr, n); 

    printf("Strings in sorted order are : "); 
    for (int i=0; i<n; i++) 
        printf("\n String %d is %s", i+1, arr[i]); 
    return 0; 
} 

/// definition of my_strlen() function
// anything before NULL

unsigned int my_strlen(char *p)
{
    unsigned int count = 0;

    while(*p!='\0')
    {
        count++;
        p++;
    }
    return count;
} 

char *my_strcat(char *strg1, char *strg2)
{
    char *start = strg1;

    while(*strg1 != '\0')
    {
        strg1++;
    }

    while(*strg2 != '\0')
    {
        *strg1 = *strg2;
        strg1++;
        strg2++;
    }

    *strg1 = '\0';
    return start;
}



int test() 
{ 
    char arr[][MAX] = {"GeeksforGeeks","Quiz","Practice","Gblogs","Coding"}; 
    int n = sizeof(arr)/sizeof(arr[0]); 

    sortStrings(arr, n); 

    printf("Strings in sorted order are : "); 
    for (int i=0; i<n; i++) 
        printf("\n String %d is %s", i+1, arr[i]); 
    return 0;  
} 

void x_strcpy(char *dest, char *src)
{
    while (*src)
        *dest++ = *src++;
    *dest = '\0';
}

int x_strcmp(char *dest, char *src)
{
    while (*dest == *src)
    {
        {
            if (*dest == '\0')
                return (0);
            dest++;
            src++;
        }
        return (*dest - *src);
    }

}  

void strtok_test ()
{ 
  char str[] ="- This, a @ sample string.";
  char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," , @.-");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, " ,.-");
  }
  return 0;
}  

void strrchr_test ()
{
   const char str[] = "vishal gupta";
   const char ch = 'g';
   char *ret;
    
   ret = strrchr(str, 'g');

   printf("String after |%c| is - |%s|\n", ch, ret);
   
   return(0);
}


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

~            
