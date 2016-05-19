#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

#define N 105
#define T 1005

int n,m,k,d;
int vx[]={0,0,0,1,-1};
int vy[]={0,1,-1,0,0};//CEWSN
bool vis[N][N][T];
bool g[N][N][T];

struct node{
    int x,y,s;
    node(int xx,int yy,int ss):x(xx),y(yy),s(ss){}
};

struct guard{
    int r,t,v,x,y;
    guard(){}
    guard(int rr,int tt,int vv,int xx,int yy):r(rr),t(tt),v(vv),x(xx),y(yy){}
};

bool check(int x,int y){
    if (x<0 || x>n || y<0 || y>m)
        return false;
    return true;
}

guard man[N];
void update(guard u){
    int r,t,v,x,y;
    r=u.r; t=u.t; v=u.v;
    x=u.x; y=u.y;

    int num=1;
    while (1){
        int tx=x+vx[r]*v*num;
        int ty=y+vy[r]*v*num;
        if (!check(tx,ty)) break;
        if (g[tx][ty][0]) break;

        int flag=0;
        int xx=x+vx[r],yy=y+vy[r];
        while (xx!=tx || yy!=ty){
            if (g[xx][yy][0]){
                flag=1;
                break;
            }
            xx+=vx[r];
            yy+=vy[r];
        }

        if (flag) break;

        int s=num;
        while (s<=d){
            g[tx][ty][s]=1;
            s+=t;
        }

        num++;
    }
}

void bfs(){
    memset(vis,0,sizeof(vis));
    queue<node> q;
    q.push(node(0,0,0));
    vis[0][0][0]=1;

    while (!q.empty()){
        node cur=q.front();
        q.pop();
        int x=cur.x,y=cur.y,s=cur.s;

        if (x==n && y==m){
            printf("%d\n",s);
            return;
        }

        if (s==d)
            continue;

        for (int i=0;i<5;i++){
            int tx=x+vx[i];
            int ty=y+vy[i];
            int ts=s+1;

            if (!check(tx,ty)) continue;
            if (g[tx][ty][0]) continue;
            if (g[tx][ty][ts]) continue;
            if (vis[tx][ty][ts]) continue;

            vis[tx][ty][ts]=1;
            q.push(node(tx,ty,ts));
        }
    }
    printf("Bad luck!\n");
}


int main(){
    while (~scanf("%d%d%d%d",&n,&m,&k,&d)){
        memset(g,0,sizeof(g));
        for (int i=0;i<k;i++){
            char st[2];
            scanf("%s",st);
            int r,t,v,x,y;
            scanf("%d%d%d%d",&t,&v,&x,&y);
            if (st[0]=='E')
                r=1;
            if (st[0]=='W')
                r=2;
            if (st[0]=='S')
                r=3;
            if (st[0]=='N')
                r=4;
            man[i]=guard(r,t,v,x,y);
            g[x][y][0]=1;
        }

        for (int i=0;i<k;i++)
            update(man[i]);

        bfs();
    }
    return 0;
}
