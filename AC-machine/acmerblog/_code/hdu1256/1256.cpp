#include <stdio.h>

int main()
{
    int n,m,p,s;
    int i,j,k;
    char a;
    scanf("%d%*c", &n);
    k = 0;
    while(n-- && scanf("%c %d%*c", &a, &m))
    {
        if(k++) puts("");
        s = m/6+1;
        p = (m-3)/2;
        m = m-3-p;
        for(j = 0; j < s; j++)
            putchar(' ');
        for(i = 0; i < m; i++)
            putchar(a);
        puts("");
        for(i = 0; i < p; i++)
        {
            for(j = 0; j < s; j++)
                putchar(a);
            for(j = 0; j < m; j++)
                putchar(' ');
            for(j = 0; j < s; j++)
                putchar(a);
            puts("");
        }
        for(j = 0; j < s; j++)
            putchar(' ');
        for(i = 0; i < m; i++)
            putchar(a);
        puts("");
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < s; j++)
                putchar(a);
            for(j = 0; j < m; j++)
                putchar(' ');
            for(j = 0; j < s; j++)
                putchar(a);
            puts("");
        }
        for(j = 0; j < s; j++)
            putchar(' ');
        for(i = 0; i < m; i++)
            putchar(a);
        puts("");
    }
    return 0;
}