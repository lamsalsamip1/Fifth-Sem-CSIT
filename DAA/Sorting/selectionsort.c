#include <stdio.h>
#define N 10
void selectionSort(int arr[N])
{
    int i, j, temp, min;
    for (i = 0; i < N - 1; i++)
    {
        min = i;
        for (j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
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
    selectionSort(arr);
    printf("\nSorted array: \n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}