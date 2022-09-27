#include <stdio.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main(){
int a =10,b=25,c=15;
int res =0;

while(b>0) {

        res += (a%c) + (c%a);
        b -= a%c;
        swap(&a,&c);
}

printf("%d",res);

}

output 45


train A goes 5km and reach in 7 hrs
train B goes 7km and rech in 5 hrs
if train A starts at 4pm and train B starts at 3pm when they reach

       3  4  5 6  6.30   7

tr a         7 14    17.5  21    

tr b      5  10 15   17.5   20
