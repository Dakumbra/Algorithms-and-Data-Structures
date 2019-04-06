//***************************************************************************
//                      Project #3 - Multiple Precision Arithmetic
//                              Name:  Samuel Weems
//                           Course:  CMPS 5243, Spring 2018
//                         Professor: Dr. Richard P. Simpson
//                              Date: April 09 2018
//***************************************************************************
//                                  Introduction
//
//  The purpose of writing this program was to gain a greater understanding
//  of the dynamic programming approach to algorithm development. In this
//  project the "Coin Change Problem" was solved using both a greedy algorithm
//  approach and a dynamic programming approach. The solutions were compared
//  to one another by examining how many fewer coins the dynamic programming
//  approach found compared to the greedy algorithm approach. The final output
//  is a percentage that expresses this ratio taken as an average from the
//  number of runs made using different total amounts and differnt coin
//  denominations.
//
//***************************************************************************
//                              Program Complexity
//                                      O(MV)
//
//  The program's overall complexity is based on the most complex call which
//  is to the dynamic programming alogrithmic approach. This function,
//  explained more fully below, is of complexity O(MV) where M is the
//  number of coin denominations and V is the total amount.
//
//***************************************************************************
//
//  I have written the entire program as turned in and have not copied this
//  code, or parts of this code from the internet or another student.
//
//                                  Signature _______________________________
//
//***************************************************************************

#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;

const int NUM_COINS = 7;    // Number of coins to use

// Coin Selector Function Prototype
int* coinSelection(int selection_range);

// Dynamic Programming and Greedy Algorithm Function Prototypes
double CoinCtDp(int coins[], int total);
double CoinCtGreedy(int coins[], int total);

int main()
{
    int amountMin = 100, amountMax = 500, numRuns = 100, maxDenomination = 100;
    double averagePerCaseSum, totalAverageSum = 0;

    // Total amount to make change for in a range from accountMin to accountMax
    for (int totalAmount = amountMin; totalAmount < amountMax; totalAmount++)
    {
        averagePerCaseSum = 0;

        // 100 runs with specific total amount and changing coin denominations each run
        for (int i = 0; i<numRuns; i++)
        {
            // Select Number of Random Coins including a 1
            int *randomCoins = coinSelection(maxDenomination);
            
            // Sort the coin denominations from smallest to largest
            sort(randomCoins, randomCoins + NUM_COINS);
            
            // Calcualate the ratio of #coins from CoinCtDP to #coins from CoinCtGreedy
            averagePerCaseSum += CoinCtDp(randomCoins, totalAmount)/CoinCtGreedy(randomCoins, totalAmount);
        }
        
        // Caluclate the average of each 100 runs (different coin denominations)
        totalAverageSum += averagePerCaseSum/numRuns;
    }

    // Calculate the average of the 400 runs (different total amounts)
    cout << "Total Average:  " << totalAverageSum/(amountMax-amountMin) << endl;


    return 0;
}

//***************************************************************************
//                   Function: int* coinSelection(int selection_range)
//                      Parameters: selection_range
//                             Returns: int*
//                          Complexity: O(n)
//
//  This function chooses a number (global variable: NUM_COINS) of coins of
//  randomn denominations that range from 1 to "selection_range" (or 100 in
//  this case). The value "1" along with any remaining coins of random
//  denominations are placed into an array which is returned. The complexity
//  of this algorithm is O(n) where n is the number of coins to be selected.
//
//***************************************************************************

int* coinSelection(int selection_range)
{
    int number_selections = NUM_COINS;
    
    // Array full of possible selections
    int selections_remaining[selection_range];
    for (int i=0; i<selection_range; i++)
        selections_remaining[i] = i+1;
    
    // Array of selections made
    int static selections_made[NUM_COINS];
    
    // Automatically choose the value 1 and place in selections
    selections_made[0] = selections_remaining[0];
    swap(selections_remaining[0], selections_remaining[(selection_range-1)]);
    --selection_range;
    --number_selections;
    
    // Seed rand() function with time
    srand (time(NULL));
    
    // Make remaining selections and place in array of selection made
    
    for (int i=1; i<number_selections+1; i++)
    {
        int selectionLocation = rand() % selection_range;
        selections_made[i] = selections_remaining[selectionLocation];
        swap(selections_remaining[selectionLocation], selections_remaining[(selection_range-1)]);
        --selection_range;
    }
    
    return selections_made;
}

//***************************************************************************
//                   Function: double CoinCtDp(int coins[], int total)
//                      Parameters: int coins[], int total
//                             Returns: double
//                            Complexity: O(MV)
//
//  This function is the dynamic programming approach to the problem. It fills
//  in a table from the bottom up and returns the solution that is reached
//  at the end of filling the table. The complexity is O(MV) where M is the
//  number of coins and V is the total.
//
//***************************************************************************

double CoinCtDp(int coins[], int total)
{
    // Dynamic Programming table with #coins for each case
    int solutionTable[total+1];
    
    // Initialize Table
    solutionTable[0] = 0;   // Base Case
    for (int i=1; i <= total; i++)
        solutionTable[i] = INT_MAX;
    
    // Fill Table
    for (int i=1; i<= total; i++)
    {
        for (int j=0; j<NUM_COINS; j++)
            if (coins[j] <= i)
            {
                int temp = solutionTable[i-coins[j]];
                if (temp != INT_MAX && temp + 1 < solutionTable[i])
                    solutionTable[i] = temp + 1;
            }
    }
    
    return solutionTable[total];
}

//***************************************************************************
//              Function: double CoinCtGreedy(int coins[], int total)
//                      Parameters: int coins[], int total
//                             Returns: double
//                             Complexity: O(n)
//
//  This function is the greedy algorithm approach. It simply uses the
//  highest denomination coins when possible and is complexity O(n) where
//  n is the number of coins.
//
//***************************************************************************

double CoinCtGreedy(int coins[], int total)
{
    int coinCount = 0;
    
    for (int i = NUM_COINS-1; i >= 0; i--)
    {
        while (total >= coins[i])
        {
            ++coinCount;
            total -= coins[i];
        }
    }
    return coinCount;
}


