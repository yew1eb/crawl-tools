#include"stdio.h"
#include"string.h"
#include"queue"
using namespace std;

struct node
{
    int x,y;
    int step;
    friend bool operator<(node n1,node n2)
    {
        return n2.step<n1.step;
    }
};
int dir[4][2]={0,1, 1,0, 0,-1, -1,0};
int map[111][111];
int flag[111][111];
int blood[111][111];
int n,m;

int judge(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m)    return 1;
    if(map[x][y]==-1)                return 1;
    return 0;
}
int BFS()
{
    priority_queue<node>q;
    node cur,next;
    int i;

    cur.x=0;
    cur.y=0;
    cur.step=0;
    map[0][0]=-1;

    q.push(cur);
    while(!q.empty())
    {
        cur=q.top();
        q.pop();
        if(cur.x==n-1 && cur.y==m-1)    return cur.step;
        for(i=0;i<4;i++)
        {
            next.x=cur.x+dir[i][0];
            next.y=cur.y+dir[i][1];

            if(judge(next.x,next.y))    continue;
            next.step=cur.step+1+map[next.x][next.y];
            flag[next.x][next.y]=i+1;
            map[next.x][next.y]=-1;
            q.push(next);
        }
    }
    return -1;
}
int temp;
void P(int x,int y)
{
    int next_x,next_y;
    if(flag[x][y]==0)    return ;
    next_x=x-dir[flag[x][y]-1][0];
    next_y=y-dir[flag[x][y]-1][1];
    P(next_x,next_y);
    printf("%ds:(%d,%d)->(%d,%d)\n",temp++,next_x,next_y,x,y);

    while(blood[x][y]--)    printf("%ds:FIGHT AT (%d,%d)\n",temp++,x,y);
}

int main()
{
    char str[111];
    int i,l;
    int ans;

    while(scanf("%d%d",&n,&m)!=-1)
    {
        memset(map,0,sizeof(map));
        memset(flag,0,sizeof(flag));
        memset(blood,0,sizeof(blood));
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            for(l=0;str[l];l++)
            {
                if(str[l]=='.')        map[i][l]=0;
                else if(str[l]=='X')map[i][l]=-1;
                else                map[i][l]=blood[i][l]=str[l]-'0';
            }
        }

        ans=BFS();
        if(ans==-1)    printf("God please help our poor hero.\n");
        else
        {
            printf("It takes %d seconds to reach the target position, let me show you the way.\n",ans);

            temp=1;
            P(n-1,m-1);
        }
        printf("FINISH\n");
    }
    return 0;
}