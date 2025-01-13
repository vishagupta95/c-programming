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
*/
#include <stdio.h>
#include <limits.h>

// Recursive function to find the minimum number of attempts
int eggDrop(int eggs, int floors) {
    // Base cases
    if (floors == 0 || floors == 1) {
        return floors;
    }
    if (eggs == 1) {
        return floors; // Linear search when only one egg is left
    }

    int minAttempts = INT_MAX;

    // Try dropping an egg from each floor and calculate the worst-case attempts
    for (int x = 1; x <= floors; x++) {
        int breakCase = eggDrop(eggs - 1, x - 1); // Egg breaks
        int noBreakCase = eggDrop(eggs, floors - x); // Egg doesn't break
        int attempts = 1 + (breakCase > noBreakCase ? breakCase : noBreakCase); // Worst case

        // Update the minimum attempts
        if (attempts < minAttempts) {
            minAttempts = attempts;
        }
    }

    return minAttempts;
}

// Main function
int main() {
    int eggs = 2; // Number of eggs
    int floors = 10; // Number of floors

    printf("Minimum number of attempts in the worst case: %d\n", eggDrop(eggs, floors));
    return 0;
}

