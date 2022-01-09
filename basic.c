#include <stdio.h>
#define my_sizeof(type) (char *)(&type + 1) - (char *)(&type)
#define concat(a, b) a##b
#define MAX(i, j) (((i) > (j)) ? i : j)


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

