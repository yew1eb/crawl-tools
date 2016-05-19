#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
bool use[30];
bool vis[30][30];
int n;
int a,b;
int dp[1000000];
struct node
{
    int x,y;
}ed;
vector<node> v;
int check1(int x,int y)
{
    if(x>y)
        swap(x,y);
    int x2 = x-4;
    int y2 = y-4;
    int ret=0;
    if(x2>0 && y2>0)
    {
        if(vis[x][x2] && vis[x2][y2] && vis[y2][y] && vis[x][y])
            ret++;
    }
    x2 = x+4;
    y2 = y+4;
    if(x2<17 && y2<17)
    {
        if(vis[x][x2] && vis[x2][y2] && vis[y2][y] && vis[x][y])
            ret++;
    }
    return ret;
}
int check2(int x,int y)
{
    if(x>y)
        swap(x,y);
    int x2,y2;
    x2 = x-1;
    y2 = y-1;
    int ret=0;
    if(x2%4!=0 && y2%4!=0 && x2>0 && y2>0)
    {
        if(vis[x2][x] && vis[x][y] && vis[y][y2] && vis[y2][x2])
            ret++;
    }
    x2 = x+1;
    y2 = y+1;
    if(x%4!=0 && y%4!=0)
    {
        if(vis[x2][x] && vis[x][y] && vis[y][y2] && vis[y2][x2])
            ret++;
    }
    return ret;
}
int dfs(int now,int last)
{
    if(now==25||last==0) return 0;
    int st=0;
    for(int i=0;i<v.size();i++)
    {
        if(use[i]) st|=(1<<i);
    }
    if(dp[st]!=-1) return dp[st];

    int maxs=0;

    for(int i=0;i<v.size();i++)
    {
        if(!use[i])
        {
            int tmp=0;
            vis[v[i].x][v[i].y]=1;
            vis[v[i].y][v[i].x]=1;
            if(abs(v[i].x-v[i].y)==1) tmp=check1(v[i].x,v[i].y);
            else tmp=check2(v[i].x,v[i].y);
            use[i]=1;
            maxs=max(maxs,last-dfs(now+1,last-tmp));
            use[i]=0;
            vis[v[i].x][v[i].y]=0;
            vis[v[i].y][v[i].x]=0;
        }
    }

    dp[st]=maxs;
    return maxs;
}

int main()
{
    int t;
    scanf("%d",&t);
    int ca=1;
    while(t--)
    {
        a=b=0;
        scanf("%d",&n);
        v.clear();
        memset(vis,false,sizeof(vis));
        int x,y;
        for(int trun=1;trun<=n;trun++)
        {
            scanf("%d%d",&x,&y);
            vis[x][y] = vis[y][x] = 1;
            if(abs(x-y)==1)
            {
                int tmp = check1(x,y);
                if(trun&1)
                    a+=tmp;
                else
                    b+=tmp;
            }
            else
            {
                int tmp = check2(x,y);
                if(trun&1)
                    a+=tmp;
                else
                    b+=tmp;
            }
        }
        for(int i=1;i<=16;i++)
        {
            for(int j=i+1;j<=16;j++)
            {
                if(vis[i][j]) continue;
                if(j-i==1&&i%4!=0) {ed.x=i; ed.y=j; v.push_back(ed);}
                else if(j-i==4) {ed.x=i; ed.y=j; v.push_back(ed);}
            }
        }
        if(a>=5||b>=5) {printf("Case #%d: %s\n",ca++,a>=5?"Tom200":"Jerry404");continue;}
        memset(dp,-1,sizeof(dp));
        memset(use,false,sizeof(use));
        if(n+1<=24)
        {
            if((n+1)&1) {a+=dfs(n+1,9-a-b);b=9-a;}
            else {b+=dfs(n+1,9-a-b);a=9-b;}
        }
        printf("Case #%d: %s\n",ca++,a>b?"Tom200":"Jerry404");
    }
    return 0;
}
/*
6
5 6
2 3
3 7
7 11
10 11
3 4
*/