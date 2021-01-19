/* initialize the structure member */

#include <stdio.h>
typedef struct A
{
  int x;
  char y[50];
 }NODE;


int main()
{

 NODE var1 = { 40,"vishal"};
 NODE var2 = { .x = 40, .y = "vishal"};

 printf("%d %s \n",var1.x,var1.y);
 printf("%d %s \n",var2.x,var2.y);
}

#include <stdio.h>
struct person
{
   int age;
   float weight;
};

int main()
{
    struct person *personPtr, person1;
    personPtr = &person1;   

    printf("Enter age: ");
    scanf("%d", &personPtr->age);

    printf("Enter weight: ");
    scanf("%f", &personPtr->weight);

    printf("Displaying:\n");
    printf("Age: %d\n", personPtr->age);
    printf("weight: %f", personPtr->weight);

    return 0;
}

