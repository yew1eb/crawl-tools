#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int path[88][88], vis[88][88], p, q, cnt;
bool flag;

int dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dy[8] = {-2, -2, -1, -1, 1, 1, 2, 2};

bool judge(int x, int y)
{
    if(x >= 1 && x <= p && y >= 1 && y <= q && !vis[x][y] && !flag)
        return true;
    return false;
}

void DFS(int r, int c, int step)
{
    path[step][0] = r;
    path[step][1] = c;
    if(step == p * q)
    {
        flag = true;
        return ;
    }
    for(int i = 0; i < 8; i++)
    {
        int nx = r + dx[i];
        int ny = c + dy[i];
        if(judge(nx,ny))
        {

            vis[nx][ny] = 1;
            DFS(nx,ny,step+1);
            vis[nx][ny] = 0;
        }
    }
}

int main()
{
    int i, j, n, cas = 0;
    scanf("%d",&n);
    while(n--)
    {
        flag = 0;
        scanf("%d%d",&p,&q);
        memset(vis,0,sizeof(vis));
        vis[1][1] = 1;
        DFS(1,1,1);
        printf("Scenario #%d:\n",++cas);
        if(flag)
        {
            for(i = 1; i <= p * q; i++)
                printf("%c%d",path[i][1] - 1 + 'A',path[i][0]);
        }
        else
            printf("impossible");
        printf("\n");
        if(n != 0)
            printf("\n");
    }
    return 0;
}