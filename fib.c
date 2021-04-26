#include <stdio.h>
//fibonicci series 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

// Returns number of ways to reach s'th stair
int countWays(int s)
{
    return fib(s + 1);
}

int main()
{
    int i, n, t1 = 0, t2 = 1, nextTerm;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series:  %d \n", countWays(n));


    for (i = 1; i <= n; ++i) {
        nextTerm = t1 + t2;
        printf("t1= %d, t2 =%d  val = %d \n", t1,t2,nextTerm);
        t1 = t2;
        t2 = nextTerm;
        
    }
    printf("Fibonacci Series:  %d \n", countWays(n));

    return 0;
}
