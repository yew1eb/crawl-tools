#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std ;
const int MAXN = 1111 ;
struct point
{
    int x ;
    int y ;
} ho[MAXN] , ve[MAXN];
int g[MAXN][MAXN] ;
int cx[MAXN] ;
int cy[MAXN] ;
int vis[MAXN] ;
int n , m ;
int path(int v)  // 匈牙利算法
{
    int i ;
    for(i = 0 ; i < m ; i ++)
    {
        if(g[v][i] == 1 && !vis[i])
        {
            vis[i] = 1 ;
            if(cy[i] == -1 || path(cy[i]))
            {
                cy[i] = v ;
                cx[v] = i ;
                return 1 ;
            }
        }
    }
    return 0 ;
}
int pi(point a , point b) // 判断是否重叠
{
    if(a.x == b.x && a.y == b.y)
        return 1 ;
    if(a.x == b.x && a.y == b.y + 1)
        return 1 ;
    if(a.x + 1 == b.x && a.y == b.y)
        return 1 ;
    if(a.x + 1 == b.x && a.y == b.y + 1)
        return 1 ;
    return 0 ;
}
void init()
{
    while (cin >> n >> m)
    {
        if(n == 0 && m == 0)
            break ;
        memset(g , 0 , sizeof(g)) ;
        memset(cx , -1 , sizeof(cx)) ; // 均初始化为-1 ，代表此点未被覆盖
        memset(cy , -1 , sizeof(cy)) ;
        int i , j ;
        for(i = 0 ; i < n ; i ++)
        {
            scanf("%d%d" , &ho[i].x , &ho[i].y) ;
        }
        for(j = 0 ; j < m ; j ++)
        {
            scanf("%d%d" , &ve[j].x , &ve[j].y) ;
        }
        for(i = 0 ; i < n ; i ++)
        {
            for(j = 0 ; j < m ; j ++)
                if(pi(ho[i] , ve[j]))
                {
                    g[i][j] = 1 ; // 建图，注意这里千万不能写成 g[i][j] = g[j][i] = 1 !!
                }
        }
        int ans = 0 ; // 记录匹配数
        for(i = 0 ; i < n ; i ++)
        {
            if(cx[i] == -1)  // 如果 第i张 水平放置 的牌未被覆盖 ， 就从此点出发寻找增广路
            {
                memset(vis , 0 ,sizeof(vis)) ;
                ans += path(i) ;
            }
        }
        printf("%d\n" , n + m - ans) ;
    }
}
int main()
{
    init() ;
    return 0 ;
}
