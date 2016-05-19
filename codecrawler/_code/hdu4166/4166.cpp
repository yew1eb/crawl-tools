#include <stdio.h> 
#include <string.h>  
#include <queue>  
#include <algorithm>  
  
using namespace std;  
#define N 1003  
const int INF = 100000000;  
int m,n,Mod,move[][2] = {0,1,-1,0,0,-1,1,0};  
struct node  
{  
    int step,dir,x,y;  
}p,pt;  
  
int dx,dy,sx,sy,dic,d[N][N][4],dp[N][N][4],vis[N][N][4];  
char maz[N][N];  
int cas = 0;  
  
bool operator<(node aa,node bb)  
{  
    return aa.step > bb.step;  
}  
bool inner(int x,int y)  
{  
    return x >= 0 && x < m && y >= 0 && y < n && maz[x][y] == '.';  
}  
int dfs(int x,int y,int di)  
{  
    if(dp[x][y][di])  
        return dp[x][y][di];  
    int k,xx,yy,res = 0;  
    k = (di + 1) % 4;  
    if(d[x][y][di] == d[x][y][k] + 1)  
        res = (res + dfs(x,y,k)) % Mod;  
  
    k = (di + 3) % 4;  
    if(d[x][y][di] == d[x][y][k] + 1)  
        res = ( res + dfs(x,y,k)) % Mod;  
  
    k = (di + 2) % 4;  
    xx = x + move[k][0];  
    yy = y + move[k][1];  
    if(inner(xx,yy) && d[x][y][di] == d[xx][yy][di] + 1)  
        res = ( res + dfs(xx,yy,di)) % Mod;  
  
    return dp[x][y][di] = res;  
}  
void bfs()  
{  
      
    if(sx == dx && sy == dy) ///杩欎釜澶彈浼や簡锛岃捣鐐圭粓鐐圭浉鍚屾椂缁撴灉搴旇鏄�1锛屼笉璇ョ壒鍒ょ殑锛岀敾铔囨坊瓒充簡銆�  
    {  
        printf("1\n");  
        return ;  
    }  
      
    memset(vis,0,sizeof(vis));  
    int i,j,k;  
    for(i = 0; i < m; ++i)  
        for(j = 0; j < n; ++j)  
            for(k = 0; k < 4; ++k)  
                d[i][j][k] = INF;  
    priority_queue<node> que;  
    p.x = dx;  
    p.y = dy;  
    p.step = 0;  
    for(k = 0; k < 4; ++k)  
    {  
        p.dir = k;  
        que.push(p);  
        d[dx][dy][k] = 0;  
    }  
  
    while(!que.empty())  
    {  
        p = que.top();  
        que.pop();  
  
        if(vis[p.x][p.y][p.dir])  
            continue;  
        vis[p.x][p.y][p.dir] = 1;  
  
        pt = p;  
        pt.step ++;  
        k = (p.dir + 1) % 4;  
  
        if(pt.step < d[p.x][p.y][k])  
        {  
            pt.dir = k;  
            d[pt.x][pt.y][pt.dir] = pt.step;  
            que.push(pt);  
        }  
  
        k = (p.dir + 3) % 4;  
        if(pt.step < d[p.x][p.y][k])  
        {  
            pt.dir = k;  
            d[pt.x][pt.y][pt.dir] = pt.step;  
            que.push(pt);  
        }  
  
        pt.dir = p.dir;  
        pt.x += move[p.dir][0];  
        pt.y += move[p.dir][1];  
  
  
        if(inner(pt.x,pt.y) && !vis[pt.x][pt.y][pt.dir] && pt.step < d[pt.x][pt.y][pt.dir] )  
        {  
            d[pt.x][pt.y][pt.dir] = pt.step;  
            que.push(pt);  
        }  
    }  
    if(d[sx][sy][dic] == INF)  
    {  
        printf("-1\n");  
        return;  
    }  
    printf("%d\n",dfs(sx,sy,dic));  
}  
  
int main()  
{  
    //freopen("robot.in","r",stdin);  
   // freopen("12.out","w",stdout);  
    int i,j,k;  
    char c[5];  
///琚緭鍏ュ潙浜嗭紝鏄庢槑璇磎 == 0缁撴潫鐨勶紝Mod棰濄�傘�傘�傘��  
    while(scanf("%d%d%d",&m,&n,&Mod) != EOF && Mod)  
    {  
        for(i = 0; i < m; ++i)  
            scanf("%s",maz[i]);  
        scanf("%d%d%d%d %s",&sx,&sy,&dx,&dy,c);  
        if(c[0] == 'E')  
            dic = 2;  
        else if(c[0] == 'N')  
            dic = 3;  
        else if(c[0] == 'W')  
            dic = 0;  
        else  
            dic = 1;  
        memset(dp,0,sizeof(dp));  
        for(i = 0; i < 4; ++i)  dp[dx][dy][i] = 1;  
        printf("Case %d: %d ",++cas,Mod);  
        bfs();  
    }  
    return 0;  
}