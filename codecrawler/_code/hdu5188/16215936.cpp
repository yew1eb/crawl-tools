#include "cstring"
#include "cstdio"
#include "iostream"
#include "string.h"
#include "algorithm"
using namespace std;
typedef struct node
{
    int t,v,l;
    bool operator < ( const node& a ) const
    {
        return l-t < a.l - a.t;
    }
}node;
int dp[3000007];
int main()
{
    int n,w;
    while(~scanf("%d%d",&n,&w))
    {
        node p[31];
        memset(dp,0,sizeof(dp));
        int maxium,sum1,sum2;
        maxium=sum1=sum2=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&p[i].t,&p[i].v,&p[i].l);
            sum1+=p[i].v;
            sum2+=p[i].t;
            maxium=max(maxium,p[i].l);
        }
        bool flag=1;
        sort(p+1,p+n+1);
        if(sum1<w)
            flag=0;
        maxium=max(maxium,sum2);
        for(int i=1;i<=n&&flag==1;i++)
        {
            for(int j=maxium;j>=p[i].l;j--)
            {
                if(j>=p[i].t)
                    dp[j]=max(dp[j],dp[j-p[i].t]+p[i].v);
            }
        }
        for(int i=0;i<=maxium&&flag;i++)
            if(dp[i]> w)
            {
                printf("%d\n",i);
                break;
            }
        if(!flag)puts("zhx is naive!");
    }
}