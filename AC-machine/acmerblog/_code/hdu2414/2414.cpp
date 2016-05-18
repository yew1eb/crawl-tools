#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;
char m[20][20];
struct point
{
    int x,y;
    int dir;
} p;
char dir[]= {'v','>','^','<'};
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
void dfs(int x,int y)
{
    if(m[x][y]=='.')
    {
        m[x][y]=m[x-dx[p.dir]][y-dy[p.dir]];
        m[x-dx[p.dir]][y-dy[p.dir]]='.';
    }
    else
    {
        dfs(x+dx[p.dir],y+dy[p.dir]);
        m[x][y]=m[x-dx[p.dir]][y-dy[p.dir]];
        m[x-dx[p.dir]][y-dy[p.dir]]='.';
    }
}
bool oor(int x,int y)
{
    if(x<1||x>8) return false;
    if(y<1||y>8) return false;
    return true;
}
void deal()
{
    for(int i=0;i<9;i++)
    m[0][i]=m[i][0]=m[9][i]=m[i][9]='.';
    m[p.x][p.y]='.';
    if(!oor(p.x+dx[p.dir],p.y+dy[p.dir])) return ;
    dfs(p.x+dx[p.dir],p.y+dy[p.dir]);
    p.x=p.x+dx[p.dir];p.y=p.y+dy[p.dir];
}
void out()
{
    m[p.x][p.y] = dir[p.dir];
    for(int i=1;i<9;i++)
    {
        for(int j=1;j<9;j++) printf("%c",m[i][j]);
        printf("\n");
    }
    printf("\n");
}
int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%s",m[1]+1)&&m[1][1]!='-')
    {
        for(int i=2; i<9; i++)
            scanf("%s",m[i]+1);
        for(int i =1; i<9; i++)
        {
            for(int j=1; j<9; j++)
                if(m[i][j]=='v')
                    p.x=i,p.y=j,p.dir=0;
                else if(m[i][j]=='>')
                    p.x=i,p.y=j,p.dir=1;
                else if(m[i][j]=='^')
                    p.x=i,p.y=j,p.dir=2;
                else if(m[i][j]=='<')
                    p.x=i,p.y=j,p.dir=3;
        }
        char op1[10],op2[10];int op3;
        while(scanf("%s",op1)&&op1[0]!='#')
        {
            if(op1[0]=='t')
            {
                scanf("%s",op2);
                if(op2[0]=='l')
                p.dir=(p.dir+1)%4;
                else if(op2[0]=='r')
                p.dir=(p.dir+3)%4;
                else
                p.dir=(p.dir+2)%4;
            }
            else
            {
                scanf("%d",&op3);
                for(int i=0;i<op3;i++)
                deal();
            }
        }
        out();
    }
    return 0;
}