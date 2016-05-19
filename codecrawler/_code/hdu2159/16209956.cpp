#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct node
{
    int val,wei;
} a[155];

int dp[155][155];

int main()
{
    int n,m,k,s,x,y,z,i;
    while(~scanf("%d%d%d%d",&n,&m,&k,&s))
    {
        for(i = 1; i<=k; i++)
            scanf("%d%d",&a[i].val,&a[i].wei);
        memset(dp,0,sizeof(dp));
        for(x = 1; x<=m; x++)
        {
            for(y = 1; y<=k; y++)
            {
                for(z = 1; z<=s; z++)
                {
                    int cnt = 1;
                    while(cnt*a[y].wei<=x && cnt<=z)
                    {
                        dp[x][z] = max(dp[x][z],dp[x-cnt*a[y].wei][z-cnt]+cnt*a[y].val);
                        cnt++;
                    }
                }
            }
            if(dp[x][s]>=n)
            break;
        }
        if(x>m)
        printf("-1\n");
        else
        printf("%d\n",m-x);
    }
    return 0;
}
