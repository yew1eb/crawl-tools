#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int Tmax=15,Tmax2=59050,th[15]={1,3,9,27,81,243,729,2187,6561,19683,59049},inf=0x3f3f3f3f;
int n,m,map[Tmax][Tmax],f[Tmax2][Tmax],v[Tmax2][Tmax],ans;
void init()
{
    int i,j,num;
    for(i=1;i<=th[10];i++)
    {
        num=i;
        for(j=0;j<10;j++)
        {
            v[i][j]=num%3;
            num/=3;
        }
    }
    return;
}
void work()
{
    int i,j,k;
    bool ok;
    for(i=0;i<n;i++)
      f[th[i]][i]=0;
    for(i=1;i<=th[n];i++)
    {
        ok=true;
        for(j=0;j<n;j++)
          if(v[i][j]!=0)
          {
              for(k=0;k<n;k++)
                if(v[i][k]!=0&&map[j][k]!=inf&&j!=k)
                  f[i][j]=min(f[i][j],f[i-th[j]][k]+map[j][k]);
          }
          else ok=false;
        if(ok) for(j=0;j<n;j++)
          ans=min(ans,f[i][j]);
    }
    if(ans==inf) printf("-1\n");
    else printf("%d\n",ans);
    return;
}
int main()
{
    int i,u,v,w;
    init();
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(map,0x3f,sizeof(map));
        memset(f,0x3f,sizeof(f));
        ans=inf;
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            map[u-1][v-1]=map[v-1][u-1]=min(map[u-1][v-1],w);
        }
        work();
    }
    return 0;
}