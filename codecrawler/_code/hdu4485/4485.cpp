#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct node {
    int x,y,step;
};
int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
node queue[1000000];
node prime[2000];
int visit[50][50],n,m;
node qfront,temp;
int map[50][50],minxx,startx,starty,endx,endy;
int fmin(int a,int b){if(a<b)return a;return b;}
int bfs(int sx,int sy)
{
    int s=0,e=0,x,y,i;

    memset(visit,0,sizeof(visit));
    visit[sx][sy]=1;
    queue[s].x=sx,queue[s].y=sy,queue[s].step=0;
    while(s<=e)
    {
        qfront=queue[s];
        if(queue[s].step>=minxx)
        return minxx;
        for(i=0;i<4;i++)
        {
            temp.x=qfront.x+dir[i][0];
            temp.y=qfront.y+dir[i][1];
            if(map[temp.x][temp.y])
            {
                return qfront.step+1;
            }
            if(!visit[temp.x][temp.y]&&temp.x>=0&&temp.x<n&&temp.y>=0&&temp.y<m)
            {
                temp.step=qfront.step+1;
                queue[e++]=temp;
            }

        }
        s++;
    }
    return -1;
}
int main()
{
    int i,j,hnum;
    char c;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        getchar();
        if(m==0&&n==0)
        break;
        hnum=0;
        for(i=0;i<n;i++)
        {

            for(j=0;j<m;j++)
            {
                c=getchar();
                if(c=='H')
                {
                    map[i][j]=0;
                    prime[hnum].x=i;
                    prime[hnum].y=j;
                    hnum++;
                }
                else if(c=='C')
                {
                    map[i][j]=1;
                }
                else
                {
                    map[i][j]=0;
                }
            }
            getchar();
        }
                    minxx=1000000;
            for(i=0;i<hnum;i++)
            {
                int t=bfs(prime[i].x,prime[i].y);
                if(t<minxx)
                {
                    startx=prime[i].x;
                    starty=prime[i].y;
                    minxx=t;
                    endx=temp.x;
                    endy=temp.y;
                }

            }
            printf("%d %d %d %d\n",startx,starty,endx,endy);


    }
    return 0;
}
