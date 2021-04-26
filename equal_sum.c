#include <stdio.h>

int findElement(int arr[], int n) 
{ 
    // Forming prefix sum array from 0 
    int prefixSum[n]; 
    prefixSum[0] = arr[0]; 
    for (int i = 1; i < n; i++) 
        prefixSum[i] = prefixSum[i - 1] + arr[i]; 

    // Forming suffix sum array from n-1 
    int suffixSum[n]; 
    suffixSum[n - 1] = arr[n - 1]; 
    for (int i = n - 2; i >= 0; i--) 
        suffixSum[i] = suffixSum[i + 1] + arr[i]; 

    // Find the point where prefix and suffix 
    // sums are same. 
    for (int i = 1; i < n - 1; i++) 
        if (prefixSum[i] == suffixSum[i]) 
            return arr[i]; 

    return -1; 
} 

// Driver code 
int main() 
{ 
    //int arr[] = { 1, 4, 2, 5 }; 
    int arr[] = { 2, 4, 12, 5 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    printf("%d \n", findElement(arr, n)); 
    return 0; 
} 

