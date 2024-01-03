#include <stdio.h>
#define N 10

void merge(int arr[N], int p, int q, int r)
{
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[N], R[N];
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[p + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[q + j + 1];
    }
    i = 0;
    j = 0;
    for (k = p; k <= r; k++)
    {
        if (i < n1 && j < n2)
        {
            if (L[i] < R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
        }
        else if (i < n1)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
    }
}
void mergeSort(int arr[N], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
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
    mergeSort(arr, 0, N - 1);
    printf("\nSorted array: \n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}