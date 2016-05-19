#include <stdio.h>
#include <string.h>

int main()
{
    char password[33];

    while (scanf("%s", &password) != EOF)
    {
        if (strcmp(password, "wujiawei") == 0)
        {
            printf("hit\n");
        }
        else
        {
            printf("lose\n");
        }
    }

    return 0;
}