#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,cnt = 0,i,j,k,ans = 0;
        scanf("%d%d",&m,&n);
        for(i = 0; i<=m; i++)
        {
            for(j = 0; j<=m-i; j++)
            {
                for(k = 0; k<=m-i-j; k++)
                {
                    if(i+j+k == m && i+2*j+5*k == n)
                    {
                        cnt++;
                    }
                }
            }
        }
        printf("%d\n",cnt);
    }

    return 0;
}
