//ÍêÈ«±³°ü
//Çó°Ñ±³°üÌîÂúµÄ×îÐ¡¼ÛÖµ
#include <stdio.h>
#include <string.h>
#define MAXN 10000
#define min(a,b) ((a)<(b)?(a):(b))
const int INF = 1000000000;
int dp[MAXN+10];

int main()
{
    int t, e, f, n, i, p, w, v, j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&e,&f); v = f-e;
        scanf("%d",&n);
        for(i=1; i<=v; i++) dp[i] = INF;
        dp[0] = 0;
        for(i=0; i<n; i++)
        {
            scanf("%d%d",&p, &w);
            for(j=w; j<=v; j++)
                dp[j] = min(dp[j], dp[j-w] + p);
        }
        if(dp[v]>=INF) printf("This is impossible.\n");
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[v]);
    }
    return 0;
}
