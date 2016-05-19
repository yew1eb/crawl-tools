#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=110;
int e[maxn][maxn];
int vis[maxn],n;
int bfs(int x)//ä»xç¹å¼å§åç»ã 
{
    queue<int>q;
    q.push(x);
    vis[x]=1;
    int i,j,k,u,v;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=1;i<=n;i++)
        {
            if(e[u][i]==1||u==i)continue;
            if(vis[i]==-1)
            {
                vis[i]=1-vis[u];
                q.push(i);
            }
            else if(vis[i]==vis[u])return 0;
        }
    }
    return 1;
}
int main()
{
    while(cin>>n)
    {
        int i,j,k,a;
        memset(e,0,sizeof(e));
        memset(vis,-1,sizeof(vis));
        for(i=1;i<=n;i++)
        {
            while(cin>>a&&a!=0)
            e[i][a]=1;
        }
        //æ¹ææ åå¾ 
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(!e[i][j])e[j][i]=0;
        for(i=1;i<=n;i++)
        {
            if(vis[i]!=-1)continue;
            if(!bfs(i))break;
        }
        if(i<=n)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
/*
    é¢æï¼å°nä¸ªäººåæä¸¤ç»ï¼ä½¿å¾æ¯ç»ä¸­çæ¯ä¸ªäººé½è®¤è¯å©ä½ææäººã
    ç¨äºç»´æ°ç»eè®°å½å³ç³»ï¼e[i][j]==0è¡¨ç¤ºiä¸è®¤è¯jã
    vis[i]è¡¨ç¤ºç»å«ï¼åå«ä¸º1å0ãåå¯ç¥è¥e[i][j]==0 ,åiåjå¿å®æ¯ä¸ä¸ªæ¯0ï¼ä¸ä¸ªæ¯1ã
bfsä¸éï¼å½åºç°çç¾çæ¶åå°±ä¸è½åç»ã
    ç±äºæä¸¾ææç¹ä½èµ·ç¹ï¼ä¸èµ·ç¹ä¸º1ç»åãåe[i][j]=0,e[j][i]=1åe[i][j]=e[j][i]=0æåµç¸åã
ä¸ºé¿åèµ·ç¹ä¸º1é æçåå§åéè¯¯ï¼æä»¥è®²æåä¸è®¤è¯å¾ï¼æ¹ææ åå¾ãä¾ï¼ä¸è®¤è¯å³ç³»ï¼3->1->2->4,
å¼å§æä¸¾1ï¼åvis[1]=1,vis[2]=0,vis[4]=1,åæä¸¾3,vis[3]=1,vis[1]=0,çç¾ï¼å¯æåµæ¯è½åæ(3,2)å(1,4)çã 
*/