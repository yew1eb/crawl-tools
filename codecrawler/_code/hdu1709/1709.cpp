#include <cstdio>
#include <cstring>
using namespace std;

int vis[10005];
int x[10005];
int dp[10005];
int abs(int x)
{
    return x<0?-x:x;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        memset(dp,0,sizeof(dp));
        int sum=0,cnt=0;
        vis[0]=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x[i]);
            sum+=x[i];
        }
        for(int i=1;i<=n;i++)
        {
            memset(dp,0,sizeof(dp));
            for(int j=0;j<=sum;j++)
            {
                if(vis[j])
                {
                    dp[j+x[i]]=1;
                    dp[abs(j-x[i])]=1;
                }
            }
            for(int j=0;j<=sum;j++)
            if(dp[j])vis[j]=1;
        }

        for(int i=1;i<=sum;i++)
        {
            if(!vis[i])cnt++;
        }

        bool first=false;

        printf("%d\n",cnt);

        for(int i=1;i<=sum;i++)
        {
            if(!vis[i])
            {
                if(!first)
                {
                    printf("%d",i);
                    first=true;
                }
                else printf(" %d",i);
            }
        }

        if(cnt)puts("");
    }
}