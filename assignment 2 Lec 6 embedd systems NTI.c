#include <stdio.h>

int main()
{
    int x = 10, y = 20, z = 30;

    int *p = &x;
    int *q = &y;
    int *r = &z;

    printf("Before Swapping:\n");
    printf("x: %d, y: %d, z: %d\n", x, y, z);
    printf("p: %p, *p: %d\n", (void*)p, *p);
    printf("q: %p, *q: %d\n", (void*)q, *q);
    printf("r: %p, *r: %d\n", (void*)r, *r);

    
    int *temp = p;
    p = q;
    q = r;
    r = temp;

    printf("\nSwapping pointers...\n\n");

    printf("After Swapping:\n");
    printf("x: %d, y: %d, z: %d\n", x, y, z);
    printf("p: %p, *p: %d\n", (void*)p, *p);
    printf("q: %p, *q: %d\n", (void*)q, *q);
    printf("r: %p, *r: %d\n", (void*)r, *r);

    return 0;
}
