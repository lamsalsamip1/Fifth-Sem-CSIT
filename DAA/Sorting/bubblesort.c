// All algorithms based on the book: Introduction to Algorithms, 3rd Edition

#include <stdio.h>
#define N 10
void bubbleSort(int arr[N])
{
    int i, j, temp;
    for (i = 0; i < N - 2; i++)
    {

        for (j = N - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
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
    bubbleSort(arr);
    printf("\nSorted array: \n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}