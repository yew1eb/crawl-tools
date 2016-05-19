#include<stdio.h>
#include<queue>
using namespace std;
char map[110][110];
int a[4][2]={1,0,0,1,-1,0,0,-1};
int cont[110][110];//记录到这步剩余的MV
int n,m;
struct op
{
    int x,y;
    int ant;
}cur,next;
int judge(int x,int y)
{
    if(x>=0 && x<n && y>=0 &&y<m &&map[x][y]!='E' &&map[x][y]!='#'&&map[x][y]!='Y')
        return 1;
    return 0;
}
int jdge(int x,int y)
{
    if(x>=0 && x<n &&y>=0 &&y<m &&map[x][y]=='E')
        return 1;
    return 0;
}
void bfs(int s,int d,int k)
{
    queue<op>Q;
    int i,X,Y,xx,yy,j;
    cur.x=s;cur.y=d;cur.ant=k;
    Q.push(cur);
    while(!Q.empty())
    {
        cur=Q.front();
        Q.pop();
        if(cur.ant<=0)continue;
        for(i=0;i<4;i++)
        {
            next.x=X=cur.x+a[i][0];
            next.y=Y=cur.y+a[i][1];
            if(judge(X,Y)==1)
            {
            
                if(map[X][Y]=='.'||map[X][Y]=='P')
                    next.ant=cur.ant-1;
                else if(map[X][Y]=='T')
                    next.ant=cur.ant-2;
                    
                else if(map[X][Y]=='R')
                    next.ant=cur.ant-3;
                if(next.ant>=0)
                {
                    for(j=0;j<4;j++)
                    {
                        xx=next.x+a[j][0];
                        yy=next.y+a[j][1];
                        if(jdge(xx,yy)==1)
                            next.ant=0;    
                    }
                    if(cont[next.x][next.y]<next.ant)//只有next的剩余MV大于原来剩余的MV时才走到这步
                    {
                        cont[next.x][next.y]=next.ant;
                        Q.push(next);
                       if(map[next.x][next.y]!='P')
                           map[next.x][next.y]='*';
                    }
                }
            }
        }
    }
}
int main()
{
    int i,j,t,x,y,k;
    scanf("%d",&t);
    while(t--)
    {
        memset(cont,-1,sizeof(cont));
        scanf("%d%d%d",&n,&m,&k);
        for(i=0;i<n;i++)
        {
            scanf("%s",map[i]);
            for(j=0;j<m;j++)
                if(map[i][j]=='Y')
                {x=i;y=j;}
        }
        cont[x][y]=k;
        bfs(x,y,k);
        for(i=0;i<n;i++)
            puts(map[i]);
        printf("\n");
    }
    return 0;
}