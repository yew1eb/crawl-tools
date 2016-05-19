#include"iostream"
#include"cstdio"
#include"queue"
#include"cstring"
using namespace std;
const int N=55;
const int inf=123456789;

int n,map[N][N],dis[N][N];
__int64 dp[N][N];
int dir[4][2]={1,0, 0,1, -1,0, 0,-1};

struct node1
{
    int x,y,dis;
    bool friend operator<(node1 n1,node1 n2){
        return n2.dis<n1.dis;
    }
};
void bfs1()
{
    int i,flag[N][N];
    node1 now,next;
    priority_queue<node1>q;

    memset(flag,0,sizeof(flag));
    now.x=n-1;
    now.y=n-1;
    now.dis=map[now.x][now.y];
    q.push(now);

    while(!q.empty())
    {
        now=q.top();
        q.pop();
        if(flag[now.x][now.y])    continue;
        flag[now.x][now.y]=1;
        for(i=0;i<4;i++)
        {
            next.x=now.x+dir[i][0];
            next.y=now.y+dir[i][1];
            if(next.x<0 || next.x>=n || next.y<0 || next.y>=n)    continue;
            if(flag[next.x][next.y])    continue;
            if(dis[now.x][now.y]+map[next.x][next.y] >= dis[next.x][next.y])    continue;
            next.dis=dis[next.x][next.y]=dis[now.x][now.y]+map[next.x][next.y];
            q.push(next);
        }
    }
}

struct node2
{
    int x,y,dis;
    bool friend operator<(node2 n1,node2 n2){
        return n1.dis<n2.dis;
    }
};
void bfs2()
{
    int i,flag[N][N];
    node2 now,next;
    priority_queue<node2>q;

    memset(flag,0,sizeof(flag));
    now.x=0;
    now.y=0;
    now.dis=dis[0][0];
    q.push(now);
    flag[0][0]=1;
    while(!q.empty())
    {
        now=q.top();
        q.pop();
        for(i=0;i<4;i++)
        {
            next.x=now.x+dir[i][0];
            next.y=now.y+dir[i][1];
            if(next.x<0 || next.x>=n || next.y<0 || next.y>=n)    continue;
            next.dis=dis[next.x][next.y];
            if(next.dis < now.dis)
            {
                dp[next.x][next.y]+=dp[now.x][now.y];
                if(!flag[next.x][next.y])    {q.push(next);flag[next.x][next.y]=1;}
            }
        }
    }
}

int main()
{
    int i,l;
    while(scanf("%d",&n)!=-1)
    {
        for(i=0;i<n;i++)
        for(l=0;l<n;l++)
        {
            scanf("%d",&map[i][l]);
            dp[i][l]=0;
            dis[i][l]=inf;
        }
        dp[0][0]=1;
        dis[n-1][n-1]=map[n-1][n-1];
        bfs1();
        bfs2();
        printf("%I64d\n",dp[n-1][n-1]);
    }
    return 0;
}