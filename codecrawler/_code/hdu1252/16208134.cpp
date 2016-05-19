#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
/*
easy bfs
*/
struct node
{
    int x[3];
}p;
int maze[55][55],m,vis[55][55][55];
void set(node t,node tt)
{
    vis[t.x[0]][t.x[1]][t.x[2]]=1+vis[tt.x[0]][tt.x[1]][tt.x[2]];
}
int test(node t)
{
    return vis[t.x[0]][t.x[1]][t.x[2]];
}
bool ok(node t)
{
    return t.x[0]==t.x[1]&&t.x[1]==t.x[2];
}
int bfs()
{
    memset(vis,0,sizeof(vis));
    node t;
    queue<node> que;
    if(ok(p))
        return 0;
    que.push(p);
    int i;
    vis[p.x[0]][p.x[1]][p.x[2]]=1;
    char c;
    while(!que.empty())
    {
        p=que.front();
        que.pop();


        c=maze[p.x[2]][p.x[1]];
        for(i=1;i<=m;++i)
        {
            if(maze[p.x[0]][i]==c&&i!=p.x[0])
            {
                t=p;
                t.x[0]=i;
                if(ok(t))
                    return test(p);
                if(!test(t))
                {
                    set(t,p);
                    que.push(t);
                }
            }
        }

        c=maze[p.x[0]][p.x[2]];
        for(i=1;i<=m;++i)
        {
            if(maze[p.x[1]][i]==c&&i!=p.x[1])
            {
                t=p;
                t.x[1]=i;
                if(ok(t))
                    return test(p);
                if(!test(t))
                {
                    set(t,p);
                    que.push(t);
                }
            }
        }

        c=maze[p.x[0]][p.x[1]];
        for(i=1;i<=m;++i)
        {
            if(maze[p.x[2]][i]==c&&i!=p.x[2])
            {
                t=p;
                t.x[2]=i;
                if(ok(t))
                    return test(p);
                if(!test(t))
                {
                    set(t,p);
                    que.push(t);
                }
            }
        }
    }
    return -1;
}
int main()
{
    while(scanf("%d",&m)==1&&m>0)
    {
        int i,j;
        char s[3];
        for(i=0;i<3;++i)
            scanf("%d",&p.x[i]);
        getchar();
        for(i=1;i<=m;++i)
            for(j=1;j<=m;++j)
            {
                scanf("%s",s);/*ç©éµæå­ç¬¦è¾å¥çæ¹æ³ï¼é¿åå¤ä½çç©ºæ ¼ï¼å°¼çä½æ­»çWA å¨è¿é*/
                maze[i][j]=s[0];
            }
        int res=bfs();
        printf(res==-1?"impossible\n":"%d\n",res);
    }
    return 0;
}
