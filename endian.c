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

int main ()
{
  unsigned int x = 77;
  char *c = (char*) &x;

  swap_endian();
 
  printf ("*c is: %d\n", *c);
  if (*c == 0x22)
  {
    printf ("Underlying architecture is little endian. \n");
  }
  else
  {
     printf ("Underlying architecture is big endian. \n");
  }
 
  return 0;
}
