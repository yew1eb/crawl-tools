#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;
#define N 200
typedef __int64 LL;

int n,m,t;
char maps[N][N];
LL dp[22][N][N];
int dist[4][2] = {0,1,0,-1,1,0,-1,0};
struct P
{
       int x,y;
};
P start;
P ens;

bool is(int x,int y)
{
     if(x<0||y<0||x>=n||y>=m)
     return false;
     return true;
 }
void solve()
{
     memset(dp,0,sizeof(dp));
     dp[0][start.x][start.y]= 1;
     
     for(int i=1;i<=t;i++)
     {
             for(int j=0;j<n;j++)
             for(int k =0;k<m;k++)
             {     dp[i][j][k] += dp[i-1][j][k];
                    if(maps[j][k] != 'X' ||maps[j][k]== 0)
                     for(int x=0;x<4;x++)
                     {     
                             int xx,y;
                             xx = j+dist[x][0];
                             y = k+dist[x][1];
                             if(is(xx,y))
                             dp[i][j][k] += dp[i-1][xx][y];
                     }
             }
     }
    LL as =  dp[t-1][ens.x][ens.y];
    LL ab = dp[t][ens.x][ens.y];
    if(as>0) printf("%I64d\n",as);
    else if(ab>0) puts("Oh, my god, bad luck!");
    else puts("God will bless XX and WisKey!");
 }
void init()
{
     while(scanf("%d%d%d",&n,&m,&t)!=EOF)
     {
         for(int i=0;i<n;i++)
           scanf("%s",maps[i]);
         
         for(int i=0;i<n;i++)
         for(int j = 0;j<m;j++)
         if(maps[i][j] == 'S') start.x = i,start.y = j;
         else if(maps[i][j] == 'E') ens.x = i,ens.y = j;
         solve();
         
     }
 }
int main()
{
    init();
    return 0;
    }