#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct node
{
    int v,w;
}a[20];

int dp[100000];

int main()
{
    int t,n,i,j,k,val,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&val,&y);
        scanf("%d",&n);
        for(i = 1;i<=n;i++)
        {
            scanf("%d%d",&a[i].v,&a[i].w);
            a[i].v/=1000;//è¿è¡åç¼©
        }
        for(i = 1;i<=y;i++)
        {
            int s = val/1000;//æ¯å¹´æ¬éé½æ¯ä¸ä¸å¹´æ¬éä¸å©æ¯ä¹å
            memset(dp,0,sizeof(dp));//æ¯å¹´é½è¦éæ°å­å©æ¯
            for(j = 1;j<=n;j++)//å®å¨èå
            {
                for(k = a[j].v;k<=s;k++)
                {
                    dp[k]=max(dp[k],dp[k-a[j].v]+a[j].w);
                }
            }
            val+=dp[s];//æ¯å¹´çæå¤§æ¬å©å
        }
        printf("%d\n",val);
    }

    return 0;
}
