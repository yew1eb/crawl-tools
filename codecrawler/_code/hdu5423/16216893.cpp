#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

bool Map[1005][1005];
int d[1005],n,cnt[1005];

void dfs(int u,int dep)
{
    d[u]=dep;
    for(int i=1;i<=n;++i)
        if(Map[u][i]&&d[i]==-1)
            dfs(i,dep+1);
}


int main()
{
    int x,y,i;
    while(~scanf("%d",&n))
    {
        memset(Map,0,sizeof(Map));
        for(i=0;i<n-1;++i){
            scanf("%d%d",&x,&y);
            Map[x][y]=Map[y][x]=1;
        }
        memset(d,-1,sizeof(d));
        memset(cnt,0,sizeof(cnt));
        dfs(1,0);
        for(i=1;i<=n;++i)
            cnt[d[i]]++;
        int tmp=0;
        for(i=1;i<n;++i)
        {
            if(cnt[i]){
                if(cnt[i]<=cnt[tmp]&&cnt[tmp]>1) break;
                else tmp=i;
            }
        }
        if(i==n) puts("YES");
        else puts("NO");
    }
    return 0;
}