#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f
#define N 1000000
#define BUG printf("here!\n")
using namespace std;
struct point
{
    int x,y;
};
struct node
{
    point num[4];
    int d;
};
node q1[N],q2[N];
char vis[8][8][8][8][8][8][8][8];
int map[10][10];
int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};
bool cmp(point lhs,point rhs)
{
    if(lhs.x!=rhs.x)
        return lhs.x<rhs.x;
    else
        return lhs.y<rhs.y;
}
 void make_vis(node start,char word)
{
    vis[start.num[0].x][start.num[0].y][start.num[1].x][start.num[1].y]
    [start.num[2].x][start.num[2].y][start.num[3].x][start.num[3].y]=word;
}
void make_map(node cur)
{
    map[cur.num[0].x][cur.num[0].y]=1;
    map[cur.num[1].x][cur.num[1].y]=1;
    map[cur.num[2].x][cur.num[2].y]=1;
    map[cur.num[3].x][cur.num[3].y]=1;
}
 char visit(node start)
{
    return vis[start.num[0].x][start.num[0].y][start.num[1].x][start.num[1].y]
    [start.num[2].x][start.num[2].y][start.num[3].x][start.num[3].y];
}
 int judge(int x,int y)
{
    if(x<0||x>=8||y<0||y>=8)
        return 0;
    if(map[x][y]==1)
        return 1;
    return 2;
}
int bfs(node start,node end)
{
    memset(vis,0,sizeof(vis));
    int front1=0,tail1=1,front2=0,tail2=1;
    sort(start.num,start.num+4,cmp);
    sort(end.num,end.num+4,cmp);
    make_vis(start,'1');
    make_vis(end,'2');
    q1[0]=start;q2[0]=end;
    q1[0].d=0;q2[0].d=0;
    while(front1<tail1||front2<tail2)
    {
        int tmp=tail1;
        for(;front1<tmp;front1++)
        {
            node cur=q1[front1];
            memset(map,0,sizeof(map));
            make_map(cur);
            int i;
            for(i=0;i<4;i++)
            {

                int j;
                for(j=0;j<4;j++)
                {
                    node next=cur;    //åè¿ä¸ªä¸è½å¨jå¾ªç¯å¤é¢åï¼å ä¸ºä¸é¢æå¯è½æ¹next.dçå¼~~
                    next.num[i].x=cur.num[i].x+xx[j];
                    next.num[i].y=cur.num[i].y+yy[j];
                    if(judge(next.num[i].x,next.num[i].y)==0)
                        continue;
                    if(judge(next.num[i].x,next.num[i].y)==1)
                    {
                        next.num[i].x=next.num[i].x+xx[j];
                        next.num[i].y=next.num[i].y+yy[j];
                        if(judge(next.num[i].x,next.num[i].y)!=2)
                            continue;
                    }
                    sort(next.num,next.num+4,cmp);
                    if(cur.d+1>8)
                        return -1;
                    if(visit(next)=='1')
                        continue;
                    else if(visit(next)=='2')
                    {
                        return next.d+cur.d+1;
                    }
                    make_vis(next,'1');
                    next.d=cur.d+1;

                    q1[tail1++]=next;

                }
            }
        }



        tmp=tail2;
        for(;front2<tmp;front2++)
        {
            node cur=q2[front2];
            memset(map,0,sizeof(map));
            make_map(cur);
            int i;
            for(i=0;i<4;i++)
            {

                int j;
                for(j=0;j<4;j++)
                {
                    node next=cur;
                    next.num[i].x=cur.num[i].x+xx[j];
                    next.num[i].y=cur.num[i].y+yy[j];
                    if(judge(next.num[i].x,next.num[i].y)==0)
                        continue;
                    if(judge(next.num[i].x,next.num[i].y)==1)
                    {
                        next.num[i].x=next.num[i].x+xx[j];
                        next.num[i].y=next.num[i].y+yy[j];
                        if(judge(next.num[i].x,next.num[i].y)!=2)
                            continue;
                    }
                    sort(next.num,next.num+4,cmp);
                    if(cur.d+1>8)
                        return -1;
                    if(visit(next)=='2')
                        continue;
                    else if(visit(next)=='1')
                    {
                        return next.d+cur.d+1;
                    }
                    make_vis(next,'2');
                    next.d=cur.d+1;

                    q2[tail2++]=next;

                }
            }
        }
    }
    return -1;
}

int main()
{
    int x,y;
    node t1,t2;
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        t1.num[0].x=x-1;
        t1.num[0].y=y-1;
        int i;
        for(i=1;i<4;i++)
        {
            scanf("%d%d",&x,&y);
            t1.num[i].x=x-1;
            t1.num[i].y=y-1;
        }
        for(i=0;i<4;i++)
        {
            scanf("%d%d",&x,&y);
            t2.num[i].x=x-1;
            t2.num[i].y=y-1;
        }
        int res=bfs(t1,t2);
        if(res==-1||res>8)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
