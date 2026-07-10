#include <stdio.h>

int main()
{
    int arr[10];
    int max, min;

    printf("Enter 10 values:\n");

    // Input the array
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Initialize max and min
    max = arr[0];
    min = arr[0];

    // Find maximum and minimum
    for (int i = 1; i < 10; i++)
    {
        if (arr[i] > max)
            max = arr[i];

        if (arr[i] < min)
            min = arr[i];
    }

    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);

    return 0;
}
}