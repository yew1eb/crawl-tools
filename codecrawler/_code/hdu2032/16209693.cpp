#include <stdio.h>
#include <iostream>
 
using namespace std;
 
int main()
{
    int n, i, j;
    int a[100][100];
    while (cin >> n)
    {
        for (i = 1; i <= n; i ++)
        {
            for (j = 1; j <= i; j ++)
            {
                if (j == 1 && j == i)
                {
                    a[i][j] = 1;
                    if (j == 1)
                        printf ("%d", a[i][j]);
                    else printf (" %d", a[i][j]);
                }
                else
                {
                 
                    a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
                    if (j == 1)
                        printf ("%d", a[i][j]);
                    else
                        printf (" %d", a[i][j]);
                }
            }
            printf ("\n");
        }
        printf ("\n");
    }
    
    system ("pause");
    return 0;
}
 
