#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct
{
    int x1,y1,x2,y2;
}ans;

ans p[10000];
int map1[100][100];
int map2[100][100];
bool s[100][100];
bool vis[100][100];
int up;
int n,m;
int minx,miny,maxx,maxy;

bool Check(ans a,ans b)
{
 //   printf("%d...%d...%d...%d\n",max(a.y2,b.y2),min(a.y1,b.y1));
    if (max(a.x2,b.x2)-min(a.x1,b.x1)<=a.x2-a.x1+b.x2-b.x1 && max(a.y2,b.y2)-min(a.y1,b.y1)<=a.y2-a.y1+b.y2-b.y1) return true;
    return false;
}

void DFS(int x,int y)
{
    int i,j;
    if (vis[x][y]==1) return;
    vis[x][y]=1;
    if (minx==x && miny==y && s[x-1][y-1]==1)
    {
        minx--;
        miny--;
        DFS(x-1,y-1);
    }
    if (minx==x && maxy==y && s[x-1][y+1]==1)
    {
        minx--;
        maxy++;
        DFS(x-1,y+1);
    }
    if (maxx==x && miny==y && s[x+1][y-1]==1)
    {
        maxx++;
        miny--;
        DFS(x+1,y-1);
    }
    if (maxx==x && maxy==y && s[x+1][y+1]==1)
    {
        maxx++;
        maxy++;
        DFS(x+1,y+1);
    }
    if (minx==x && s[x-1][y]==1)
    {
        minx--;
        DFS(x-1,y);
    }
    if (miny==y && s[x][y-1]==1)
    {
        miny--;
        DFS(x,y-1);
    }
    if (maxy==y && s[x][y+1]==1)
    {
        maxy++;
        DFS(x,y+1);
    }
    if (maxx==x && s[x+1][y]==1)
    {
        maxx++;
        DFS(x+1,y);
    }
    if (minx<x) DFS(x-1,y);
    if (miny<y) DFS(x,y-1);
    if (maxx>x) DFS(x+1,y);
    if (maxy>y) DFS(x,y+1);
}

bool cmp(ans a,ans b)
{
    if (a.x1!=b.x1) return a.x1<b.x1;
    return a.y1<b.y1;
}

int main()
{
    int i,j;
    ans tag;
    bool ok;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                scanf("%d",&map1[i][j]);
            }
        }
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                scanf("%d",&map2[i][j]);
            }
        }
        memset(s,0,sizeof(s));
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                s[i+1][j+1]=(map1[i][j]!=map2[i][j]);
            }
        }
        up=0;
        memset(vis,0,sizeof(vis));
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=m;j++)
            {
                if (s[i][j]==1 && vis[i][j]==0)
                {
                    maxx=minx=i;
                    maxy=miny=j;
                    DFS(i,j);
                    p[up].x1=minx;
                    p[up].y1=miny;
                    p[up].x2=maxx;
                    p[up].y2=maxy;
                    up++;
                 //   debug();
                }
            }
        }
        while(1)
        {
            ok=0;
            for (i=0;i<up;i++)
            {
                for (j=i+1;j<up;j++)
                {
                    if (Check(p[i],p[j])==true)
                    {
                        ok=1;
                        tag.x1=min(p[i].x1,p[j].x1);
                        tag.y1=min(p[i].y1,p[j].y1);
                        tag.x2=max(p[i].x2,p[j].x2);
                        tag.y2=max(p[i].y2,p[j].y2);
                        p[i]=tag;
                        p[j]=p[up-1];
                        up--;
                    }
                }
            }
            if (ok==0) break;
        }
        sort(p,p+up,cmp);
        printf("%d\n",up);
        for (i=0;i<up;i++)
        {
            printf("%d %d %d %d\n",p[i].x1,p[i].y1,p[i].x2,p[i].y2);
        }
    }
    return 0;
}
