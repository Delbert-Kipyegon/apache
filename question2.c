#include <stdio.h>
#include <stdlib.h>

/**
 * Below is the Code the three functions and the main function
 *
 * Please find the advantages and disadvantages in the README2.md file
 */

// Recursive implementation of the recurrence relation
int F_recursive(int n)
{
    if (n == 0) // Base case for n = 0
        return 0;
    else if (n == 1) // Base case for n = 1
        return 1;
    else if (n == 2) // Base case for n = 2
        return 2;
    else
        // Recursive case for n > 2
        return F_recursive(n - 3) + F_recursive(n - 2);
}

// Helper function for the Dynamic Programming implementation
int F_memo(int n, int *memo)
{
    if (memo[n] != -1) // If the value has already been calculated, return it
        return memo[n];
    else
    {
        // Otherwise, calculate it using the recurrence relation
        memo[n] = F_memo(n - 3, memo) + F_memo(n - 2, memo);
        return memo[n]; // Return the calculated value
    }
}

// Dynamic Programming implementation of the recurrence relation
int F_dp(int n)
{
    // Allocate memory for the memo array
    int *memo = (int *)malloc((n + 1) * sizeof(int));
    // Initialize all elements of the memo array to -1
    for (int i = 0; i <= n; i++)
        memo[i] = -1;
    // Set base cases
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 2;
    // Calculate the n-th term using the helper function
    int result = F_memo(n, memo);
    // Free the memory allocated for the memo array
    free(memo);
    // Return the result
    return result;
}

// Iterative implementation of the recurrence relation
int F_iterative(int n)
{
    // Initialize the array for the first three terms
    int F[3] = {0, 1, 2};

    // Calculate each term from 3 to n
    for (int i = 3; i <= n; i++)
    {
        // Update the array to hold the last two terms
        int temp = F[2];
        F[2] = F[0] + F[1];
        F[0] = F[1];
        F[1] = temp;
    }

    // Return the n-th term
    return F[2];
}

int main()
{
    // Let's compute for n = 5 for all three methods
    int n = 5;

    // Recursive method
    printf("Recursive: %d\n", F_recursive(n));

    // Dynamic Programming method
    printf("Dynamic Programming: %d\n", F_dp(n));

    // Iterative method
    printf("Iterative: %d\n", F_iterative(n));

    return 0;
}
