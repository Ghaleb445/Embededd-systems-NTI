#include <stdio.h>

int maximum(int a, int b, int c, int d)
{
    int max = a;

    if (b > max)
        max = b;
    if (c > max)
        max = c;
    if (d > max)
        max = d;

    return max;
}


int minimum(int a, int b, int c, int d)
{
    int min = a;

    if (b < min)
        min = b;
    if (c < min)
        min = c;
    if (d < min)
        min = d;

    return min;
}

int main()
{
    int v1, v2, v3, v4;

    printf("Enter value 1: ");
    scanf("%d", &v1);

    printf("Enter value 2: ");
    scanf("%d", &v2);

    printf("Enter value 3: ");
    scanf("%d", &v3);

    printf("Enter value 4: ");
    scanf("%d", &v4);

    printf("\nMaximum number is %d\n", maximum(v1, v2, v3, v4));
    printf("Minimum number is %d\n", minimum(v1, v2, v3, v4));

    return 0;
}