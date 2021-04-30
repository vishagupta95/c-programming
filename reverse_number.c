#include <stdio.h>

int reversDigits(int num)
{
    int tmp = 0;
    //If num is negative, then convert it to positive
    tmp = (num < 0)? (-1 * num): num;
    int prev_rev_num = 0, rev_num = 0;
    while (tmp != 0)
    {
        int last_digit = tmp%10;
        prev_rev_num = (rev_num*10) + last_digit;
        // checking if the reverse overflowed or not.
        // The values of (rev_num - last_digit)/10 and
        // prev_rev_num must be same if there was no
        // problem.
        if ((prev_rev_num - last_digit)/10 != rev_num)
        {
            printf("WARNING OVERFLOWED!!!\n");
            return 0;
        }
        else
        {
            rev_num = prev_rev_num;
        }
        tmp = tmp/10;
    }
    return (num < 0)? -rev_num : rev_num;
}
int main()
{
    int number, reversed = 0;
    //Input a number from user
    printf("Enter any number = ");
    scanf("%d", &number);
    //Reverse the number
    reversed = reversDigits(number);
    if(reversed != 0)
    {
        printf("Reverse of no. is %d", reversed);
    }
    return 0;
}

/*
Enter any number = 12345
Reverse of no. is 54321

Enter any number = 1000000045
WARNING OVERFLOWED!!!
*/
