The following example shows how dlopen() and dlsym() can be used to access either function or data objects. For simplicity, error checking has been omitted.
int     *iptr, (*fptr)(int);

int my_function ( int x) {
  printf("dll() %d \n",n);
  return 0;
}

/* open the needed object */
handle = dlopen("/usr/home/me/libfoo.so", RTLD_LOCAL | RTLD_LAZY);

/* find the address of function and data objects */
fptr = (int (*)(int))dlsym(handle, "my_function");
iptr = (int *)dlsym(handle, "my_object");

/* invoke function, passing value of integer as a parameter */
(*fptr)(*iptr);

gcc -c dll.c -fpic
gcc -shared -o libdll.so dll.o
gcc -c main.c
gcc -rdynamic main.o -o main -ldl

