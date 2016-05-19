#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[100][100];
struct node
{
    int x;
    int y;
}p[100];
int bbs(int x)
{
    if(x<0)
    return -x;
    return x;
}
bool visit[100];
int t;
int ans;
void dfs(int v,int temp,node u)
{
   if(temp>ans)//åªæ
   return;
    if(v==0)//éå½åºå£
    {
        temp=temp+u.x+u.y;
        if(temp<ans)
        ans=temp;
        return;
    }
    int yu;
    for(int i=0;i<t;i++)
    {
        if(visit[i]==false)
        {
           yu=temp+bbs(p[i].x-u.x)+bbs(p[i].y-u.y);
            visit[i]=true;
            dfs(v-1,yu,p[i]);
            visit[i]=false;
        }
    }
    return;
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int w;
        t=0;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            scanf("%d",&w);
            if(j==0&&i==0)
            continue;
            if(w)
            {
                p[t].x=i;
                p[t++].y=j;
            }
        }
        memset(visit,false,sizeof(visit));
        ans=99999999;
        int temp=0;
        node u;
        u.x=0;
        u.y=0;
        dfs(t,temp,u);
        printf("%d\n",ans);
    }
    return 0;
}
