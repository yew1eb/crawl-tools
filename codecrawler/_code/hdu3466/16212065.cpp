#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct node
{
    int p,q,v;
} a[555];

int cmp(node x,node y)//æq-pæåºï¼ä¿è¯å·®é¢æå°ä¸ºæä¼
{
    return x.q-x.p<y.q-y.p;
}

int main()
{
    int n,m,i,j;
    int dp[5555];
    while(~scanf("%d%d",&n,&m))
    {
        for(i = 0; i<n; i++)
            scanf("%d%d%d",&a[i].p,&a[i].q,&a[i].v);
        memset(dp,0,sizeof(dp));
        sort(a,a+n,cmp);
        for(i = 0; i<n; i++)
        {
            for(j = m; j>=a[i].q; j--)//å©ä½çé±å¤§äºqæè½ä¹°
            {
                dp[j] = max(dp[j],dp[j-a[i].p]+a[i].v);//è¿éçj-a[i].på³å®äºä¹åçæåºæ¹æ³
            }
        }
        printf("%d\n",dp[m]);
    }

    return 0;
}
