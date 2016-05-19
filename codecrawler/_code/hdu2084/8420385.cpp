#include <stdio.h>
int f[102][102];
int main()
{
    int C, n, i, j;
    scanf("%d",&C);
    while(C--)
    {
        scanf("%d",&n);
        for(i=1; i<=n; i++)
            for(j=1; j<=i; j++)
                scanf("%d",&f[i][j]);
        for(i=n-1; i>=1; i--)
            for(j=i; j>=1; j--)
                if(f[i+1][j+1]>f[i+1][j]) f[i][j] +=f[i+1][j+1];
                else f[i][j] +=f[i+1][j];
        printf("%d\n",f[1][1]);
    }
    return 0;
}
