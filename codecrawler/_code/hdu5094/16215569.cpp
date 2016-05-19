/**
hdu5094 ç¶æåç¼©+bfs
é¢ç®å¤§æï¼ç»å®ä¸ä¸ªæ£çï¼ä»(1,1)èµ°å°(n,m)æçä»»æä¸¤ä¸ªæ ¼å­ä¹é´çè¾¹è§ä¸ºï¼éè·¯ï¼é¨ï¼å¢ãéè·¯å¯ä»¥ç´æ¥èµ°ï¼é¨å¿é¡»æ©å°ç¸åºçé¥åï¼å¢æ°¸è¿ä¸è½éè¿ãé¥åå¨ä¸äºç»å®ç¹ç
          æ ¼å­ä¸­(åä¸ä¸ªæ ¼å­ä¸­å¯è½æå¤æé¥å)ï¼é®éåææ ·çèµ°æ³å¯ä»¥å¾å°æå°çç§»å¨æ­¥æ°
è§£é¢æè·¯ï¼vis[x][y][s]è¡¨ç¤ºç¶æä¸ºsæ¶å°è¾¾(x,y)ç¹æ¯å¦å·²ç»å°è¾¾è¿ï¼sè¡¨ç¤ºé¥åçå¾å°æåµçç¶æãç¶åè¿è¡bfså³å¯
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int a[53][53][53][53],key[53][53],vis[53][53][1<<11];
int dx[4][2]= {0,1,0,-1,-1,0,1,0};
int n,m,k,p;
struct note
{
    int x,y,dep,s;
    note() {}
    note(int _x,int _y,int _dep,int _s)
    {
        x=_x;
        y=_y;
        dep=_dep;
        s=_s;
    }
};
bool judge(int xx,int yy)
{
    if(xx>=1 && xx<=n && yy>=1 && yy<=m)  return true;
    return false;
}
int bfs()
{
    queue<note>q;
    memset(vis,0,sizeof(vis));
    q.push(note(1,1,0,key[1][1]));
    vis[1][1][key[1][1]]=1;
    while(!q.empty())
    {
        int x=q.front().x;
        int y=q.front().y;
        int dep=q.front().dep;
        int s=q.front().s;
        q.pop();
        if(x==n&&y==m)return dep;
        for(int i=0; i<4; i++)
        {
            int xx=x+dx[i][0];
            int yy=y+dx[i][1];
            int ss=s|key[xx][yy];
            int t=a[x][y][xx][yy];
            int w=1<<(t-1);
            if(judge(xx,yy)&&((t==-1)||(ss&w)&&t!=0)&&!vis[xx][yy][ss])
            {
                vis[xx][yy][ss]=1;
                q.push(note(xx,yy,dep+1,ss));
            }
        }
    }
    return -1;
}
int main()
{
    while(~scanf("%d%d%d",&n,&m,&p))
    {
        scanf("%d",&k);
        memset(a,-1,sizeof(a));
        for(int i=0; i<k; i++)
        {
            int x,y,xx,yy,q;
            scanf("%d%d%d%d%d",&x,&y,&xx,&yy,&q);
            a[x][y][xx][yy]=a[xx][yy][x][y]=q;
        }
        int S;
        scanf("%d",&S);
        memset(key,0,sizeof(key));
        while(S--)
        {
            int x,y,g;
            scanf("%d%d%d",&x,&y,&g);
            g--;
            if((key[x][y]&(1<<g))==0)
            {
                key[x][y]|=(1<<g);
            }
        }
        printf("%d\n",bfs());
    }
    return 0;
}
