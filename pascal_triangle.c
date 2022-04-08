#include <stdio.h>

/*

Pascal triangle is a triangular array of binomial coefficients. In pascal triangle, each number is 
the sum of the two numbers directly above it. Here we will write a pascal triangle program in the C programming language.
*/

int main()
{
  int n;
  printf("Enter the number of rows: ");
  scanf("%d",&n);
  for(int row=1; row<=n; row++)
  {
    int a=1;

    /*
    We can display the pascal triangle at the center of the screen. 
    For this, just add the spaces before displaying every row. Generally,
     on a computer screen, we can display a maximum of 80 characters horizontally. 
    Half of 80 is 40, so 40th place is the center of the line.
    */

    for(int s=1; s<=40-row; s++)
    printf(" ");

    for(int i=1; i<=row; i++)
    {
      printf("%d ",a);
      a = a * (row-i)/i;
    }

    printf("\n");
  }

  return 0;
}

