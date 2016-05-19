#include <stdio.h>
#include <string.h>
typedef struct{
    int ai;
    int bi;
}node;
int max (int a,int b)
{
    return a > b ? a : b ;
}
int main ()
{
    node skill[110];
    int n,t,q,i,j,k,p;
    int dp[110];
    while (scanf ("%d%d%d",&n,&t,&q))
    {
        p = 0;
        if (n == 0 && t == 0 && q == 0)
            break;
        for (i = 1 ; i <= n ; i++)
            scanf ("%d%d",&skill[i].ai,&skill[i].bi);
        skill[0].ai = 0;
        skill[0].bi = 1;
        memset (dp,-1,sizeof(dp));
        dp[100] = 100;
        int time = (100 % q == 0) ? 100/q : 100 / q + 1 ;//è±éå¨timeåååè¦æå°bossï¼
        for (i = 1 ; i <= time ; i ++)
        {
            for (j = 1 ; j <= 100 ; j ++)
            {
                if (dp[j] == -1)
                    continue;
                for (k = 0 ; k <= n ; k ++)
                {
                    if (j <= skill[k].bi && dp[j] >= skill[k].ai)
                    {
                        printf ("%d\n",i);
                        p = 1;
                        break;
                    }
                    else if (j > skill[k].bi && dp[j] >= skill[k].ai)
                    {
                        dp[j - skill[k].bi] = max (dp[j - skill[k].bi],dp[j] - skill[k].ai + t);
                        if (dp[j + skill[k].bi] > 100)
                            dp[j + skill[k].bi] = 100;
                    }
                }
                if (p)
                    break;
            }
            if(p)
                break;

        }
        if (!p)
            printf ("My god\n");    
    }
}