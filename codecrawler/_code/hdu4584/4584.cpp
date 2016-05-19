#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

char str[44][44];
int vis[44][44],dist[44][44];
int dir[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
int qx[20000],qy[20000];
int m,n;

int solve(int r,int c,int &resr,int &resc)
{
    int i=r;int j=c;
    memset(vis,0,sizeof(vis));
    memset(dist,127,sizeof(dist));
    int head=0;int rear=0;
    qx[rear]=i;qy[rear++]=j;
    vis[i][j]=1;dist[i][j]=0;
    while(head<rear)
    {
        int ux=qx[head];
        int uy=qy[head++];
        for(int k=0;k<4;++k)
        {
            int nx=ux+dir[k][0];
            int ny=uy+dir[k][1];
            if(nx>=0&&nx<m&&ny>=0&&ny<n&&!vis[nx][ny])
            {
                dist[nx][ny]=dist[ux][uy]+1;
                vis[nx][ny]=1;
                qx[rear]=nx;qy[rear++]=ny;
                /*if(str[nx][ny]=='C')
                {
                    resr=nx;resc=ny;
                    return dist[nx][ny];
                }*/
            }
        }
    }
    int ans=100000;
    for(int i=0;i<m;++i)
        for(int j=0;j<n;++j)
            if(str[i][j]=='C'&&ans>dist[i][j])
        {
            ans=dist[i][j];
            resr=i;resc=j;
        }
    return ans;
}
int main ()
{
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if(m==0&&n==0) break;
        for(int i=0;i<m;++i)
            scanf("%s",str[i]);
        int ans=50*50;
        int x1,y1,x2,y2,tx,ty;
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
            if(str[i][j]=='H')
        {
            int res=solve(i,j,tx,ty);
            if(ans>res)
            {
                ans=res;
                x1=i;y1=j;
                x2=tx;y2=ty;
            }
        }
        printf("%d %d %d %d\n",x1,y1,x2,y2);
    }
    return 0;
}


