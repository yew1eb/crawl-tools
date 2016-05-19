#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
const int maxn = 505;
using namespace std;
int n,m;
struct Point
{
    int location;
    int high;
}dp[maxn*maxn];
struct node
{
    int num;
    int H;
}map[maxn][maxn];
int fx[] = {-1,1,0,0};
int fy[] = {0,0,-1,1};
int cmp(const void *a, const void *b)
{
    Point *c = (Point*)a;
    Point *d = (Point*)b;
    if(c->high == d->high)
        return c->location - d->location;
    return c->high - d->high;
}
int par[maxn*maxn],vis[maxn][maxn];
int Find(int x)
{
    if(par[x] == x)
        return x;
    par[x] = Find(par[x]);
    return par[x];
}
int main()
{
    int t;
    __int64 ans;
    scanf("%d",&t);
    while(t--)
    {
        ans = 0;
        scanf("%d%d",&n,&m);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                scanf("%d",&map[i][j].H);
                map[i][j].num = 1;
                dp[i*m+j].high = map[i][j].H;
                dp[i*m+j].location = i*m+j;
                par[i*m+j] = i*m+j;
                vis[i][j] = 0;
            }
        }
        qsort(dp,n*m,sizeof(dp[0]),cmp);
        for(int i = 0; i < n*m; i++)
        {
            bool flag = false;
            int x = dp[i].location/m;
            int y = dp[i].location%m;
            vis[x][y] = 1;
            for(int j = 0; j < 4; j++)
            {
                int xi = x+fx[j];
                int yi = y+fy[j];
                if(xi<0||xi>=n||yi<0||yi>=m)
                {
                    flag = true;
                    continue;
                }
                int fa = Find(xi*m+yi);
                if(fa == dp[i].location)continue;
                xi = fa/m;
                yi = fa%m;
                if(vis[xi][yi]==1&&map[xi][yi].num != 0)
                {
                    ans += (map[x][y].H-map[xi][yi].H)*map[xi][yi].num;
                    par[fa] = dp[i].location;
                    map[x][y].num += map[xi][yi].num;
                }
                else if(map[xi][yi].num == 0)
                {
                    flag = true;
                    par[fa] = dp[i].location;
                }
            }
            if(flag)
                map[x][y].num = 0;
        }
        cout<<ans<<endl;
    }
    return 0;
}