#include<algorithm>
#include<cstdio>
#include<string.h>
#include<queue>
#include<cmath>
using namespace std;
const int N=102;
int dist[N];
int map[102][102];
const int INF=999999;
bool vis[102];
int prim(int n,int m)
{
    memset(vis,false,sizeof(vis));
    for(int i=0;i<=n;i++)
    {  
        for(int j=0;j<=n;j++)
        {
            if(i!=j)
         map[i][j]=INF;
            else
                map[i][j]=0;
        }
        
    }
    int u,v,val,ok=0;
    
    for(int i=0;i<m;i++)
    {
      scanf("%d%d%d%d",&u,&v,&val,&ok);
       if(ok)
          val=0;
      // if(map[u][v]>val)
      map[v][u]=map[u][v]=val;
     }
    for(int i=1;i<=n;i++)
    {
     dist[i]=map[1][i];
    }
    dist[1]=INF;
    vis[1]=true;
    int Min,sum=0,p=-1;

    for(int i=1;i<n;i++)
    {
     Min=INF;
     for(int j=1;j<=n;j++)
     {
      if(!vis[j] && dist[j] < Min)
      {
       Min=dist[j];
       p=j;
      }
     }
      sum+=dist[p];
     // printf("dist[%d]= %d\n",p,dist[p]);
      vis[p]=true;
      
      for(int j=1;j<=n;j++)
      {
       if(!vis[j] && dist[j] > map[p][j])
       {
         dist[j]=map[p][j];
       }
      }
    }
    return sum;
}
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
     printf("%d\n",prim(n,n*(n-1)/2));
    }
  return 0;
}