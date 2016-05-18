#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 33;
const int INF = 9999999;

int dp[MAXN][MAXN][MAXN][MAXN];
int maze[MAXN][MAXN];
int N;
int dir[4][4] = {1,0,1,0,1,0,0,1,0,1,1,0,0,1,0,1};

int dfs(int x1,int y1,int x2,int y2)
{
      if (maze[x1][y1] == -1 || maze[x2][y2] == -1)return 0;
      if (x1 + y1 == N + N)return maze[N][N];
      if (dp[x1][y1][x2][y2] != -1)return dp[x1][y1][x2][y2];
      if (x1 == x2 && y1 == y2 && x1 + y1 > 2)return 0;
      int ans = 0;
      for (int i = 0;i < 4;i++)
      {
            int a = x1 + dir[i][0];
            int b = y1 + dir[i][1];
            int c = x2 + dir[i][2];
            int d = y2 + dir[i][3];
            int temp = dfs(a,b,c,d);
            ans = max(ans,temp);
      }
      return dp[x1][y1][x2][y2] = ans + maze[x1][y1] + maze[x2][y2];
}


int solve()
{
      memset(dp,-1,sizeof(dp));
      return dfs(1,1,1,1) - maze[1][1];
}

int main()
{
      while (scanf("%d",&N) != EOF)
      {
            memset(maze,-1,sizeof(maze));
            for (int i = 1;i <= N;i++)
                  for (int j = 1;j <= N;j++)
                  scanf("%d",&maze[i][j]);
            printf("%d\n",solve());
      }
      return 0;
}