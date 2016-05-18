#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int M =1010;
int map[M][M];
int vis[M][M];
int dir[8][2]={-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1,-1,-1};
int r,c;
int sx,sy,ex,ey;
struct node{
    int x,y,ti;
    bool  operator < (const node &a) const
    {
        return a.ti<ti;
    };
};
bool is_ok(node a)
{
    if(a.ti >= vis[a.x][a.y]||a.x<1||a.x>r||a.y<1||a.y>c)
        return false;
    return true;
}
void bfs()
{
    priority_queue<node> Q;
    memset(vis,127,sizeof(vis));
    node s;s.x=sx;s.y=sy;
    s.ti=0;
    vis[sx][sy]=0;
    Q.push(s);
    while(!Q.empty())
    {
        node h=Q.top();
        Q.pop();
        if(h.x==ex&&h.y==ey) return ;
        for(int i=0;i<8;i++)
        {
            node t;
            t.x=h.x+dir[i][0];
            t.y=h.y+dir[i][1];
            t.ti=h.ti;
            if(map[h.x][h.y]!=i)
                t.ti+=1;
            if(is_ok(t))
            {
                vis[t.x][t.y]=t.ti;
                Q.push(t);
            }
        }
    }
}
int main()
{
    int m;
    while(scanf("%d%d",&r,&c)!=EOF)
    {
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                scanf("%1d",&map[i][j]);
            scanf("%d",&m);
            while(m--)
            {
                scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
                if(sx==ex&&sy==ey) 
                {
                    printf("0\n");
                    continue;
                }
                bfs();
                printf("%d\n",vis[ex][ey]);
            }
    }
    return 0;
}