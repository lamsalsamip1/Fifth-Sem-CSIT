#include <stdio.h>
#define N 10
void compareExchange(int arr[N], int i, int j)
{
    int temp;
    if (arr[i] > arr[j])
    {
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }
}
void insertionSort(int arr[N])
{
    int i, j;
    for (j = 1; j < N; j++)
    {
        for (i = j - 1; i >= 0; i--)
        {
            compareExchange(arr, i, i + 1);
        }
    }
}
int main()
{
    int arr[N] = {5, 2, 4, 6, 1, 3, 7, 9, 8, 10};
    printf("Original array: \n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    insertionSort(arr);
    printf("\nSorted array: \n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}