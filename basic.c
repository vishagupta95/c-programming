#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>

int** initialize2DArray(int rows, int cols, int defaultValue) {
    int** array = malloc(rows * sizeof(int*));  // Allocate memory for rows
    int i =0;
    if (array == NULL) {  // Check if malloc failed for rows allocation
        printf("Memory allocation failed for rows.\n");
        return NULL;
    }
      // Initialize with the default value using pointer arithmetic
        for (int j = 0; j < cols; j++) {
            *(*(array + i) + j) = defaultValue;
   }

}

double getAverage1(int x[], int argc) {
  int i = 0;
  double j = 0; // Initialize j to zero

  // Sum up the elements in the array
  for (i = 0; i < argc; i++) {
    j += x[i];
  }

  // Return the average
  return (j / argc);
}

typedef struct A
{
  int x;
  char y[50];
 }NODE;


int mains()
{

 NODE var1 = { 40,"vishal"};
 NODE var2 = { .x = 40, .y = "vishal"};

 printf("%d %s \n",var1.x,var1.y);
 printf("%d %s \n",var2.x,var2.y);
}

struct person
{
   int age;
   float weight;
};

int abc()
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

// Macro to calculate the size of a variable or type using pointer arithmetic
#define my_sizeof(type) (char *)(&type + 1) - (char *)(&type)

// Macro to concatenate two tokens
#define concat(a, b) a##b

// Macro to get the maximum of two values
#define MAX(i, j) (((i) > (j)) ? (i) : (j))

// Function to demonstrate macro functionality
void demo_macros() {
    int someVar = 10; // Simple integer variable
    printf("Size of someVar = %ld bytes\n", my_sizeof(someVar)); // Size of `someVar` in bytes

    int concat(my, Var) = 42; // Creates a variable named `myVar`
    printf("Value of myVar (from concat) = %d\n", myVar);  // Prints the value of the generated variable

    int a = 5, b = 10;
    printf("Max of %d and %d is %d\n", a, b, MAX(a, b));  // Maximum of `a` and `b`
}

int limit() {
    printf("INT_MAX: %d\n", INT_MAX);
    printf("INT_MIN: %d\n", INT_MIN);
    printf("LONG_MAX: %ld\n", LONG_MAX);
    printf("LONG_MIN: %ld\n", LONG_MIN);
    
    printf("FLT_MAX: %f\n", FLT_MAX);
    printf("FLT_MIN: %e\n", FLT_MIN);
    printf("DBL_MAX: %lf\n", DBL_MAX);
    printf("DBL_MIN: %e\n", DBL_MIN);
    
    return 0;
}

// Function to test the conditional ternary operator
int test_condition() {
    int a = 10; // Example variable
    return a <= 0 ? 999 : 888; // Returns 999 if `a <= 0`, otherwise returns 888
}

// Function to demonstrate different methods of array initialization
void demo_array_initialization() {
    char zeroArray[1024]; // Local array
    memset(zeroArray, 0, sizeof(zeroArray)); // Use `sizeof` to zero initialize

    char zeroArray2[1024] = {0}; // Explicit zero initialization
    printf("First element of zeroArray2: %d\n", zeroArray2[0]); // Should print 0
}

// Function to demonstrate `strlen` and `sizeof` differences
void demo_string_operations() {
    char s[] = "help"; // String with null terminator
    printf("strlen(s) = %zu\n", strlen(s)); // Length excluding null terminator
    printf("sizeof(s) = %zu\n", sizeof(s)); // Length including null terminator
}

// Function to demonstrate enum usage
void enum_test() {
    enum week {
        Mon, Tue, Wed, Thur, Fri, Sat, Sun
    };
    enum week day = Mon; // Assigning the first value of the enum
    printf("enum_test: week day = %d\n", day); // Prints the value of Mon
}

// Function to calculate factorial of a number using recursion
int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

// Function to demonstrate factorial calculation
void demo_factorial() {
    int number = 5; // Example number
    printf("Factorial of %d is %d\n", number, factorial(number));
}

// Function to test various sizes and behavior of macros
int size_test() {
    enum week { Mon, Tue, Wed, Thur, Fri, Sat, Sun } day; // Enum declaration
    int x = 10; // Integer variable
    char *ptr; // Pointer variable
    day = Mon; // Assigning value to enum
    int xy = 40; // Another integer

    // Printing sizes using `sizeof` and custom `my_sizeof`
    printf("size of integer x: %d\n", my_sizeof(x));
    printf("Concatenated xy: %d\n", concat(x, y));
    printf("Enum init value = %d, fancy return = %d\n", day, test_condition());
    printf("size of int: %lu\n", sizeof(int));
    printf("size of long: %lu\n", sizeof(long));
    printf("size of double: %lu\n", sizeof(double));
    printf("size of long long: %lu\n", sizeof(long long));
    printf("size of enum: %lu\n", sizeof(day));
    printf("size of ptr: %lu\n", sizeof(ptr));
    printf("size of *ptr: %lu\n", sizeof(*ptr));

    // Post-increment and pre-increment examples
    printf("x++=[%d] x++=[%d] x++=[%d]\n", x++, x++, x++);
    printf("++x=[%d] ++x=[%d] ++x=[%d]\n", ++x, ++x, ++x);

    return 0;
}

// Main function
int main() {
    demo_macros();               // Test macros
    demo_array_initialization(); // Test array initialization
    demo_string_operations();    // Test string operations
    enum_test();                 // Test enums
    demo_factorial();            // Test factorial calculation
    size_test();                 // Test size-related operations
    limit();
    return 0; // Successful execution
}

