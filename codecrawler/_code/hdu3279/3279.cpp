#include<stdio.h>
#include<string.h>
#include<algorithm>
#define clr(a,b) memset(a,b,sizeof(a))
#define maxn 65
#define maxm 100005

using namespace std;
int next[maxn*maxm],ev[maxn*maxm],first[maxn];
int vis[maxm],mat[maxm],matx[maxn],ca,n,x,y,e;
void add(int u,int v)
{
    next[e]=first[u],ev[e]=v,first[u]=e++;
}
bool find(int u)
{
    int v;
    for(int i=first[u];i!=-1;i=next[i])
    {
        v=ev[i];
        if(!vis[v])
        {
            vis[v]=1;
            if(mat[v]==-1||find(mat[v]))
            {
                mat[v]=u;
                matx[u]=v;
                return 1;
            }
        }
    }
    return 0;
}
int Hungary(int nx)
{
    int Max=0;
    clr(mat,-1);
    clr(matx,-1);
    for(int i=nx;i>=1;i--)
    {
        clr(vis,0);
        if(find(i))
            Max++;
    }
    return Max;
}
int main()
{
    //freopen("D:/d.txt","r",stdin);
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
        clr(first,-1);
        e=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&x,&y);
            for(int j=x;j<=y;j++)
               add(i,j);
        }
        int ans=Hungary(n);
        printf("%d\n",ans);
        int count=0;
        for(int i=1;i<=n;i++)
          if(matx[i]!=-1)
          {
              count++;
              if(count==ans)
                 printf("%d\n",i);
              else printf("%d ",i);
          }
    }
    return 0;
}