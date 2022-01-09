#include<stdio.h>

/*
 * 1) Recursive Approach:
 *
 * We have n eggs and k floors. The following are the possibilities,
 *
 * When we drop an egg from a floor x, there can be two cases (1) The egg breaks (2) The egg doesn't break.
 *
 * If the egg breaks after dropping from xth floor, then we only need to check for floors lower than x with 
 * remaining eggs; so the problem reduces to x-1 floors and n-1 eggs.
 * If the egg doesn't break after dropping from the xth floor, then we only need to check for floors higher than x;i
 * so the problem reduces to k-x floors and n eggs.
 * Since we need to minimize the number of trials in the worst case, we take the maximum of two cases. 
 * We consider the max of the above two cases for every floor and choose the floor which yields the minimum number of trials.
 *
 *a for 2 eggs and 100 floor

  if first eggg breaks at 14th floor, start from 1 to 13  = 1+13 =14
  if first eggg breaks at 27th floor, start from 15 to 26  = 2+12 =14
  if first eggg breaks at 39th floor, start from 40 to 38  = 3+11 =14

 *
 *
 */


#define MAX_VAL 9999

int max(int a, int b) {
   return (a > b)? a: b;
}

int eggTrialCount(int eggs, int floors) { //minimum trials for worst case

   int minTrial[eggs+1][floors+1]; //to store minimum trials for i-th egg and jth floor
   int res, i, j, k;
  
   for (i = 1; i <= eggs; i++) { //one trial to check from first floor, and no trial for 0th floor
      minTrial[i][1] = 1;
      minTrial[i][0] = 0;
   }
   for (j = 1; j <= floors; j++) //when egg is 1, we need 1 trials for each floor
      minTrial[1][j] = j;


   for (i = 2; i <= eggs; i++){ //for 2 or more than 2 eggs
      for (j = 2; j <= floors; j++) { //for second or more than second floor
         minTrial[i][j] = MAX_VAL;
         for (k = 1; k <= j; k++) {
            res = 1 + max(minTrial[i-1][k-1], minTrial[i][j-k]);
            if (res < minTrial[i][j])
               minTrial[i][j] = res;
         }
      }
   }
   return minTrial[eggs][floors]; //number of trials for asked egg and floor
}
int main () {
   int egg, maxFloor;
   printf("Enter number of eggs: ");
   scanf("%d", &egg);
   printf("Enter max Floor: ");
   scanf("%d", &maxFloor);
   printf("Minimum number of trials: %d", eggTrialCount(egg, maxFloor));
}
