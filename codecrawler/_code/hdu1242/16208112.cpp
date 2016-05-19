#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
using namespace std;
char map[205][205];
int visit[205][205];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n,m;
struct node
{
    int x,y;
    int time;
    friend bool operator < (const node &a,const node &b)  //æ¶é´å°çååºé
    {
        return a.time>b.time;
    }
};
int go(int x,int y)
{
    if(0<=x&&x<n&&0<=y&&y<m&&map[x][y]!='#')
    return 1;
    return 0;
}
int bfs(int x,int y)
{
    int i;
    node st,ed;
    priority_queue<node>que;  //å®ä¹ä¸ä¸ªä¼åéå
    memset(visit,0,sizeof(visit));
    st.x=x;
    st.y=y;
    st.time=0;
    visit[st.x][st.y]=1;
    que.push(st);
    while(!que.empty())
    {
        st=que.top();
        que.pop();
        if(map[st.x][st.y]=='r')
        return st.time;
        for(i=0;i<4;i++)
        {
            ed.x=st.x+dir[i][0];
            ed.y=st.y+dir[i][1];
            if(go(ed.x,ed.y)&&!visit[ed.x][ed.y])
            {
                visit[ed.x][ed.y]=1;
                if(map[ed.x][ed.y]=='x')
                ed.time=st.time+2;
                else
                ed.time=st.time+1;
                que.push(ed);
            }
        }
    }
    return -1;
}
int main()
{
    int i,j;
    int x,y,ans;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)
        scanf("%s",map[i]);
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        if(map[i][j]=='a')
        {
            x=i;
            y=j;
            break;
        }
        ans=bfs(x,y);
        if(ans==-1)
        printf("Poor ANGEL has to stay in the prison all his life.\n");
        else
        printf("%d\n",ans);
    }
    return 0;
}
