#include"stdio.h"
#include"string.h"
#include"queue"
using namespace std;
struct node
{
    int x,y,z;
    int step;
};
int map[12][12][12];
int dir[6][3]={1,0,0, -1,0,0, 0,1,0, 0,-1,0, 0,0,1, 0,0,-1};
int n;
int x_s,y_s,z_s,x_e,y_e,z_e;


int judge(int x,int y,int z)
{
    if(x<0 || x>=n || y<0 || y>=n || z<0 || z>=n)    return 1;
    if(map[x][y][z])    return 1;
    return 0;
}


int BFS()
{
    queue<node>q;
    node cur,next;
    int i;


    cur.x=x_s;
    cur.y=y_s;
    cur.z=z_s;
    cur.step=0;
    map[cur.x][cur.y][cur.z]=1;


    q.push(cur);
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        if(cur.x==x_e && cur.y==y_e && cur.z==z_e)    return cur.step;
        for(i=0;i<6;i++)
        {
            next.x=cur.x+dir[i][0];
            next.y=cur.y+dir[i][1];
            next.z=cur.z+dir[i][2];


            if(judge(next.x,next.y,next.z))    continue;
            next.step=cur.step+1;
            map[next.x][next.y][next.z]=1;
            q.push(next);
        }
    }
    return -1;
}


int main()
{
    char str[15];
    int i,l,j;
    int ans;


    while(scanf("%s",str)!=-1)
    {
        scanf("%d",&n);
        memset(map,0,sizeof(map));


        for(i=0;i<n;i++)
        {
            for(l=0;l<n;l++)
            {
                scanf("%s",str);
                for(j=0;str[j];j++)
                {
                    if(str[j]=='O')    map[i][l][j]=0;
                    else            map[i][l][j]=1;
                }
            }
        }
        scanf("%d%d%d",&z_s,&y_s,&x_s);
        scanf("%d%d%d",&z_e,&y_e,&x_e);
        scanf("%s",str);


        ans=BFS();
        if(ans==-1)    printf("NO ROUTE\n");
        else        printf("%d %d\n",n,ans);
    }
    return 0;
}