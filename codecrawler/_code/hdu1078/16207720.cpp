#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

#define N 105
#define CLR(a,v) memset(a,v,sizeof(a))

int map[N][N],dp[N][N];
int dir[]={1,0,0,1,-1,0,0,-1};
int n,k;
int Dfs(int x,int y)
{
    if(dp[x][y]+1)
        return dp[x][y];
    int _x,_y,mmax = 0;         //ä¸è¦æè¿éçåéå£°ææå¨å±åé
    for(int t=1;t<=k;t++)
    {
        for(int i=0;i<8;)
        {
            _x = x + t*dir[i++];
            _y = y + t*dir[i++];
            if(!(_x<1 || _y<1 || _x>n || _y>n) && map[_x][_y] > map[x][y])
                mmax = max(mmax,Dfs(_x,_y));
        }
    }
    return dp[x][y] = map[x][y]+mmax;
}
int main()
{
    while(scanf("%d%d",&n,&k),n+1)
    {
        CLR(dp,-1);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&map[i][j]);
        printf("%d\n",Dfs(1,1));
    }
    return 0;
}
