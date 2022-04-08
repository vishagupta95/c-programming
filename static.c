# output is 9 10 11
int m(){
static int x =9;
x++;
printf("%d \n",x);
}

int main(){
m();        
m();
m();
}
