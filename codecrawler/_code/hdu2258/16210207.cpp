#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<limits.h>
using namespace std;
int mp[22][22];
int visit[22][22];
int dr[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n,m,s;
void dfs(int x,int y,int sum)//dfsæç´¢èéåºå
{
    visit[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int xx=x+dr[i][0];
        int yy=y+dr[i][1];
        if(!visit[xx][yy]&&mp[xx][yy]==sum)
        {
            s++;
            dfs(xx,yy,sum);
        }
    }
    return ;
}

int main()
{
    int sx,sy;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                scanf("%1d",&mp[i][j]);
        }
        int ans=0;
        while(1)
        {
            int k=0;
            for(int i=1;i<=n;i++)//éæ©æå¤§çèéå
            {
                for(int j=1;j<=m;j++)
                {
                    if(mp[i][j])
                    {
                        memset(visit,0,sizeof(visit));
                        s=1;
                        dfs(i,j,mp[i][j]);
                        if(s>k)
                        {
                            sx=i;
                            sy=j;
                            k=s;
                        }
                    }
                }
            }
            if(k<1)   break;//ä¸è¦åæk<=1=ã=
            ans+=k*(k-1);
            memset(visit,0,sizeof(visit));//å¯¹èéåè¿è¡æ å¿
            dfs(sx,sy,mp[sx][sy]);
            for(int i=1;i<=n;i++)//èéåæ¶0
            {
                for(int j=1;j<=m;j++)
                {
                    if(visit[i][j])
                        mp[i][j]=0;
                }
            }
            for(int j=1;j<=m;j++)//ç«åæ¶0
            {
                for(int i=1;i<=n;i++)
                {
                    if(mp[i][j]==0)
                    {
                        for(int k=i;k>1;k--)
                            mp[k][j]=mp[k-1][j];
                        mp[1][j]=0;
                    }
                }
            }
            for(int j=1;j<=m;j++)//åå·¦ç§»å¨
            {
                if(mp[n][j]==0)
                {
                    for(int k=j;k>1;k--)
                    {
                        for(int l=1;l<=n;l++)
                            mp[l][k]=mp[l][k-1];

                    }
                    for(int i=1;i<=n;i++)
                        mp[i][1]=0;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
