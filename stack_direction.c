/*

A stack is a data structure that stores elements. There are two operations on the stack. push that adds a new element to the stack. pop that removes an element from the stack.

The stack can grow upward and downward according to the nature of the program that uses it. The program to find the direction of the growth of stack in a program.

Algorithm
Step 1: Create a local variable in the main function.
Step 2: Create a function that with a local variable.
Step 3: Call the function from the main function. And then compare the local variables of in both these functions.
Step 4: Compare the address of local variables in main and the function.
Step 5: If the address of fun() local variable is more than the main local variable, then the stack grows upward otherwise it grows downward.

*/

#include<stdio.h>
void fun(int *main_local_addr){
   int fun_local;
   if (main_local_addr < &fun_local)
      printf("Stack grows upward\n");
   else
      printf("Stack grows downward\n");
}
int main(){
   int main_local;
   fun(&main_local);
   return 0;
}
