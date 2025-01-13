#include <stdio.h>

int countWaysToMakeChange(int coinDenominations[], int numCoins, int targetAmount) {
    // Initialize an array to store the number of ways to make change for each amount
    int ways[targetAmount + 1]; 
    
    // Base case: There's 1 way to make change for amount 0 (using no coins)
    ways[0] = 1;
    
    // Initialize all other entries of ways[] to 0
    for (int i = 1; i <= targetAmount; i++) {
        ways[i] = 0;
    }
    
    // Iterate over all the coin denominations
    for (int coin = 0; coin < numCoins; coin++) {
        // For each coin, update the ways array for all amounts greater than or equal to the coin's value
        for (int amount = coinDenominations[coin]; amount <= targetAmount; amount++) {
            // Calculate the number of ways to make the value minus the current coin
            int waysWithoutCurrentCoin = ways[amount];
            int waysWithCurrentCoin = ways[amount - coinDenominations[coin]];
            
            // Add the number of ways together to update the current amount
            ways[amount] = waysWithoutCurrentCoin + waysWithCurrentCoin;
        }
    }
    
    // The number of ways to make the target amount is now stored in ways[targetAmount]
    return ways[targetAmount];
}

int main() {
    // Define the coin denominations
    int coinDenominations[] = {1, 2, 3};
    int numCoins = sizeof(coinDenominations) / sizeof(coinDenominations[0]);
    
    // Define the target amount
    int targetAmount = 4;
    
    // Call the function to count the number of ways to make the target amount
    int totalWays = countWaysToMakeChange(coinDenominations, numCoins, targetAmount);
    
    // Print the result
    printf("Total number of ways to make change for %d: %d\n", targetAmount, totalWays);
    
    return 0;
}

