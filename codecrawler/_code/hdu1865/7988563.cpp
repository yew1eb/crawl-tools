#include <stdio.h>
#include <string.h>

int f[201][10];
int length[201];
const int Base = 100000;

void init()
{
    int i, j, c;
    f[0][0] = 1; f[1][0] = 1;
    length[0]=1; length[1]=1;
    for(i=2; i<=200; ++i)
    {
        length[i]=length[i-1]+1;
        c = 0;
        for(j=0; j<=length[i]; ++j)
        {
            f[i][j] = (c += f[i-1][j] +f[i-2][j] )% Base;
            c /= Base;
        }
        while( !f[i][length[i]]) length[i]--;
    }
}

void work()
{
    int k, i, n;
    char s[201];
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s",s); k = strlen(s);
        while( !f[k][length[k]]) length[k]--;
        printf("%d",f[k][ length[k] ]);
        for(i=length[k]-1; i>=0; --i)
            printf("%05d",f[k][i]);
        printf("\n");
    }
}
int main()
{
    init();
    work();
    return 0;
}
