#include <stdio.h>

// Two-operand functions
int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

float divide(int a, int b)
{
    return (float)a / b;
}

int And(int a, int b)
{
    return a & b;
}

int Or(int a, int b)
{
    return a | b;
}

int Xor(int a, int b)
{
    return a ^ b;
}

int remainder(int a, int b)
{
    return a % b;
}

// One-operand functions
int Not(int a)
{
    return ~a;
}

int increment(int a)
{
    return ++a;
}

int decrement(int a)
{
    return --a;
}

int main()
{
    int id;
    int a, b;

    printf("Simple Calculator\n");
    printf("-----------------\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. And\n");
    printf("6. Or\n");
    printf("7. Not\n");
    printf("8. Xor\n");
    printf("9. Remainder\n");
    printf("10. Increment\n");
    printf("11. Decrement\n");

    printf("\nEnter Operation ID: ");
    scanf("%d", &id);

    switch(id)
    {
        case 1:
            printf("Enter two numbers: ");
            scanf("%d%d", &a, &b);
            printf("Result = %d\n", add(a,b));
            break;

        case 2:
            printf("Enter two numbers: ");
            scanf("%d%d", &a, &b);
            printf("Result = %d\n", subtract(a,b));
            break;

        case 3:
            printf("Enter two numbers: ");
            scanf("%d%d", &a, &b);
            printf("Result = %d\n", multiply(a,b));
            break;

        case 4:
            printf("Enter two numbers: ");
            scanf("%d%d", &a, &b);

            if(b == 0)
                printf("Cannot divide by zero!\n");
            else
                printf("Result = %.2f\n", divide(a,b));
            break;

        case 5:
            printf("Enter two numbers: ");
            scanf("%d%d", &a, &b);
            printf("Result = %d\n", And(a,b));
            break;

        case 6:
            printf("Enter two numbers: ");
            scanf("%d%d", &a, &b);
            printf("Result = %d\n", Or(a,b));
            break;

        case 7:
            printf("Enter one number: ");
            scanf("%d", &a);
            printf("Result = %d\n", Not(a));
            break;

        case 8:
            printf("Enter two numbers: ");
            scanf("%d%d", &a, &b);
            printf("Result = %d\n", Xor(a,b));
            break;

        case 9:
            printf("Enter two numbers: ");
            scanf("%d%d", &a, &b);
            printf("Result = %d\n", remainder(a,b));
            break;

        case 10:
            printf("Enter one number: ");
            scanf("%d", &a);
            printf("Result = %d\n", increment(a));
            break;

        case 11:
            printf("Enter one number: ");
            scanf("%d", &a);
            printf("Result = %d\n", decrement(a));
            break;

        default:
            printf("Invalid Operation ID!\n");
    }

    return 0;
}