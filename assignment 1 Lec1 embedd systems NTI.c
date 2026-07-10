#include <stdio.h>

int main()
{
    int rows = 6;

    for (int i = 1; i <= rows; i++)
    {
        // Print spaces
        for (int j = 1; j <= rows - i; j++)
        {
            printf(" ");
        }

        // Print X's
        for (int j = 1; j <= (2 * i - 1); j++)
        {
            printf("x");
        }

        printf("\n");
    }

    return 0;
}