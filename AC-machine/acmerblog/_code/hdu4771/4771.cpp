#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <math.h>
using namespace std;
int n,m,k;
struct node
{
    int x,y;
    int step;
    bool operator<(const node &t)const
    {
        return t.step<step;
    }
}num[5];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
char map[105][105];
bool Vis[10];
int dist[10][10];
bool judge(node &a,bool vis[][105])
{
    if(a.x>=0 && a.x<n && a.y>=0 && a.y<m && !vis[a.x][a.y] && map[a.x][a.y]=='.')
    {
        return true;
    }
    return false;
}

int bfs(node s,node e)
{
    bool vis[105][105];
    memset(vis, false, sizeof(vis));
    priority_queue<node>q;
    q.push(s);
    vis[s.x][s.y]=true;
    while (!q.empty())
    {
        node h=q.top();
        node temp;
        q.pop();
        if(h.x==e.x && h.y==e.y)
        {
            return h.step;
        }
        for (int i=0; i<4; i++)
        {
            temp.x=h.x+dir[i][0];
            temp.y=h.y+dir[i][1];
            temp.step=h.step+1;
            if(judge(temp,vis))
            {
                vis[temp.x][temp.y]=true;
                q.push(temp);
            }
        }
    }
    
    return -1;
}
int dfs(int u,int cnt)
{
    if(cnt==k)
    {
        return 0;
    }
    int ans=1000000;
    for (int v=1; v<=k; v++)
    {
        if(dist[u][v]==-1 || Vis[v])
        {
            continue;
        }
        Vis[v]=true;
        ans=min(ans,dfs(v, cnt+1)+dist[u][v]);
        Vis[v]=false;
    }
    return ans;
}
int main()
{
    while (scanf("%d%d",&n,&m) && (n||m))
    {
        for (int i=0; i<n; i++)
        {
            scanf("%s",map[i]);
            for (int j=0; j<m; j++)
            {
                if(map[i][j]=='@')
                {
                    num[0].x=i;
                    num[0].y=j;
                    num[0].step=0;
                    break;
                }
            }
        }
        scanf("%d",&k);
        for (int i=1; i<=k; i++)
        {
            scanf("%d%d",&num[i].x,&num[i].y);
            num[i].x--;
            num[i].y--;
            num[i].step=0;
            
        }
        memset(dist, -1, sizeof(dist));
        bool flag=false;
        // bfs 求权值 并建图
        for (int i=1; i<=k; i++)
        {
            dist[0][i]=bfs(num[0], num[i]);
            if(flag)
            {
                flag=true;
                break;
            }
            for (int j=i+1; j<=k; j++)
            {
                dist[i][j]=dist[j][i]=bfs(num[i], num[j]);
                // 除出发点外 如果存在两个点无法到达则无法求出
                if(dist[i][j]==-1)
                {
                    flag=true;
                    break;
                }
            }
        }
        
        //如果出发点与所有坐标都不通也是不行的
        for (int i=1; i<=k; i++)
        {
            if(dist[0][i]!=-1 || flag)
            {
                break;
            }
            if(i==k)
            {
                flag=true;
            }
        }
        if(flag)
        {
            printf("-1\n");
        }
        else
        {
            memset(Vis, false, sizeof(Vis));
            printf("%d\n",dfs(0, 0));
        }
    }
    return 0;
}