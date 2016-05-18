#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char mp[60][60];
int dir[4][2]={-1,0,0,1,1,0,0,-1};
int n,up,down,le,ri;
bool flag;

bool Isok(int x,int y)
{
    if (x>0&&x<=n&&y>0&&y<=n&&mp[x][y]=='#')
        return true;
    return false;
}

void dfs_up(int x,int y)
{
    int dx=x+dir[0][0];
    int dy=y+dir[0][1];
    if (Isok(dx,dy))
    {
        if (mp[dx][dy-1]=='#'||mp[dx][dy+1]=='#')
        {
            flag=false;
            return ;
        }
        mp[dx][dy]='.';
        up++;
        dfs_up(dx,dy);
    }
    return ;
}

void dfs_down(int x,int y)
{
    int dx=x+dir[2][0];
    int dy=y+dir[2][1];
    if (Isok(dx,dy))
    {
        if (mp[dx][dy-1]=='#'||mp[dx][dy+1]=='#')
        {
            flag=false;
            return ;
        }
        mp[dx][dy]='.';
        down++;
        dfs_down(dx,dy);
    }
    return ;
}

void dfs_le(int x,int y)
{
    int dx=x+dir[3][0];
    int dy=y+dir[3][1];
    if (Isok(dx,dy))
    {
        if (mp[dx-1][dy]=='#'||mp[dx+1][dy]=='#')
        {
            flag=false;
            return ;
        }
        mp[dx][dy]='.';
        le++;
        dfs_le(dx,dy);
    }
    return ;
}

void dfs_ri(int x,int y)
{
    int dx=x+dir[1][0];
    int dy=y+dir[1][1];
    if (Isok(dx,dy))
    {
        if (mp[dx+1][dy]=='#'||mp[dx-1][dy]=='#')
        {
            flag=false;
            return ;
        }
        mp[dx][dy]='.';
        ri++;
        dfs_ri(dx,dy);
    }
    return ;
}

int main()
{
    while (scanf("%d",&n)&&n)
    {
        memset(mp,'o',sizeof(mp));
        getchar();
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
                scanf("%c",&mp[i][j]);
            getchar();
        }
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (mp[i][j]=='#')
                {
                    int f=1;
                    for (int t=0;t<4;t++)
                        if (mp[ i+dir[t][0] ][ j+dir[t][1] ]!='#')
                        {
                            f=0;
                            break;
                        }
                    if (f)
                    {
                        flag=true;
                        up=0,down=0,le=0,ri=0;
                        dfs_up(i,j);
                        dfs_down(i,j);
                        dfs_le(i,j);
                        dfs_ri(i,j);
                        if (flag)
                        {
                            if (up==down&&down==le&&le==ri&&up!=0)
                                ans++;
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}