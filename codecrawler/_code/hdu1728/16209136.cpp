#include"stdio.h"
#include"string.h"
#include"queue"
using namespace std;


struct node
{
    int x,y;
    int ts;
};
int map[111][111];
int n,m;
int x_s,y_s;
int x_e,y_e;
int limit;
int dir[4][2]={1,0, -1,0, 0,1, 0,-1};


int judge(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m)    return -1;
    return map[x][y];
}
int BFS()
{
    queue<node>q;
    node cur,next;
    int i;
    int temp;


    cur.x=x_s;
    cur.y=y_s;
    cur.ts=-1;
    map[cur.x][cur.y]=-1;
    q.push(cur);


    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        if(cur.ts>limit)                return -1;
        if(cur.x==x_e && cur.y==y_e)    return 1;
        for(i=0;i<4;i++)
        {
            next.x=cur.x+dir[i][0];
            next.y=cur.y+dir[i][1];
            temp=judge(next.x,next.y);
            while(temp!=-1)
            {
                if(temp==0)
                {
                    next.ts=map[next.x][next.y]=cur.ts+1;
                    q.push(next);
                }
                next.x+=dir[i][0];
                next.y+=dir[i][1];
                temp=judge(next.x,next.y);
            }
        }
    }
    return -1;
}


int main()
{
    int T;
    char str[111];
    int i,l;
    int ans;


    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            for(l=0;str[l];l++)
            {
                if(str[l]=='.')        map[i][l]=0;
                else if(str[l]=='*')map[i][l]=-1;
            }
        }
        scanf("%d%d%d%d%d",&limit,&y_s,&x_s,&y_e,&x_e);
        x_s--;y_s--;
        x_e--;y_e--;


        ans=BFS();
        if(ans==-1)    printf("no\n");
        else        printf("yes\n");
    }
    return 0;
}