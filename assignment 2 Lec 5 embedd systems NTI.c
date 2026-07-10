#include <stdio.h>

int main()
{
    int class1[10], class2[10], class3[10];
    int i;
    int pass = 0, fail = 0;
    int highest, lowest;
    int sum = 0;
    float average;

  
    printf("Enter grades for Class 1:\n");
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &class1[i]);
    }

  
    printf("Enter grades for Class 2:\n");
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &class2[i]);
    }


    printf("Enter grades for Class 3:\n");
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &class3[i]);
    }


    highest = class1[0];
    lowest = class1[0];

 
    for(i = 0; i < 10; i++)
    {
        if(class1[i] >= 50)
            pass++;
        else
            fail++;

        if(class1[i] > highest)
            highest = class1[i];

        if(class1[i] < lowest)
            lowest = class1[i];

        sum += class1[i];
    }


    for(i = 0; i < 10; i++)
    {
        if(class2[i] >= 50)
            pass++;
        else
            fail++;

        if(class2[i] > highest)
            highest = class2[i];

        if(class2[i] < lowest)
            lowest = class2[i];

        sum += class2[i];
    }

   
    for(i = 0; i < 10; i++)
    {
        if(class3[i] >= 50)
            pass++;
        else
            fail++;

        if(class3[i] > highest)
            highest = class3[i];

        if(class3[i] < lowest)
            lowest = class3[i];

        sum += class3[i];
    }

    average = (float)sum / 30;

    printf("\n----- Statistics -----\n");
    printf("Passed Students = %d\n", pass);
    printf("Failed Students = %d\n", fail);
    printf("Highest Grade = %d\n", highest);
    printf("Lowest Grade = %d\n", lowest);
    printf("Average Grade = %.2f\n", average);

    return 0;
}