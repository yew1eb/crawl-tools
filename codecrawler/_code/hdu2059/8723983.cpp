#include <stdio.h>
#include <string.h>
#define INF 0xfffffff
int st[105];
double dp[105];

int main()
{
    int L, n, c, t, v, v1, v2, i, j;
    double min, time;
    while(~scanf("%d",&L))
    {
        scanf("%d%d%d",&n,&c,&t);
        scanf("%d%d%d",&v,&v1,&v2);
        for(i=1; i<=n; i++)
            scanf("%d",&st[i]);
        st[0] = 0;
        st[++n] = L;
        dp[0] = 0.0;
        for(i=1; i<=n; i++)
        {
            min = INF;
            for(j=0; j<i; j++)
            {
                if(st[i]-st[j]>c)
                    time = (double)c/v1 + (double)(st[i]-st[j]-c)/v2;
                else
                    time = (double)(st[i]-st[j])/v1;
                if(j!=0) time += t;
                time +=dp[j];
                if(time<min)
                    min = time;
            }
            dp[i] = min;
        }
        if(dp[n]>(double)L/v)
            printf("Good job,rabbit!\n");
        else
            printf("What a pity rabbit!\n");
    }
    return 0;
}
