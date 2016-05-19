#include "stdio.h"
#include "string.h"
#include "queue"
using namespace std;

int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int s_x,s_y,n,m,t;
char str[11][11];

struct node
{
    int x,y,step,key;
};
int bfs()
{
    queue<node>q;
    node cur,next;
    int i;
    int hash[11][11][2];

    cur.x=s_x;
    cur.y=s_y;
    cur.step=0;
    cur.key=0;
    q.push(cur);
    memset(hash,0,sizeof(hash));
    hash[s_x][s_y][0]=1;

    while (!q.empty())
    {
        cur=q.front();
        q.pop();
        if (cur.step>=t) return -1;

        for (i=0;i<4;i++)
        {
            next.x=cur.x+dir[i][0];
            next.y=cur.y+dir[i][1];
            if (next.x<0 || next.y<0 || next.x>=n || next.y>=m) continue;
            if (str[next.x][next.y]=='#') continue;
            next.step=cur.step+1;
            next.key=cur.key;
            if (str[next.x][next.y]=='J')
                next.key=1;
            if (hash[next.x][next.y][next.key]==1) continue;
            hash[next.x][next.y][next.key]=1;
            q.push(next);
            if (str[next.x][next.y]=='E' && next.key==1) return 1;
        }
    }
    return -1;
}


int dfs(int k)
{
    int i,j;
    char ch;
    if (k==0)
        return bfs();

    for (i=0;i<n;i++)
        for (j=0;j<m;j++)
        if (str[i][j]=='J' || str[i][j]=='.')
        {
            ch=str[i][j];
            str[i][j]='#';
            if (dfs(k-1)==-1)
                return -1;
            str[i][j]=ch;
        }
    return 1;
}
int main()
{
    int Case,i,j;
    scanf("%d",&Case);
    while (Case--)
    {
        scanf("%d%d%d",&n,&m,&t);
        for (i=0; i<n; i++)
        {
            scanf("%s",str[i]);
            for (j=0; j<m; j++)
                if(str[i][j]=='S')
                {
                    s_x=i;
                    s_y=j;
                    break;
                }
        }

        if (bfs()==-1)
        {
            printf("0\n");
            continue;
        }

        if (dfs(1)==-1)
            printf("1\n");
        else
            if (dfs(2)==-1)
            printf("2\n");
        else
            if (dfs(3)==-1)
            printf("3\n");
        else
            printf("4\n");
    }
    return 0;
}
