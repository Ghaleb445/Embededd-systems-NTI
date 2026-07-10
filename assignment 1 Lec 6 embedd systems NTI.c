#include <stdio.h>

void bubbleSort(int arr[], int size)
{
    int i, j, temp;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    int i;

    printf("Original Array: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    bubbleSort(arr, size);

    printf("\nSorted Array: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}