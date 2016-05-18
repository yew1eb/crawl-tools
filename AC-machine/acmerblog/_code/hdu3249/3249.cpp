#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define inf 0x3f3f3f3f
struct node
{
    int l;
    int p;
}a[10005];
bool cmp(node b,node c)
{
    return b.p<c.p;
}
int dp[10005];

int search(int k)
{
    for(int i=1;i<=k;i++)
    {
        if(a[k].p<dp[i])
        return i-1;
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        for(int i=1;i<=n;i++)
            scanf("%d%d",&a[i].l,&a[i].p);
        sort(a+1,a+1+n,cmp);                //根据pole位置升序
        memset(dp+1,0x3f,sizeof(int)*(n+1));
        dp[0]=-inf;
        int top=0;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            top=search(i);  //找到第i个线段影响的top，例如样例的5 9,6 10，都会影响到dp[2]
                            
            dp[top+1]=min(dp[top+1],a[i].p>=dp[top]+a[i].l?a[i].p:dp[top]+a[i].l);  //通过转移方程找到最优解
            if(top+1>ans)   //记录答案
            ans=top+1;
        }

        printf("%d\n",ans);
    }
    return 0;
}