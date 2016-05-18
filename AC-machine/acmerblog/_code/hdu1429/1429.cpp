#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int n,m,time,visited[25][25][1025];
int sx,sy,ex,ey,res;
int b[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char map[25][25];

struct node{
    int x;
    int y;
    int t;
    int st;
};

int check(int x,int y)
{
    if(x>=1&&x<=n&&y>=1&&y<=m&&map[x][y]!='*')
     return 1;
    else
     return 0;
}

void bfs()
{
    queue<node>Q;
    struct node p,temp;
    int i,j,add;
    memset(visited,0,sizeof(visited));
    p.x=sx;p.y=sy;
    p.t=0;p.st=0;
    visited[sx][sy][0]=1;
    Q.push(p);
    while(!Q.empty())
    {
        p=Q.front();
        Q.pop();
        if(p.x==ex&&p.y==ey&&p.t<time)//这里要注意下，为此贡献了一次wa
        {
            res=p.t;
            return ;
        }
        if(p.t>=time)
         return ;
        for(i=0;i<4;i++)
        {
            temp.x=p.x+b[i][0];
            temp.y=p.y+b[i][1];
            temp.t=p.t+1;
            temp.st=p.st;
            if(check(temp.x,temp.y))
            {
                if(map[temp.x][temp.y]>='a'&&map[temp.x][temp.y]<='j')
                {
                    add=1<<(map[temp.x][temp.y]-'a');
                    temp.st=temp.st|add;
                    if(visited[temp.x][temp.y][temp.st]==0)
                    {
                        visited[temp.x][temp.y][temp.st]=1;
                        Q.push(temp);
                    }
                }
                else if(map[temp.x][temp.y]>='A'&&map[temp.x][temp.y]<='J')
                {
                    add=1<<(map[temp.x][temp.y]-'A');
                    if((temp.st&add)&&visited[temp.x][temp.y][temp.st]==0)
                    {
                        visited[temp.x][temp.y][temp.st]=1;
                        Q.push(temp);
                    }
                }
                else if(visited[temp.x][temp.y][temp.st]==0)
                {
                    visited[temp.x][temp.y][temp.st]=1;
                    Q.push(temp);
                }
            }
        }
    }
}

int main()
{
    int i,j;
    while(scanf("%d%d%d",&n,&m,&time)!=EOF)
    {
        res=-1;
        for(i=1;i<=n;i++)
        {
            getchar();
            for(j=1;j<=m;j++)
            {
                scanf("%c",&map[i][j]);
                if(map[i][j]=='@')
                {
                    sx=i;
                    sy=j;
                }
                else if(map[i][j]=='^')
                {
                    ex=i;
                    ey=j;
                }
            }
        }
        bfs();
        printf("%d\n",res);
    }
    return 0;
}