#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <bitset>
#include <algorithm>
#include <climits>
using namespace std;

#define ls 2*i
#define rs 2*i+1
#define UP(i,x,y) for(i=x;i<=y;i++)
#define DOWN(i,x,y) for(i=x;i>=y;i--)
#define MEM(a,x) memset(a,x,sizeof(a))
#define W(a) while(a)
#define gcd(a,b) __gcd(a,b)
#define LL long long
#define N 205
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define EXP 1e-8
#define rank rank1
const int mod = 10007;

struct node
{
    int x,y,step,key;
};

int n,m,sx,sy,knum,kk[N][N];
char g[N][N];
bool vis[N][N][4][1<<7];
bool used[N][N][1<<7];
int to[4][2]= {1,0,0,1,-1,0,0,-1};


int check(int x,int y)
{
    if(x<0||y<0||x>=n||y>=m)
        return 1;
    return 0;
}

int bfs()
{
    int i,j;
    MEM(vis,0);
    MEM(used,0);
    queue<node> Q;
    node a,next;
    a.x = sx;
    a.y = sy;
    a.step = 0;
    a.key = 0;
    Q.push(a);
    used[a.x][a.y][0] = 1;
    while(!Q.empty())
    {
        a = Q.front();
        Q.pop();
        for(i = 0; i<4; i++)
        {
            int mx=to[i][0],my=to[i][1];
            int x,y,k,d;
            x = a.x,y=a.y,k=a.key;
            while(1)
            {
                if(g[x][y]=='D')
                    mx=1,my=0;
                if(g[x][y]=='R')
                    mx=-0,my=1;
                if(g[x][y]=='U')
                    mx=-1,my=0;
                if(g[x][y]=='L')
                    mx=0,my=-1;

                if(mx==1&&my==0)
                    d=0;
                if(mx==0&&my==1)
                    d=1;
                if(mx==-1&&my==0)
                    d=2;
                if(mx==0&&my==-1)
                    d=3;

                if(vis[x][y][d][k])
                    break;
                vis[x][y][d][k] = 1;
                x+=mx,y+=my;
                if(check(x,y)) break;
                if(g[x][y]=='#') break;

                if(g[x][y]=='E'&&k==(1<<knum)-1)
                    return a.step+1;

                if(g[x][y]=='D')
                    mx=1,my=0;
                if(g[x][y]=='R')
                    mx=-0,my=1;
                if(g[x][y]=='U')
                    mx=-1,my=0;
                if(g[x][y]=='L')
                    mx=0,my=-1;
                if(g[x][y]=='K')
                    k|=kk[x][y];

                if(!check(x+mx,y+my)&&g[x+mx][y+my]=='#')
                {
                    if(used[x][y][k])
                        break;
                    used[x][y][k] = 1;
                    next.x = x;
                    next.y = y;
                    next.key = k;
                    next.step=a.step+1;
                    Q.push(next);
                    break;
                }
            }
        }
    }
    return -1;
}

int main()
{
    int i,j;
    while(~scanf("%d%d",&n,&m))
    {
        knum = 0;
        for(i = 0; i<n; i++)
        {
            scanf("%s",g[i]);
            for(j = 0; j<m; j++)
            {
                if(g[i][j]=='S')
                {
                    sx=i,sy=j;
                }
                if(g[i][j]=='K')
                {
                    kk[i][j]=1<<knum;
                    knum++;
                }
            }
        }
        printf("%d\n",bfs());
    }

    return 0;
}
