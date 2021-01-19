#include <stdio.h>

//Fibonacci Series using Recursion 
#include<bits/stdc++.h> 
using namespace std; 

int fib_rec(int n) 
{ 
    if (n <= 1) 
        return n; 
    return fib(n-1) + fib(n-2); 
} 

// Returns number of ways to reach s'th stair
int countWays(int s)
{
    return fib_rec(s + 1); 
}
 

int main() {
    int i, n, t1 = 0, t2 = 1, nextTerm;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");

    for (i = 1; i <= n; ++i) {
        printf("%d, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }

    return 0;
}
