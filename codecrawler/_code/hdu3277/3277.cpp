#include"stdio.h"
#include"iostream"
#include"string.h"
#include"stdlib.h"
#include"queue"
using namespace std;
int t,m,n,f;
int map[101][101],link[101],vy[101],fa[101],rank[101];
void make_()
{
  for(int i=1;i<=n;i++) rank[i]=0,fa[i]=i;
}
int find_(int x)
{
  if(fa[x]!=x) fa[x]=find_(fa[x]);
  return fa[x];
}
void union_(int x,int y)
{
  int fx,fy;
  fx=find_(x);
  fy=find_(y);
  if(fx==fy) return ;
  if(rank[fx]>rank[fy])
  {
    fa[fy]=fx;
  }
  else
  {
    fa[fx]=fy;
    if(rank[fx]==rank[fy]) rank[fy]++;
  }
}
int xiongyali(int i)
{
  int j,k;
  for(j=1;j<=n;j++)
  {
    if(!vy[j] && map[i][j])
    {
      vy[j]=1;
      if(!link[j] || xiongyali(link[j]))
      {
        link[j]=i;
        return 1;
      }
    }
  }
  return 0;
}
void del()
{
  int i;
  for(i=1;i<=n;i++)
    map[link[i]][i]=0;
}
int solve()
{
  int i,j,k,temp,ans=0;
  while(1)
  {
    memset(link,0,sizeof(link));
    temp=0;
    for(i=1;i<=n;i++)
    {
      memset(vy,0,sizeof(vy));
      if(xiongyali(i)) temp++;
    }
    //printf("%d\n",temp);
    if(temp==n)
    {
      ans++;
      del();
    }
    else break;
  }
  return ans;
}
int main()
{
  int i,j,k,l,p;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d%d",&n,&m,&f);
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        map[i][j]=0;
    for(i=1;i<=m;i++)
    {
      scanf("%d%d",&j,&k);
      map[j][k]=1;
    }
    make_();
    for(i=1;i<=f;i++)
    {
      scanf("%d%d",&j,&k);
      union_(j,k);
    }
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        if(j==i) continue;
        else
          if(find_(i)==find_(j))
            for(k=1;k<=n;k++)
              if(map[j][k]) map[i][k]=1;
    int ans=solve();
    printf("%d\n",ans);
  }
  return 0;
}