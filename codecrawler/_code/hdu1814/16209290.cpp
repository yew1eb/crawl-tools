#include <cstdio>
#include <iostream>

using namespace std;

int n,m,len;
int col[50005],ans[50005];
int fi[50005],ne[50005];
struct edge
{
    int u,v;
}e[50005];

bool dfs(int x)
{
    if (col[x]==1) return 1;
    if (col[x]==2) return 0;
    col[x]=1; col[x^1]=2;
    ans[len++]=x;
    for (int i=fi[x];i!=-1;i=ne[i])
    {
       if (!dfs(e[i].v)) return 0;
    }
    return 1;
}

bool work()
{
    for (int i=0;i<n;i++) col[i]=0;
    for (int i=0;i<n;i++)
    {
        if (col[i]) continue;
        len=0;
        if (!dfs(i))
        {
            for (int j=0;j<len;j++)
            {
                col[ans[j]]=0;
                col[ans[j]^1]=0;
            }
            if (!dfs(i^1)) return 0;
        }
    }
    return 1;
}

int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        n=n*2;
        for (int i=0;i<n;i++) fi[i]=-1;
        for (int i=0;i<m;i++)
        {
            int j,k;
            scanf("%d%d",&j,&k);
            j--; k--;
            e[2*i].u=j; e[2*i].v=k^1; ne[2*i]=fi[j]; fi[j]=2*i;
            e[2*i+1].u=k; e[2*i+1].v=j^1; ne[2*i+1]=fi[k];  fi[k]=2*i+1;
        }
        if (work())
        {
            for (int i=0;i<n;i++)
                if (col[i]==1) printf("%d\n",i+1);
        }
        else printf("NIE\n");
    }
    return 0;
}