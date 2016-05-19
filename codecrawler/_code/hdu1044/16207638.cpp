#include <iostream>
#include <string.h>
#include <stdio.h>
#include <queue>
using namespace std;
char map[55][55];
int val[60];
int d[60][60];
int step[60][60];
bool vis[60][60];
bool mark[60];
int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};
int w,h,l,m;
int maxx;
int sval;
queue<int> q;
void bfs(int x,int y,int num)
{

    while(!q.empty())q.pop();
    memset(vis,false,sizeof(vis));
    memset(step,0,sizeof(step));
    int s=x*w+y;
    vis[x][y]=true;
    step[x][y]=0;

    q.push(s);
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        y=s%w;
        x=s/w;
        int i;
        for(i=0;i<4;i++)
        {
            int nx=x+xx[i];
            int ny=y+yy[i];
            if(nx<0||nx>=h||ny<0||ny>=w)
                continue;
            if(vis[nx][ny]||map[nx][ny]=='*')
                continue;
            vis[nx][ny]=true;
            step[nx][ny]=step[x][y]+1;
            if(map[nx][ny]=='@')
                d[num][0]=step[nx][ny];
            else if(map[nx][ny]=='<')
                d[num][m+1]=step[nx][ny];
            else if(map[nx][ny]>='A'&&map[nx][ny]<='J')
                d[num][map[nx][ny]-'A'+1]=step[nx][ny];
            q.push(nx*w+ny);
        }

    }
}

void dfs(int now,int v,int time)
{
    if(time>l)
        return ;
    if(maxx==sval)
        return ;
    if(now>m)
    {
        if(v>maxx)
            maxx=v;
        return ;
    }

    int i;
    for(i=0;i<=m+1;i++)
    {
        if(!d[now][i]||mark[i]==true)
            continue;
        mark[i]=true;
        dfs(i,v+val[i],time+d[now][i]);
        mark[i]=false;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    int cas;
    for(cas=1;cas<=t;cas++)
    {
        scanf("%d%d%d%d",&w,&h,&l,&m);
        int i,j;
        memset(d,0,sizeof(d));
        sval=0;
        for(i=1;i<=m;i++)
        {
            scanf("%d",&val[i]);
            sval+=val[i];
        }
        val[0]=val[m+1]=0;
        for(i=0;i<h;i++)
            scanf("%s",map[i]);
        for(i=0;i<h;i++)
        {
            for(j=0;j<w;j++)
            {

                if(map[i][j]=='@')
                    bfs(i,j,0);
                else if(map[i][j]=='<')
                    bfs(i,j,m+1);
                else if(map[i][j]>='A'&&map[i][j]<='J')
                    bfs(i,j,map[i][j]-'A'+1);
            }
        }
        memset(mark,false,sizeof(mark));
        maxx=-1;
        mark[0]=true;
        dfs(0,0,0);
        if(cas!=1)
            printf("\n");
        printf("Case %d:\n",cas);
        if(maxx==-1)
            printf("Impossible\n");
        else
            printf("The best score is %d.\n",maxx);
    }
    return 0;
}
