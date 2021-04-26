#include <stdio.h>

//
/* const char *ptr : This is a pointer to a constant character. 
* There is no difference between const char *p and char const *p
 *as both are pointer to a const char 
 * You cannot change the value pointed by ptr, but you can 
 * change the pointer itself. 
*/

//int mystrcmp(const char *p1, const char *p2) most common
int ptr_to_const_func(const char *ptr1, char const *ptr2)
{
    char m1;
    //*ptr1='A'; illegal statement (assignment of read-only location *ptr)
    //*ptr2='A'; illegal statement (assignment of read-only location *ptr)
}

/*This is a constant pointer to non-constant character. You cannot change the pointer p, 
 * but can change the value pointed by ptr.
 */

int const_ptr_to_func(char *const ptr1, char *const ptr2)
{
    char m1;
    *ptr1 = 'A';
    *ptr2 = 'B';
    //ptr1 =&m1; assignment of read-only parameter 'ptr1'
}

void main()
{

    char v1 = 'a';
    char v2 = 'b';
    char *ptr1 = &v1;
    char *ptr2 = &v2;
    ptr_to_const_func(ptr1, ptr2);
    const_ptr_to_func(ptr1, ptr2);
    printf("%c %c \n", *ptr1, *ptr2);
}
