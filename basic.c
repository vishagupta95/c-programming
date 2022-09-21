#include <stdio.h>
#include <stdlib.h>  // malloc etc

/*
*
* char s[]="help";
* strlen(s) should return 4.
* sizeof: Returns the length of the given byte string, include null terminator;
*
* char s[]="help";
* sizeof(s) should return 5
*
* strcpy(ptr2, ptr1) is equivalent to while(*ptr2++ = *ptr1++)
* where as strdup is equivalent to
* ptr2 = malloc(strlen(ptr1)+1);
* strcpy(ptr2,ptr1);
*
*
* 1)  NULL pointer is usually defined as:#define NULL (void *)0                                                                                            
* 2) ASCII character '0' evaluates to 48 or 0x30.
*
* 3)'\0' is defined to be a null character  \0 is 0
*
* ascii code    48  0   (number zero)           
* ascii code    49  1   (number one)            
* ascii code    65  A   (Capital A )            
* ascii code    66  B   (Capital B )            
* ascii code    97  a   (Lowercase  a )         
* ascii code    98  b   (Lowercase  b )         
* ascii code    122 z   (Lowercase  z )     
*
* 4) In C language string is nothing but an array of char 1 byte. Each array is terminated with null character of 1 byte 
*  Integer arrays are not C-style strings, and there is no null-terminator values in them
*
* For me the easiest way was to look at a graph of log2(n), where n
* is the number of nodes in the binary tree. As a table this looks like:

          log2(n) = d

          log2(1) = 0
          log2(2) = 1 
          log2(4) = 2
          log2(8) = 3

and then I draw a little binary tree, this one goes from depth d=0 to d=3:

            d=0          O
                        / \
            d=1        R   B
                      /\   /\
            d=2      R  B R  B
                    /\ /\ /\ /\
            d=3    R B RB RB R B


5) On 32-bit machine sizeof pointer is 32 bits ( 4 bytes), while on 64 bit machine it's 8 byte


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
print_element_names(xmlNode * a_node, char *argt)
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
}
*/



/*
 *
 *
 * #define DUAL_IP_MIN_MTU(x,y,z)       (x)>(y)?((x)>(z)?((y)>(z)?(z):(y)):(y)):((x)>(z)?(z):(x))
 * Pointer arthmatic
 * The answers are:
 * a) int a; // An integer
 *
 * b) int *a; // A pointer to an integer
 *
 * c) int **a; // A pointer to a pointer to an integer
 *
 * d) int a[10]; // An array of 10 integers
 *
 * e) int *a[10]; // An array of 10 pointers to integers
 *
 * f) int (*a)[10]; // A pointer to an array of 10 integers
 *
 * g) int (*a)(int); // A pointer to a function a that takes an integer argument and returns an integer
 *
 * h) int (*a[10])(int); // An array of 10 pointers to functions that take an integer
 * `
 *
 *2D pointer declaratrion

 int **array1 = malloc(nrows * sizeof(int *));
    for(i = 0; i < nrows; i++)
           array1[i] = malloc(ncolumns * sizeof(int));
 *
 */


/* Macro */
#define my_sizeof(type) (char *)(&type + 1) - (char *)(&type)
#define concat(a, b) a##b
#define MAX(i, j) (((i) > (j)) ? i : j)

/*  memseting array*/
static char ZEROARRAY[1024]; // if declaration is in global scope or is static it will alredy be initialized to Zeroes
 OR
char ZEROARRAY[1024] = {0}; // Compiler fills unwritten entries with zeroes
 OR
memset(ZEROARRAY, 0, 1024); // Alternatively you could use memset to initialize the array at program startup:

enum week
{
    Mon,
    Tue,
    Wed,
    Thur,
    Fri,
    Sat,
    Sun
};

int test_condition()
{
    int a = 10;
    return a <= 0 ? 999 : 888;
}

int enum_test()
{
    enum week day = Mon;
    printf("enum_test week day =%d\n",day);
}


int size_test()
{
    enum week day;
    int x = 10;
    char *ptr;
    day = Mon;
    int xy = 40;
    printf("size of integer %d \n", my_sizeof(x));
    printf("concat macro %d", concat(x, y));
    printf("enum init value  = %d fancy return = %d\n", day, test_condition());
    printf("size of int %lu\n", sizeof(int));
    printf("size of long %lu\n", sizeof(long));
    printf("size of double %lu\n", sizeof(double));
    printf("size of long long %lu\n", sizeof(long long));
    printf("size of enum %lu\n", sizeof(day));
    printf("size of ptr %lu\n", sizeof(ptr));
    printf("size of *ptr %lu\n", sizeof(*ptr));
    printf("if x is 10 x++=[%d] x++=[%d] x++=[%d] \n", x++, x++, x++);
    printf("++x=[%d] ++x=[%d]  ++x=[%d] \n", ++x, ++x, ++x);
    //printf("%c", *argv[1]);  - seg fault

    //return 0;

    //int a, b;

    //a = 250;
    //b = 25;

    //cout << "The maximum is " << MAX(a, b) << endl;

    return 0;
}

typedef struct Point
{
    int x;
    int y;
} Point;

int struck_test()
{
    Point p1;
    p1.x = 1;
    p1.y = 3;
    printf("%d \n", p1.x);
    printf("%d \n", p1.y);
    return 0;
}

char *c[] = {"Mahesh", "Ganesh", "999", "333"};
char *a;
char **cp[] = {c + 3, c + 2, c + 1, c};  // size of any array pointer is larger than single pointer
char ***cpp = cp; // size of any array pointer is larger than single pointer

int main(void)
{
    printf("%u %u %u %u %u %u \n", sizeof(a), sizeof(*a), sizeof(c), sizeof(cp), sizeof(cpp), sizeof(char), sizeof(char *));
    printf("a is char pointer ,sizeof(a) = [%u] \n ", sizeof(a));
    printf("a is char pointer ,sizeof(*a) = [%u ]\n ", sizeof(*a));
    printf("c is array of char pointer with 4 elements ,sizeof(c) is [%u] \n ", sizeof(c)); 
    printf("cp is array of double char pointer with 4 elements ,sizeof(cp) is [%u] \n ", sizeof(cp)); 
    printf("cpp is tripple char pointer ,sizeof(cpp) is [%u] \n ", sizeof(cpp)); 
    printf("sizeof(char *)  is [%u] \n ", sizeof(char *)); 
    enum_test();  
    size_test();
    struck_test();
}


