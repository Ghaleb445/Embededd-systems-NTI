#include <stdio.h>

int main()
{
    int height;

    printf("Enter height of the pyramid: ");
    scanf("%d", &height);

    for (int i = 1; i <= height; i++)
    {
        
        for (int j = 1; j <= height - i; j++)
        {
            printf(" ");
        }

        
        for (int j = 1; j <= (2 * i - 1); j++)
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}
