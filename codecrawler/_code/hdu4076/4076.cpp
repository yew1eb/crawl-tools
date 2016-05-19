/*
hdu 4076 Haunted Graveyard - spfa(负权回路)
题意：有n*m个点，每一点可以向四个方向走，有些点是墓地不能走，有些点是山洞，当你走到该点时会传送到另外一点，所花费的时间有可能是个正数也可能是个负数
也可能是0。起点是（0,0），目的地是（n-1,m-1），题目保证起点和终点不会是墓地也不会是山洞。如果有可能永远都到达不了终点也就是该图存在负权回路，输出Never;
否则输出需最少的花费时间或者Impossible;
思路：存在负权，显然要用spfa。当对某一个点的松弛次数超时该图的顶点数n*m时就表示存在负权回路。
但是有一点需要注意：判断负权回路的时候不能把终点算在内，因为当第一次走到终点的时候就走出去了，终点不会对他的后继点进行松弛。
*/
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define inf 0xfffffff
const int N=35;
int map[N][N],xx[N][N],yy[N][N],tt[N][N],dist[N][N],vis[N][N],cnt[N][N];
int dir[4][2]= { {0,1},{0,-1},{1,0},{-1,0} };
int W,H,flag;
struct node
{
    int x,y;
};
void spfa()
{
    int i,j,ans;
    for(i=0; i<W; ++i)
    {
        for(j=0; j<H; ++j)
        {
            dist[i][j]=inf;
        }
    }
    dist[0][0]=0;
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    queue<node> q;
    node cur,next;
    cur.x=0;
    cur.y=0;
    next.x=next.y=0;
    q.push(cur);
    vis[0][0]=1;
    cnt[0][0]++;
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        vis[cur.x][cur.y]=0;//是否在队列内
        if(cnt[cur.x][cur.y]>W*H)
        {
            flag=1;
            return;
        }
        if(cur.x==W-1&&cur.y==H-1)continue;
        if(xx[cur.x][cur.y]!=-1)
        {
            next.x=xx[cur.x][cur.y];
            next.y=yy[cur.x][cur.y];
            ans=dist[cur.x][cur.y]+tt[cur.x][cur.y];
            if(dist[next.x][next.y]>ans)
            {
                dist[next.x][next.y]=ans;
                if(vis[next.x][next.y]==0)
                {
                    vis[next.x][next.y]=1;
                    cnt[next.x][next.y]++;
                    q.push(next);
                }
            }
            continue;
        }

        for(i=0; i<4; ++i)
        {
            next.x=cur.x+dir[i][0];
            next.y=cur.y+dir[i][1];
            ans=dist[cur.x][cur.y]+1;
            if(next.x<0 || next.y<0 || next.x>=W || next.y>=H || map[next.x][next.y]==1) continue;
            if(dist[next.x][next.y]>ans)
            {
                dist[next.x][next.y]=ans;
                if(vis[next.x][next.y]==0)
                {
                    vis[next.x][next.y]=1;
                    cnt[next.x][next.y]++;
                    q.push(next);
                }
            }
        }
    }
}
int main()
{
    int numofmu,numofdong,i,tempa,tempb;
    while(cin>>W>>H,W+H)
    {
        flag=0;
        memset(map,0,sizeof(map));
        memset(xx,-1,sizeof(xx));
        cin>>numofmu;
        for(i=1; i<=numofmu; ++i)
        {
            cin>>tempa>>tempb;
            map[tempa][tempb]=1;
        }
        cin>>numofdong;
        for(i=1; i<=numofdong; ++i)
        {
            cin>>tempa>>tempb;
            cin>>xx[tempa][tempb]>>yy[tempa][tempb]>>tt[tempa][tempb];
        }
        spfa();
        if(flag==1) cout<<"Never"<<endl;
        else if(dist[W-1][H-1]==inf) cout<<"Impossible"<<endl;
        else cout<<dist[W-1][H-1]<<endl;
    }
    return 0;
}
