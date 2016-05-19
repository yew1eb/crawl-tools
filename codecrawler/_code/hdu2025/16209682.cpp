#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

int main()
{
    int i, j;
    char str[100];
    while (scanf ("%s", str) != EOF)
    {
        int len = strlen(str), max = str[0];
        for (i = 1; i < len; i ++)
        {
            if (str[i] > max)
            {
                max = str[i];
            }
        }
        
        for (j = 0; j < len; j ++)
        {
            printf ("%c", str[j]);
            if (str[j] == max)
                printf ("(max)");
        }
        printf ("\n"); 
    }
    
    system ("pause");
    return 0;
}
