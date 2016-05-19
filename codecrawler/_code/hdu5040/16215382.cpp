#include <cstdio>
#include <queue>
#define INF 99999999;
using namespace std;

char mp[500][505];
int n,ex,ey,nxt[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int vis[500][500];

struct S{
int x,y,step;

bool operator<(const S &p) const
{
    return step>p.step;
}

}t;

bool check(int x,int y,int time)//å¤æ­è¯¥ç¹æ¯å¦è¢«ç§å°
{
    if(mp[x][y]!='.') return 0;

    if(x-1>=0 && mp[x-1][y]!='.')
    {
        switch(time)
        {
            case 0:if(mp[x-1][y]=='S') return 0; break;
            case 1:if(mp[x-1][y]=='E') return 0; break;
            case 2:if(mp[x-1][y]=='N') return 0; break;
            case 3:if(mp[x-1][y]=='W') return 0; break;
        }
    }

    if(x+1<n && mp[x+1][y]!='.')
    {
        switch(time)
        {
            case 0:if(mp[x+1][y]=='N') return 0; break;
            case 1:if(mp[x+1][y]=='W') return 0; break;
            case 2:if(mp[x+1][y]=='S') return 0; break;
            case 3:if(mp[x+1][y]=='E') return 0; break;
        }
    }

    if(y-1>=0 && mp[x][y-1]!='.')
    {
        switch(time)
        {
            case 0:if(mp[x][y-1]=='E') return 0; break;
            case 1:if(mp[x][y-1]=='N') return 0; break;
            case 2:if(mp[x][y-1]=='W') return 0; break;
            case 3:if(mp[x][y-1]=='S') return 0; break;
        }
    }

    if(y+1<n && mp[x][y+1]!='.')
    {
        switch(time)
        {
            case 0:if(mp[x][y+1]=='W') return 0; break;
            case 1:if(mp[x][y+1]=='S') return 0; break;
            case 2:if(mp[x][y+1]=='E') return 0; break;
            case 3:if(mp[x][y+1]=='N') return 0; break;
        }
    }

    return 1;
}

int main()
{
    int T,i,j,time,cases=1;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++) scanf("%s",mp[i]);

        printf("Case #%d: ",cases++);

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(mp[i][j]=='M') mp[i][j]='.',t.x=i,t.y=j;
                else if(mp[i][j]=='T') mp[i][j]='.',ex=i,ey=j;
            }
        }

        for(i=0;i<n;i++) for(j=0;j<n;j++) vis[i][j]=INF;

        t.step=0;

        vis[t.x][t.y]=0;

        priority_queue<S>que;

        que.push(t);

        while(!que.empty())
        {
            t=que.top();

            if(t.x==ex && t.y==ey)
            {
                printf("%d\n",t.step);

                break;
            }

            que.pop();

            t.step++;

            for(i=0;i<4;i++)
            {
                t.x+=nxt[i][0];
                t.y+=nxt[i][1];

                if(mp[t.x][t.y]=='#' || t.x<0 || t.x>=n || t.y<0 || t.y>=n)
                {
                    t.x-=nxt[i][0];
                    t.y-=nxt[i][1];

                    continue;
                }

                if(mp[t.x][t.y]=='.')//å¦æç®æ ç¹æ¯ç©ºå°
                {
                    for(j=0;j<3;j++)//æå¤ç­ä¸ç§
                    {
                        time=(t.step+j-1)%4;

                        if(check(t.x,t.y,time) && check(t.x-nxt[i][0],t.y-nxt[i][1],time) && t.step+j<vis[t.x][t.y])//èµ·ç¹åç®æ ç¹é½ä¸è¢«ç§å°
                        {
                            t.step+=j;

                            vis[t.x][t.y]=t.step;

                            que.push(t);

                            t.step-=j;

                            break;//æ¾å°ä¸ä¸ªæå°è½å°çæ¶é´å³å¯
                        }
                    }

                    if(j==3)//å¦æç­ä¸ç§é½æ²¡ç­å°å¯ä»¥èµ°çï¼å°±ç´æ¥èº²çå­éé¢èµ°
                    {
                        t.step+=2;

                        if(t.step<vis[t.x][t.y])
                        {
                            vis[t.x][t.y]=t.step;

                            que.push(t);
                        }

                        t.step-=2;
                    }
                }
                else//å¦æç®æ ç¹æ¯ç¯ï¼åç´æ¥èº²çå­éé¢èµ°
                {
                    t.step+=2;

                    if(t.step<vis[t.x][t.y])
                    {
                        vis[t.x][t.y]=t.step;

                        que.push(t);
                    }

                    t.step-=2;
                }

                t.x-=nxt[i][0];
                t.y-=nxt[i][1];
            }
        }

        if(que.empty()) printf("-1\n");
    }
}