#include <stdio.h>
#include <stdlib.h>  // malloc etc

/*
*
*
*  NULL pointer is usually defined as:#define NULL (void *)0
*  ASCII character '0' evaluates to 48 or 0x30.
* '\0' is defined to be a null character  \0 is 0
* ascii code    48  0   (number zero)           
* ascii code    49  1   (number one)            
* ascii code    50  2   (number two)            
* ascii code    51  3   (number three)          
* ascii code    52  4   (number four)           
* ascii code    53  5   (number five)           
* ascii code    54  6   (number six)            
* ascii code    55  7   (number seven)          
* ascii code    56  8   (number eight)          
* ascii code    57  9   (number nine)           
* ascii code    58  :   (Colon)         
* ascii code    59  ;   (Semicolon)         
* ascii code    60  <   (Less-than sign )           
* ascii code    61  =   (Equals sign)           
* ascii code    62  >   (Greater-than sign ; Inequality)            
* ascii code    63  ?   (Question mark)         
* ascii code    64  @   (At sign)           
* ascii code    65  A   (Capital A )            
* ascii code    66  B   (Capital B )            
* ascii code    67  C   (Capital C )            
* ascii code    68  D   (Capital D )            
* ascii code    69  E   (Capital E )            
* ascii code    70  F   (Capital F )            
* ascii code    71  G   (Capital G )            
* ascii code    72  H   (Capital H )            
* ascii code    73  I   (Capital I )            
* ascii code    74  J   (Capital J )            
* ascii code    75  K   (Capital K )            
* ascii code    76  L   (Capital L )            
* ascii code    77  M   (Capital M )            
* ascii code    78  N   (Capital N )            
* ascii code    79  O   (Capital O )            
* ascii code    80  P   (Capital P )            
* ascii code    81  Q   (Capital Q )            
* ascii code    82  R   (Capital R )            
* ascii code    83  S   (Capital S )            
* ascii code    84  T   (Capital T )            
* ascii code    85  U   (Capital U )            
* ascii code    86  V   (Capital V )            
* ascii code    87  W   (Capital W )            
* ascii code    88  X   (Capital X )            
* ascii code    89  Y   (Capital Y )            
* ascii code    90  Z   (Capital Z )            
* ascii code    91  [   (square brackets or box brackets)           
* ascii code    92  \   (Backslash)         
* ascii code    93  ]   (square brackets or box brackets)           
* ascii code    94  ^   (Caret or circumflex accent)            
* ascii code    95  _   (underscore , understrike , underbar or low line)           
* ascii code    96  `   (Grave accent)          
* ascii code    97  a   (Lowercase  a )         
* ascii code    98  b   (Lowercase  b )         
* ascii code    99  c   (Lowercase  c )         
* ascii code    100 d   (Lowercase  d )         
* ascii code    101 e   (Lowercase  e )         
* ascii code    102 f   (Lowercase  f )         
* ascii code    103 g   (Lowercase  g )         
* ascii code    104 h   (Lowercase  h )         
* ascii code    105 i   (Lowercase  i )         
* ascii code    106 j   (Lowercase  j )         
* ascii code    107 k   (Lowercase  k )         
* ascii code    108 l   (Lowercase  l )         
* ascii code    109 m   (Lowercase  m )         
* ascii code    110 n   (Lowercase  n )         
* ascii code    111 o   (Lowercase  o )         
* ascii code    112 p   (Lowercase  p )         
* ascii code    113 q   (Lowercase  q )         
* ascii code    114 r   (Lowercase  r )         
* ascii code    115 s   (Lowercase  s )         
* ascii code    116 t   (Lowercase  t )         
* ascii code    117 u   (Lowercase  u )         
* ascii code    118 v   (Lowercase  v )         
* ascii code    119 w   (Lowercase  w )         
* ascii code    120 x   (Lowercase  x )         
* ascii code    121 y   (Lowercase  y )         
* ascii code    122 z   (Lowercase  z )     
*
*  In C language string is nothing but an array of char 1 byte. Each array is terminated with null character of 1 byte 
*  Integer arrays are not C-style strings, and there is no null-terminator values in them
*
*/


