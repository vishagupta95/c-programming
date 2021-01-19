#include <stdio.h> 
// Function to return gcd of a and b 
int gcd(int a, int b) 
{

    if (a == 0) {
     printf("a = %d , b = %d ,return ( b =%d \n)",a,b,b);
        return b;
    }
    printf("a = %d , b = %d , return ( b mod a =%d \n)",a,b,b%a);
    return gcd(b % a, a); 
} 
  
// Function to find gcd of array of 
// numbers 
int findGCD(int arr[], int n) 
{ 
    int result = arr[0]; 
    int i =0;
    for (i = 1; i < n; i++) 
    { 
        result = gcd(arr[i], result); 
  
        if(result == 1) 
        { 
           return 1; 
        } 
    } 
    return result; 
} 
  
// Driver code 
int main() 
{ 
    int arr[] = { 2, 4, 6, 8, 16 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    printf(" result = %d", findGCD(arr, n)); 
    return 0; 
} 
