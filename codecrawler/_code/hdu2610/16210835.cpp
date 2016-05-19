#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int n,p,a[1005],sta[1005],h,ans;
bool vis[1005],f;

void finish()
{
    for (int i=0;i<h-1;i++) printf("%d ",sta[i]);
    printf("%d\n",sta[h-1]);
    ans++;
}

bool check(int last,int d,int x,int p)
{
    return  x>=last && !vis[p];
}

void dfs(int last,int lastp,int d,int l)
{
    if (n-lastp<l-d) return;
    bool flag[1005];
    memset(flag,0,sizeof(flag));
    if (d==l)
    {
        finish(); f=1;
        return ;
    }
    for (int i=lastp+1;i<=n;i++) if (check(last,d,a[i],i) && !flag[a[i]])
    {
        sta[h++]=a[i]; flag[a[i]]=1; vis[i]=1;
        dfs(a[i],i,d+1,l);
        if (ans==p) return;
        sta[--h]=0; vis[i]=0;
    }
}

int main()
{
    while (scanf("%d%d",&n,&p)!=EOF)
    {
        ans=0;
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        for (int l=1;l<=n-1;l++)
        {
            f=0;
            memset(vis,0,sizeof(vis));
            memset(sta,0,sizeof(sta)); h=0;
            dfs(0,0,0,l);
            if (!f) break;
            if (ans==p) break;
        }
        printf("\n");
    }
    return 0;
}
