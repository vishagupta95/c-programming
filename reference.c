#include <iostream>

using namespace std;

int global_Var = 42;

// function to change pointer value
void changePointerValue(int* pp)
{
    pp = &global_Var;
}

/*If a pointer is passed to a function as a parameter and tried to be modified then the changes made to the pointer does not reflects back outside that function. This is because only a copy of the pointer is passed to the function
*/

int main()
{
    int var = 23;
    int* ptr_to_var = &var;

    cout << "Passing Pointer to function:" << endl;

    cout << "Before :" << *ptr_to_var << endl; // display 23

    changePointerValue(ptr_to_var);

    cout << "After :" << *ptr_to_var << endl; // display 23

    return 0;
}

/*
The above problem can be resolved by passing the address of the pointer to the function instead of a copy of the actual function. For this, the function parameter should accept a ointer to pointer as shown in the below program:
*/

/ function to change pointer to pointer value
void changePointerValue(int** ptr_ptr)
{
    *ptr_ptr = &global_var;
}
  
/*
A reference allows called function to modify a local variable of the caller function. For example, consider the following example program where fun() is able to modify local variable x of main().

*/

#include<iostream>

using namespace std;

void fun(int &x) {
    x = 20;
}
    
int main() {
    int x = 10;
    fun(x);
    cout<<"New value of x is "<<x;
    return 0;
}

// New value of x is 20

/*
Below program shows how to pass a Reference to a pointer to a function:
*/

#include <iostream>

using namespace std;

int gobal_var = 42;

// function to change Reference to pointer value
void changeReferenceValue(int*& pp)
{
    pp = &gobal_var;
}

int main()
{
    int var = 23;
    int* ptr_to_var = &var;

    cout << "Passing a Reference to a pointer to function" << endl;

    cout << "Before :" << *ptr_to_var << endl; // display 23

    changeReferenceValue(ptr_to_var);

    cout << "After :" << *ptr_to_var << endl; // display 42

    return 0;
}

Passing a Reference to a pointer to function
Before :23
After :42








