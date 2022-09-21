#if 0
Algorithm Paradigm: Backtracking 

Time Complexity: O(n*n!) Note that there are n! permutations and it requires O(n) time to print a permutation.

Auxiliary Space: O(r – l)
// C program to print all permutations with duplicates allowed
#include <stdio.h>
#include <string.h>

/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

/* Function to print permutations of string
This function takes three parameters:
1. String
2. Starting index of the string
3. Ending index of the string. */
void permute(char *a, int l, int r)
{
int i;
if (l == r)
	printf("%s\n", a);
else
{
	for (i = l; i <= r; i++)
	{
		swap((a+l), (a+i));
		permute(a, l+1, r);
		swap((a+l), (a+i)); //backtrack
	}
}
}

/* Driver program to test above functions */
int main()
{
	char str[] = "ABC";
	int n = strlen(str);
	permute(str, 0, n-1);
	return 0;
}

#endif

#include <stdio.h>

//function to print the array
void printarray(int arr[], int size)
{
    int i,j;
    for(i=0; i<size; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

//function to swap the variables
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//permutation function
void permutation(int *arr, int start, int end)
{
    if(start==end)
    {
        printarray(arr, end+1);
        return;
    }
    int i;
    for(i=start;i<=end;i++)
    {
        //swapping numbers
        swap((arr+i), (arr+start));
        //fixing one first digit
        //and calling permutation on
        //the rest of the digits
        permutation(arr, start+1, end);
        swap((arr+i), (arr+start));
    }
}

int main()
{
    //taking input to the array
    int size;
    printf("Enter the size of array\n");
    scanf("%d",&size);
    int i;
    int arr[size];
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
    //calling permutation function
    permutation(arr, 0, size-1);
    return 0;
}
