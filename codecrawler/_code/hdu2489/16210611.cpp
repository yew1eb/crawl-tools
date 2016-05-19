//ç»ä¸ä¸ªå®å¨å¾ï¼å¨å¶ä¸­æ¾ä¸é¢æ ï¼ä½¿å¾è¾¹çæå¼ä¹åé¤ä»¥ç¹çæå¼ä¹åæå°
//ç±äºn<=15ï¼ç´æ¥æ´åæä¸¾ææéçç¹çæåµï¼å¨ä»è¿äºç¹æ¾æå°çææ 
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std ;
const int inf = 0x3f3f3f3f ;
const int maxn = 20 ;
int vis[maxn] ;
int dis[maxn] ;
int tmp[maxn] ;
int w[maxn] ;int a[maxn] ;
int map[maxn][maxn] ;
int n , m;
int prim()
{
    int pos ;
    memcpy(tmp , vis , sizeof(vis)) ;
    for(int i = 1;i <= n;i++)
    if(!vis[i])
    {
        vis[i] = 1 ;
        pos = i ;
        break;
    }
    for(int i = 1;i <= n;i++)
    dis[i] = i == pos ? 0 : map[pos][i] ;
    int ans = 0 ;
    while(1)
    {
        int mi = inf ;
        for(int i = 1;i <= n;i++)
        if(!vis[i] && dis[i] < mi)
        mi = dis[pos = i] ;
        if(mi == inf)break;
        vis[pos] = 1;
        ans += mi ;
        for(int i = 1;i <= n;i++)
        if(!vis[i])
        dis[i] = min(dis[i] , map[pos][i]) ;
    }
    memcpy(vis , tmp , sizeof(tmp)) ;
    return ans ;
}
double ans = inf ;
void dfs(int pos , int num , double sum )
{
    if(num == m)
    {
        double sum_e = prim() ;
        if(sum_e/sum < ans)
        {
            ans = sum_e/sum ;
            memcpy(a , vis , sizeof(vis)) ;
        }
        return ;
    }
    for(int i = pos;i <= n;i++)
    {
        if(!vis[i])continue ;
        vis[i] = 0 ;
        dfs(i , num + 1 , sum + w[i]) ;
        vis[i] = 1 ;
    }
}
int main()
{
    //freopen("in.txt" ,"r" , stdin) ;
    while(scanf("%d%d" , &n ,&m) &&(n+m))
    {
        for(int i = 1;i <= n;i++)
        scanf("%d" , &w[i]) ;
        for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n ;j++)
        scanf("%d" , &map[i][j]) ;
        for(int i = 1;i <= n;i++)
        vis[i] = 1;
        ans = inf ;
        dfs(1,0 , 0) ;
        int flag = 0 ;
        for(int i = 1;i <= n ;i++)
        if(!a[i])
        {
            if(flag)printf(" ") ;
            printf("%d" , i) ;
            flag = 1 ;
        }
        puts("") ;
    }
    return 0 ;
}
