#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <ctime>
#include <cmath>
#include <cctype>
using namespace std;
#define maxn 330
#define LL long long
int cas=1,T;
int n,m;
char mapp[maxn][maxn];
int d[maxn][maxn],vis[maxn][maxn];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
struct Node
{
    int x,y;
};
bool check(int x,int y)
{
    if (x<0 || x>=n || y<0 || y>=m ||vis[x][y])
        return false;
    return true;
}
int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        memset(d,0,sizeof(d));
        memset(vis,0,sizeof(vis));
        Node s;
        queue<Node> q;
        for (int i = 0;i<n;i++)
        {
            scanf("%s",mapp[i]);
            for (int j = 0;j<m;j++)
            {
                if (mapp[i][j] == '1')
                {
                    s.x=i;
                    s.y=j;
                    q.push(s);
                    vis[i][j]=1;
                }
            }
        }

        while (!q.empty())
        {
            s=q.front();q.pop();
            for (int i = 0;i<4;i++)
            {
                Node temp;
                temp.x = s.x+dir[i][0];
                temp.y = s.y+dir[i][1];
                if (!check(temp.x,temp.y))
                    continue;
                q.push(temp);
                vis[temp.x][temp.y]=1;
                d[temp.x][temp.y] = d[s.x][s.y]+1;
            }
        }

        for (int i =0;i<n;i++)
        {
            printf("%d",d[i][0]);
            for (int j = 1;j<m;j++)
                printf(" %d",d[i][j]);
            printf("\n");
        }
    }
    //freopen("in","r",stdin);
    //scanf("%d",&T);
    //printf("time=%.3lf",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