/* coding Guideline
 *
 * 1.   main and other functions should start with a curly brace on a new  line
 * 2.   Use 4 space gap after the start of function or while loop on a new  line
 * 3.   Use  single space before and after every variable  assignment 
 * 4.   Inside a for loop space immediately after first and second semicolon
 * 5.   Space after if  before bracket 
 * 6.   Space after for loop  before bracket 
 * 7.   Space after while loop  before bracket 

static void
print_element_names(xmlNode * a_node)
{
    xmlNode *cur_node = NULL;

    for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
        if (cur_node->type == XML_ELEMENT_NODE) {
            printf("node type: Element, name: %s\n", cur_node->name);
        }

        print_element_names(cur_node->children);
    }

    while (ret == 1) {
       ret = xmlTextReaderRead(reader);
    }
}

int
main(int argc, char **argv)
{
    xmlDoc *doc = NULL;
    xmlNode *root_element = NULL;

    if (argc != 2)
        return(1);
*/



/* C program to demonstrate how to pass array of integer to a function*/

void displayString(char **argv,char *argt[], int argc, char *array, char array2[])
{

    int i = 0;
    char *strg1 = array;
     
 
    printf("String test  Method 1\n\n");
    
    for (i = 0; i < argc; i++)
    {
        printf("String [%d] : %s \n", i + 1, argv[i]);
    }
    
    printf("String test  Method 2\n\n");
    
    for (i = 0; i < argc; i++)
    {
        printf("A-String [%d] : %s \n", i + 1, argt[i]);
    }

    printf("String test  Method 3\n\n");

    for (i = 0; i < array[i] != '\0'; i++)
    {
        printf("array [%d] : %c\n", i + 1, array[i]);
    }

    printf("String test  Method 4\n\n");
    for (i = 0; i < array2[i] != '\0'; i++)
    {
        printf("array [%d] : %c\n", i + 1, array[i]);
    }

    printf("String test  Method 5\n\n");
    // loooping array of characters
    i = 0;
    while (*strg1 != '\0')
       printf("new array [%d] : %c\n", ++i, *strg1++);

}

int displayString_test()
{
    char array[] = "king";
    char *buff[] = {"aap", "bap", "cat", "dog"};
    int argc = sizeof(buff) / sizeof(buff[0]);
    printf("argc = %d\n ", argc);
    displayString(buff, buff, argc, array, array);
    return 0;
}


double getIntegerAverage1(int x[], int argc)
{
    int i = 0;
    double j;
    for (i = 0; i < argc; i++)
    {
        j += x[i]; //imp
    }
    return (j / argc);
}

double getIntegerAverage2(int *x, int argc)
{
    int i = 0;
    double j;
    for (i = 0; i < argc; i++)
    {
        j += x[i];
    }
    return (j / argc);
}

int main()
{

    /* an int array with 5 elements */
    int balance[] = {14, 16, 18, 20, 22};
    double avg;
    printf("\\0 is %d\n", '\0');
    printf("0 is %d\n", '0');

    displayString_test();
    
    int argc = sizeof(balance) / sizeof(balance[0]);
    printf("sizeof(balance) %d \n", sizeof(balance));
    printf("sizeof(balance[0]) %d \n", sizeof(balance[0]));
    printf("argc =%d \n", argc);
    /* pass pointer to the array as an argument */
    
    avg = getIntegerAverage1(balance, argc);
    printf("Average value is: %f  \n", avg);

    avg = getIntegerAverage1(balance, argc);
    printf("Average value is: %f \n ", avg);

    avg = getIntegerAverage2(balance, argc);
    printf("Average value is: %f \n", avg);
    return 0;
}
