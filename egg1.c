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

Dynamic Programming (DP) is a method for solving complex problems by breaking them down into smaller subproblems. 
Unlike traditional recursion, DP saves the results of already-solved subproblems in a table (usually an array or matrix) 
to avoid redundant computations. This technique is particularly effective for optimization problems where 
there are overlapping subproblems and optimal substructure properties.
Dynamic Programming helps solve the Egg Drop Problem efficiently by breaking it into smaller subproblems, leveraging optimal substructure, and avoiding redundant calculations. Without binary search, the time complexity is 
𝑂
(
eggs
×
floors
2
)
O(eggs×floors 
2
 ), but it is still far better than a naive brute-force approach.

 *
 *
 */

#include <stdio.h>
#include <limits.h>

// Function to calculate minimum trials using DP
int eggDropDP(int eggs, int floors) {
    // Create a DP table
    int dp[eggs + 1][floors + 1];

    // Initialize base cases
    for (int i = 1; i <= eggs; i++) {
        dp[i][0] = 0; // 0 floors require 0 trials
        dp[i][1] = 1; // 1 floor requires 1 trial
    }
    for (int j = 1; j <= floors; j++) {
        dp[1][j] = j; // 1 egg requires j trials
    }

    // Fill the DP table
    for (int i = 2; i <= eggs; i++) {
        for (int j = 2; j <= floors; j++) {
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= j; x++) {
                // Calculate worst-case trials for each floor x
                int trials = 1 + (dp[i - 1][x - 1] > dp[i][j - x] ? dp[i - 1][x - 1] : dp[i][j - x]);
                if (trials < dp[i][j])
                    dp[i][j] = trials;
            }
        }
    }

    return dp[eggs][floors];
}

int main() {
    int eggs = 2, floors = 100;
    printf("Minimum number of trials in worst case with %d eggs and %d floors is: %d\n", eggs, floors, eggDropDP(eggs, floors));
    return 0;
}

