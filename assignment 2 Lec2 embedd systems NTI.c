#include <stdio.h>
#include <string.h>

int main()
{
    char userID[3][20] = {"Ahmed", "Amr", "Wael"};
    char password[3][20] = {"12347788", "56785566", "98701122"};

    char username[20];
    char pass[20];
    int found = 0;

    printf("Enter User ID: ");
    scanf("%s", username);

    printf("Enter Password: ");
    scanf("%s", pass);

    for (int i = 0; i < 3; i++)
    {
        if (strcmp(username, userID[i]) == 0 &&
            strcmp(pass, password[i]) == 0)
        {
            found = 1;
            break;
        }
    }

    if (found)
        printf("Login Successful.\n");
    else
        printf("Invalid User ID or Password.\n");

    return 0;
}