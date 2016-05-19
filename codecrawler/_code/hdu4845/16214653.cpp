#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

int map[20][20];
int f[20][20][20][20];
int d[20][20];
int mark[20][20][4100];
int n,m,P,k;
int p[15];
int xx[5]={1,-1,0,0};
int yy[5]={0,0,1,-1};

struct pp
{
    int x,y;
    int a;
    int s;
    pp()
    {
        a=0;
    }
};

queue <pp> myqueue;

int min(int a,int b)
{
    return a>b?b:a;
}

void short_path()
{
    while (!myqueue.empty())
    {
        pp cur=myqueue.front();
        myqueue.pop();
        int x=cur.x;
        int y=cur.y;
        //cout<<x<<" "<<y<<" "<<cur.s<<" "<<cur.a<<endl;
        for (int i=0;i<=3;i++)
        {
            int x1=x+xx[i];
            int y1=y+yy[i];
            int a=(cur.a|map[x1][y1]);
            if (x1>n||y1>m||x1<1||y1<1)
                continue ;
            int t=f[x][y][x1][y1];
            if (t==0)
                continue ;
            if (t>0)
            {
                if ((cur.a&p[t])==0)
                {
                    continue ;
                }
            }
            pp next;
            next.x=x1;
            next.y=y1;
            next.a=a;
            next.s=cur.s+1;
            d[x1][y1]=min(d[x1][y1],next.s);
            if (mark[next.x][next.y][next.a]>next.s||mark[next.x][next.y][next.a]==-1)
            {
                myqueue.push(next);
                mark[next.x][next.y][next.a]=next.s;
            }
        }
    }
}

int main()
{
    for (int i=1;i<=10;i++)
        p[i]=(1<<i);
    while (cin>>n>>m>>P>>k)
    {
        memset(f,-1,sizeof(f));
        memset(map,0,sizeof(map));
        memset(mark,-1,sizeof(mark));
        for (int i=1;i<20;i++)
            for (int t=1;t<20;t++)
                d[i][t]=99999999;
        for (int i=1;i<=k;i++)
        {
            int x1,y1,x2,y2,z;
            cin>>x1>>y1>>x2>>y2>>z;
            f[x1][y1][x2][y2]=f[x2][y2][x1][y1]=z;
        }
        int s;
        cin>>s;
        while (s--)
        {
            int a,b,c;
            cin>>a>>b>>c;
            map[a][b]|=p[c];
        }
        pp cur;
        cur.x=1;
        cur.y=1;
        cur.s=0;
        d[1][1]=0;
        myqueue.push(cur);
        short_path();
        if (d[n][m]!=99999999)
            cout<<d[n][m]<<endl;
        else
            cout<<-1<<endl;
    }
}