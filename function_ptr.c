#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

typedef int function(int a, int b);

int call_function(function *p, int a, int b) {
    return p(a, b);
}

int main(void) {
    int sum;
    
    sum = call_function(&add, 10, 5);
    printf("add: %d\n", sum);
    
    sum = call_function(&sub, 10, 5);
    printf("sub: %d\n", sum);
    
    return 0;
}
