#include <stdio.h>


#define FD_SET(n, p) (n |= (1 << p))
#define FD_CLR(n, p) (n &= ~(1 << p))
#define FD_RESET(n, p) (n ^= (1 << p))

/* little to big endian */
#define SWAP_INT32(x) (((x) >> 24) | (((x)&0x00FF0000) >> 8) | (((x)&0x0000FF00) << 8) | ((x) << 24))


void set_bit_count_old()
{
  int n =0xF;
  int cnt=0;
  while(n)
  {
    if(n & 0x01)cnt++;
       n>>=1;
  }
  printf("\n %u",cnt);
}


void set_bit_count()
{

    int n = 39;
    int count = 0;

    while (n)
    {
        count++;
        n = n & (n - 1);
    }
    printf("vishal %u \n", count);
    return;
}

/* Function to reverse bits of num */
unsigned int reverseBits(unsigned int num)
{
    unsigned int NO_OF_BITS = sizeof(num) * 8;
    unsigned int reverse_num = 0, i, temp;

    for (i = 0; i < NO_OF_BITS; i++)
    {
        temp = (num & (1 << i));
        if (temp)
            reverse_num |= (1 << ((NO_OF_BITS - 1) - i));
    }

    return reverse_num;
}

void toggle_1_bit()
{
    unsigned int x = 0XFF00;
    printf("\n");
    printf("BEFORE SET LSB %x \n", x);
    FD_SET(x, 0);
    printf("AFTER SET  LSB %x \n", x);

    x = 0XFFFF;
    printf("BEFORE CLR LSB %x \n", x);
    FD_CLR(x, 0);
    printf("AFTER CLR LSB %x \n", x);

    x = 0XFFFF;

    printf("BEFORE RESET LSB %x \n", x);
    FD_RESET(x, 0);
    printf("AFTER RESET LSB %x \n", x);
}

unsigned int mod_bits(unsigned int x, unsigned int pos, unsigned int val)
{
    unsigned int mask = 1 << pos;
    return ((x & ~mask) | ((val << pos) & mask));
}

// Function to extract k bits from p position
// // and returns the extracted value as integer
// int bitExtracted(int number, int k, int p)
// {
//  return (((1 << k) - 1) & (number >> (p - 1)));
//  }
//
//
//
/* Driver function to test above function */
int main()
{
    unsigned int x = 1;
    printf("%0X", reverseBits(x));
    mod_bits(6, 2, 0);
    return 0;
}
