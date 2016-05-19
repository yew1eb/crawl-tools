#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
bool vis[1010];
int deg[1010];
int Map[1010][1010];
int fg;
void dfs(int u,int cnt)
{
    vis[u]=true;
    if(cnt==n)
    {
        fg=1;
        return;    
    }
    for(int i=1;i<=n&&!fg;i++)
    {
        if(!vis[i]&&Map[u][i])
        {
            dfs(i,cnt+1);
            vis[i]=false;
        }
    }
}
int main(){
   //freopen("in.txt","r",stdin);
   int i,u,v;
   while(scanf("%d",&n)!=EOF)
   {
           memset(deg,0,sizeof(deg)); 
           memset(vis,0,sizeof(vis));  
        memset(Map,0,sizeof(Map));
           for(i=1;i<=n;i++)
           {
               scanf("%d%d",&u,&v);
               if(u!=v&&!Map[u][v])//æé¤èªç¯åéè¾¹ 
               {
                deg[u]++;
                deg[v]++;
                Map[u][v]=Map[v][u]=1;
            }
        }
        int tot=0;
        int st=1;
        for(i=1;i<=n;i++)
        {
            if(deg[i]==1)
            {
                tot++;
                st=i;
            }    
        }
        if(tot>2)
            puts("NO");
        else
        {
            fg=0;
            dfs(st,1);//ä»åº¦æ°ä¸º1çç¹å¼å§æ·±æ 
            if(fg)
            {
                puts("YES");
            }
            else
            {
                puts("NO");
            }
        }
   }
   return 0;
}