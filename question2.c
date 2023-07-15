/**
 * Recursive implementation
 * 
 * Advantages
 * 1. Simplicity: The recursive method is a direct translation of the problem statement.
 * 
 * Disadvantages
 * 1. Inefficiency: The recursive implementation recalculates the same subproblems over and over again.
 * 2. Stack overflow: For large inputs, this approach may lead to stack overflow due to many recursive calls.
 * 
 * **/

#include <stdio.h>

int F_recursive(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
        return F_recursive(n - 3) + F_recursive(n - 2);
}

/**
 * Memoization/Dynamic Programming
 * 
 * Advantages
 * Efficiency: The DP method remembers results of subproblems to avoid unnecessary recalculation.
 * Avoiding stack overflow: As each subproblem is calculated only once, 
 * this approach avoids the stack overflow issue present in the simple recursive approach.
 * 
 * Disadvantages
 * Space trade-off: The memoization approach uses extra space to store the results of subproblems.
 * **/

#include <stdio.h>
#include <stdlib.h>

int F_memo(int n, int *memo)
{
    if (memo[n] != -1)
        return memo[n];
    else
    {
        memo[n] = F_memo(n - 3, memo) + F_memo(n - 2, memo);
        return memo[n];
    }
}

int F_dp(int n)
{
    int *memo = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++)
        memo[i] = -1;
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 2;
    int result = F_memo(n, memo);
    free(memo);
    return result;
}

/**
 * Iterative Bottom-Up approach implementation
 * 
 * Advantages
 * Efficiency: Like the DP method, the iterative method calculates each subproblem only once.
 * No extra space: Unlike the DP method, the iterative method does not need extra space proportional to n. 
 * Only a constant amount of space is needed.
 * Disadvantages
 * Less intuitive: The iterative method can be less intuitive to implement than the recursive and DP methods.
 */

#include <stdio.h>

int F_iterative(int n)
{
    int F[3] = {0, 1, 2};

    for (int i = 3; i <= n; i++)
    {
        int temp = F[2];
        F[2] = F[0] + F[1];
        F[0] = F[1];
        F[1] = temp;
    }

    return F[2];
}
