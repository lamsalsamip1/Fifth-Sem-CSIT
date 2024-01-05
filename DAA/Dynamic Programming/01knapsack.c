#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to solve binary knapsack problem using dynamic programming
void DP_BINARY_KNAPSACK(int n, int M, int w[], int v[])
{
    int V[n + 1][M + 1];

    // Initialization
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            if (i == 0 || j == 0)
                V[i][j] = 0;
        }
    }

    // Dynamic Programming
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            if (w[i - 1] <= j)
            {
                V[i][j] = max(V[i - 1][j], v[i - 1] + V[i - 1][j - w[i - 1]]);
            }
            else
            {
                V[i][j] = V[i - 1][j];
            }
        }
    }

    // Printing the result
    printf("DP_BINARY_KNAPSACK Solution:\n");
    printf("Maximum value that can be obtained: %d\n", V[n][M]);

    // Backtracking to find selected items
    printf("Selected items: ");
    int i = n, j = M;
    while (i > 0 && j > 0)
    {
        if (V[i][j] != V[i - 1][j])
        {
            printf("%d ", i);
            j -= w[i - 1];
        }
        i--;
    }
    printf("\n");
}

int main()
{
    // Example usage
    int n = 4; // Number of items
    int M = 8; // Knapsack capacity

    int w[] = {3, 4, 6, 5}; // Weights of items
    int v[] = {2, 3, 1, 4}; // Profits of items

    DP_BINARY_KNAPSACK(n, M, w, v);

    return 0;
}