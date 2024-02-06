#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Job
{
    char id;
    int deadline;
    int profit;
};
#define min(a, b) ((a) < (b) ? (a) : (b))
int compare(const void *a, const void *b)
{
    return (((struct Job *)b)->profit - ((struct Job *)a)->profit);
}

void printJobScheduling(struct Job arr[], int n)
{
    qsort(arr, n, sizeof(struct Job), compare);

    int result[n];
    bool slot[n];

    for (int i = 0; i < n; i++)
        slot[i] = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--)
        {
            if (slot[j] == false)
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
        if (slot[i])
            printf("%d ", arr[result[i]].id);
}

int main()
{
    struct Job arr[] = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Following is maximum profit sequence of jobs\n");
    printJobScheduling(arr, n);
    return 0;
}