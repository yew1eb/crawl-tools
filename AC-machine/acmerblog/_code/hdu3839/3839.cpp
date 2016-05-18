#include <cstdio>
#include <algorithm>
using namespace std;

char ts[201],mes[6]={'W','A','K','J','S','D'},ans[10];
bool vis[205][205];
int n,m,mp[205][205],nxt[4][2]={{1,0},{0,1},{-1,0},{0,-1}},num;

void dfs(int x,int y)
{
    int i;

    for(i=0;i<4;i++)
    {
        x+=nxt[i][0];
        y+=nxt[i][1];

        if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && !mp[x][y])
        {
            vis[x][y]=1;
            dfs(x,y);
        }

        x-=nxt[i][0];
        y-=nxt[i][1];
    }
}

void dfs3(int x,int y)
{
    int i;

    for(i=0;i<4;i++)
    {
        x+=nxt[i][0];
        y+=nxt[i][1];

        if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && !mp[x][y])
        {
            vis[x][y]=1;
            dfs3(x,y);
        }

        x-=nxt[i][0];
        y-=nxt[i][1];
    }
}

void dfs2(int x,int y)
{
    int i;

    for(i=0;i<4;i++)
    {
        x+=nxt[i][0];
        y+=nxt[i][1];

        if(x>=0 && x<n && y>=0 && y<m && !vis[x][y])
        {
            if(mp[x][y])
            {
                vis[x][y]=1;
                dfs2(x,y);
            }
            else
            {
                vis[x][y]=1;
                num++;
                dfs3(x,y);
            }

        }

        x-=nxt[i][0];
        y-=nxt[i][1];
    }
}

int main()
{
    int i,j,t,casenum=1,cnt;

    while(~scanf("%d%d",&n,&m) && n)
    {
        n++;
        m*=4;
        m++;

        for(i=0;i<=n;i++) for(j=0;j<=m;j++) vis[i][j]=0;

        for(i=1;i<n;i++)
        {
            gets(ts);

            if(!ts[0])
            {
                i--;
                continue;
            }


            for(j=0;ts[j];j++)
            {
                if(ts[j]>='a' && ts[j]<='f')
                {
                    t=ts[j]-'a'+10;

                    mp[i][j*4+1]=t/8;
                    mp[i][j*4+2]=t%8/4;
                    mp[i][j*4+3]=t%4/2;
                    mp[i][j*4+4]=t%2/1;
                }
                else
                {
                    t=ts[j]-'0';

                    mp[i][j*4+1]=t/8;
                    mp[i][j*4+2]=t%8/4;
                    mp[i][j*4+3]=t%4/2;
                    mp[i][j*4+4]=t%2/1;
                }
            }
        }

        for(i=0;i<=m;i++) mp[n][i]=0;
        for(i=0;i<=n;i++) mp[i][m]=0;

        n++;
        m++;

        vis[0][0]=1;
        dfs(0,0);

        cnt=0;

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(mp[i][j] && !vis[i][j])
                {
                    num=0;

                    vis[i][j]=1;

                    dfs2(i,j);

                    ans[cnt++]=mes[num];
                }
            }
        }

        sort(ans,ans+cnt);

        ans[cnt]=0;

        printf("Case %d: ",casenum++);
        
        puts(ans);
    }
}
