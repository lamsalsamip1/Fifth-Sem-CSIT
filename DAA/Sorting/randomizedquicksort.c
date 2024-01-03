#include <stdio.h>
#include <stdlib.h>
#define N 10
int partition(int arr[N], int p, int r)
{
    int i, j, temp;
    int x = arr[r];
    i = p - 1;
    for (j = p; j < r; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    temp = arr[r];
    arr[r] = arr[i + 1];
    arr[i + 1] = temp;
    return i + 1;
}
int randPartition(int arr[N], int p, int r)
{
    // generate random index between p and r
    int i = p + rand() % (r - p + 1);
    // swap arr[i] and arr[r]
    int temp = arr[i];
    arr[i] = arr[r];
    arr[r] = temp;
    return partition(arr, p, r);
}
void randQuickSort(int arr[N], int p, int r)
{
    if (p < r)
    {
        int q = randPartition(arr, p, r);
        randQuickSort(arr, p, q - 1);
        randQuickSort(arr, q + 1, r);
    }
}
int main()
{
    int arr[N] = {9, 2, 4, 7, 1, 3, 6, 5, 8, 10};
    printf("Original array: \n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    randQuickSort(arr, 0, N - 1);
    printf("\nSorted array: \n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}