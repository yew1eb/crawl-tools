#include"stdio.h"
#include"string.h"
#include"queue"
using namespace std;


int stair[22][22];


struct node
{
    int x,y;
    int step;
    friend bool operator<(node n1,node n2)
    {
        return n2.step<n1.step;
    }
};
int map[22][22];
int n,m;
int dir[4][2]={1,0, 0,-1, -1,0, 0,1};
int x_s,y_s;
int x_e,y_e;


int judge(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m)    return 1;
    if(map[x][y]==1)                return 1;
    if(map[x][y]==2)    return 2;
    return 0;
}
int judge2(int step,int x2,int y2,int k)
{
    if((step+stair[x2][y2])%2!=0 && (k==0 || k==2))    return 1;
    if((step+stair[x2][y2])%2==0 && (k==1 || k==3))    return 1;
    return 0;
}
int BFS()
{
    priority_queue<node>q;
    node cur,next;
    int i;
    int temp;
    int t_x,t_y;


    cur.x=x_s;
    cur.y=y_s;
    cur.step=0;
    map[cur.x][cur.y]=1;


    q.push(cur);
    while(!q.empty())
    {
        cur=q.top();
        q.pop();
        if(cur.x==x_e && cur.y==y_e)    return cur.step;
        for(i=0;i<4;i++)
        {
            next.x=cur.x+dir[i][0];
            next.y=cur.y+dir[i][1];


            temp=judge(next.x,next.y);
            if(temp==1)    continue;
            if(!temp)
            {
                next.step=cur.step+1;
                map[next.x][next.y]=1;
                q.push(next);
            }
            else
            {
                t_x=next.x+dir[i][0];
                t_y=next.y+dir[i][1];
                if(judge(t_x,t_y)==1)    continue;

                if(judge2(cur.step,next.x,next.y,i))
                {
                    next.x=t_x;
                    next.y=t_y;
                    next.step=cur.step+1;
                }
                else
                {
                    next.x=t_x;
                    next.y=t_y;
                    next.step=cur.step+2;
                }
                q.push(next);
            }
        }
    }
    return -1;
}


int main()
{
    int i,l;
    int ans;
    char str[25];


    while(scanf("%d%d",&n,&m)!=-1)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            for(l=0;str[l];l++)
            {
                if(str[l]=='S')        {x_s=i;y_s=l;map[i][l]=0;}
                else if(str[l]=='T'){x_e=i;y_e=l;map[i][l]=0;}
                else if(str[l]=='|'){stair[i][l]=1;map[i][l]=2;}
                else if(str[l]=='-'){stair[i][l]=0;map[i][l]=2;}
                else if(str[l]=='*')map[i][l]=1;
                else if(str[l]=='.')map[i][l]=0;
            }
        }


        ans=BFS();
        printf("%d\n",ans);
    }
    return 0;
}