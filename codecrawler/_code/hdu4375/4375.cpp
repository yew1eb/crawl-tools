#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>

#define N 1010
#define M 1000010

using namespace std;

int sx,sy,ex,ey;
int H,W,n;
int vis[N][N][4];
char str[M];
char st[N];
int map[N][N];
int head[M];
int next[N*N*4];
int x[]={0,1,0,-1};
int y[]={1,0,-1,0};
queue < pair<int,int> > que;

int code(int i,int j,int k){
    return j+i*W+k*H*W;
}
int td[M];
int dir[M][4];
void init(){
    td[0]=3;
    for (int i=0;i<n;i++)
        if (str[i]=='R')
            td[i+1]=(td[i]+1)%4;
        else
            td[i+1]=(td[i]+3)%4;
    int nt[4]={n+1,n+1,n+1,n+1};
    for (int i=n;i>=0;i--){
        copy(nt,nt+4,dir[i]);
        nt[td[i]]=i;
    }
}
void insert(int k,int tx,int ty,int td){
    //printf("%d %d %d %d\n",k,tx,ty,td);
    while (1){
        if (tx<0||ty<0||tx>=H||ty>=W) break;
        if (!map[tx][ty]) break;
        if (vis[tx][ty][td]) break;
        vis[tx][ty][td]=1;
        next[code(tx,ty,td)]=head[k];
        head[k]=code(tx,ty,td);
        tx=tx+x[td];
        ty=ty+y[td];
    }
}
bool bfs(){
    init();
    //for (int i=0;i<4;i++)
    //    printf(" %d",dir[0][i]);
    //printf("\n");
    memset(vis,0,sizeof(vis));
    memset(head,-1,sizeof(head));
    insert(0,sx,sy,3);
    for (int i=0;i<=n;i++)
        for (int j=head[i];j!=-1;j=next[j]){
            int ty=j%W,tx=j/W%H;
            for (int k=0;k<4;k++)
                if (dir[i][k]<=n) insert(dir[i][k],tx,ty,k);
            for (int k=0;k<4;k++)
                if (vis[ex][ey][k]) return 1;
        }
    for (int k=0;k<4;k++)
        if (vis[ex][ey][k]) return 1;
    return 0;
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while (scanf("%d%d%d",&H,&W,&n)==3){
        scanf("%s",str);
        //printf("%d %d %d\n",H,W,n);
        //printf("%s\n",str);
        int i,j;
        memset(map,0,sizeof(map));
        for (i=0;i<H;i++){
            scanf("%s",st);
            for (j=0;j<W;j++)
                if (st[j]=='.') map[i][j]=1;
                else if (st[j]=='S') {sx=i;sy=j;map[i][j]=1;}
                else if (st[j]=='E') {ex=i;ey=j;map[i][j]=1;}
        }
        if (bfs()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}