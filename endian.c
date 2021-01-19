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

void Swap endian (big to little) or (little to big)
{
   uint32_t num = 9;
   uint32_t b0,b1,b2,b3;
   uint32_t res;

   b0 = (num & 0x000000ff) << 24u;
   b1 = (num & 0x0000ff00) << 8u;
   b2 = (num & 0x00ff0000) >> 8u;
   b3 = (num & 0xff000000) >> 24u;

   res = b0 | b1 | b2 | b3;

   printf("%" PRIX32 "\n", res);

}

int main ()
{
  unsigned int x = 77;
  char *c = (char*) &x;
 
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
