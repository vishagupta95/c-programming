#include <stdio.h>

/*
 *
 * nt x = 77;
 * char *c = (char*) &x;
 *
 * Big endian format:
 * ------------------
 *  Byte address  | 0x01 | 0x02 | 0x03 | 0x04 | 
 *  +++++++++++++++++++++++++++++
 *  Byte content  | 0x76 | 0x54 | 0x32 | 0x10 |
 *                           
 *  Little endian format:
 *  ---------------------
 *  Byte address  | 0x01 | 0x02 | 0x03 | 0x04 | 
 *  +++++++++++++++++++++++++++++
 *  Byte content  | 0x10 | 0x32 | 0x54 | 0x76 |
 *
 */

void swap_endian()
{
   unsigned int num = 0X12345678;
   unsigned int b0 ,b1 ,b2,b3;
   unsigned int res;

   b0 = (num & 0x000000ff) << 24u;
   b1 = (num & 0x0000ff00) << 8u;
   b2 = (num & 0x00ff0000) >> 8u;
   b3 = (num & 0xff000000) >> 24u;

   res = b0 | b1 | b2 | b3;

   printf("%x \n", res);

}

#define BIG_ENDIAN      0
#define LITTLE_ENDIAN   1
int TestByteOrder()
{
   short int word = 0x0001;
   char *byte = (char *) &word;
   return(byte[0] ? LITTLE_ENDIAN : BIG_ENDIAN);
}

/* 
 *    Function check_for_endianness() returns 1, if architecture 
 *       is little endian, 0 in case of big endian.
 *        */
 
int check_for_endianness()
{
  unsigned int x = 1;
  char *c = (char*) &x;
  return (int)*c;
}

/* 
 *   Write a C program to find out if the underlying 
 *   architecture is little endian or big endian. 
 *   */
int main()
{

  union
  {
    int i;
    char c[sizeof(int)];
  } x;
  x.i = 1;
  if (x.c[0] == 1)
    printf("little-endian\n");
  else
    printf("big-endian\n");

} 
