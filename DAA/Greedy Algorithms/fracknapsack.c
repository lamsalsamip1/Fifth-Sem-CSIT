#include <stdio.h>

void swap(float *a, float *b)
{
    float t = *a;
    *a = *b;
    *b = t;
}

void sort(float weight[], float profit[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (profit[j] / weight[j] < profit[j + 1] / weight[j + 1])
            {
                swap(&profit[j], &profit[j + 1]);
                swap(&weight[j], &weight[j + 1]);
            }
        }
    }
}

float knapSack(float W, float weight[], float profit[], int n)
{
    sort(weight, profit, n);
    float totalProfit = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (weight[i] <= W)
        {
            W -= weight[i];
            totalProfit += profit[i];
        }
        else
        {
            totalProfit += (W / weight[i]) * profit[i];
            break;
        }
    }
    return totalProfit;
}

int main()
{
    float weight[] = {1, 3, 5, 4, 1, 3, 2};
    float profit[] = {5, 10, 15, 7, 8, 9, 4};
    float W = 15;
    int n = sizeof(profit) / sizeof(profit[0]);
    printf("Maximum profit we can obtain = %.2f", knapSack(W, weight, profit, n));
    return 0;
}