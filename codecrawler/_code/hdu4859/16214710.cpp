#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <queue>
#include <map>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int head[3000], source, sink, nv, cnt;
int cur[3000], num[3000], d[3000], pre[3000];
int jx[]={0,0,1,-1};
int jy[]={1,-1,0,0};
struct node
{
    int u, v, cap, next;
}edge[1000000];
void add(int u, int v, int cap)
{
    edge[cnt].v=v;
    edge[cnt].cap=cap;
    edge[cnt].next=head[u];
    head[u]=cnt++;

    edge[cnt].v=u;
    edge[cnt].cap=0;
    edge[cnt].next=head[v];
    head[v]=cnt++;
}
void bfs()
{
    memset(d,-1,sizeof(d));
    memset(num,0,sizeof(num));
    queue<int>q;
    q.push(sink);
    d[sink]=0;
    num[0]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].v;
            if(d[v]==-1)
            {
                d[v]=d[u]+1;
                num[d[v]]++;
                q.push(v);
            }
        }
    }
}
int isap()
{
    memcpy(cur,head,sizeof(cur));
    bfs();
    int flow=0, u=pre[source]=source, i;
    while(d[source]<nv)
    {
        if(u==sink)
        {
            int f=INF, pos;
            for(i=source;i!=sink;i=edge[cur[i]].v)
            {
                if(f>edge[cur[i]].cap)
                {
                    f=edge[cur[i]].cap;
                    pos=i;
                }
            }
            for(i=source;i!=sink;i=edge[cur[i]].v)
            {
                edge[cur[i]].cap-=f;
                edge[cur[i]^1].cap+=f;
            }
            flow+=f;
            u=pos;
        }
        for(i=cur[u];i!=-1;i=edge[i].next)
        {
            if(d[edge[i].v]+1==d[u]&&edge[i].cap) break;
        }
        if(i!=-1)
        {
            cur[u]=i;
            pre[edge[i].v]=u;
            u=edge[i].v;
        }
        else
        {
            if(--num[d[u]]==0) break;
            int mind=nv;
            for(i=head[u];i!=-1;i=edge[i].next)
            {
                if(mind>d[edge[i].v]&&edge[i].cap)
                {
                    mind=d[edge[i].v];
                    cur[u]=i;
                }
            }
            d[u]=mind+1;
            num[d[u]]++;
            u=pre[u];
        }
    }
    return flow;
}
int main()
{
    int t, n, m, i, j, mp[60][60], num=0;
    char s[60];
    scanf("%d",&t);
    while(t--)
    {
        num++;
        scanf("%d%d",&n,&m);
        memset(mp,0,sizeof(mp));
        for(i=1;i<=n;i++)
        {
            scanf("%s",s);
            for(j=0;j<m;j++)
            {
                if(s[j]=='E')
                    mp[i][j+1]=2;
                else if(s[j]=='.')
                    mp[i][j+1]=1;
            }
        }
        cnt=0;
        memset(head,-1,sizeof(head));
        source=0;
        sink=(n+2)*(m+2)+1;
        nv=sink+1;
        for(i=0;i<=n+1;i++)
        {
            for(j=0;j<=m+1;j++)
            {
                if((i+j)%2==0)
                {
                    if(mp[i][j]==1)
                    {
                        add(i*(m+2)+j+1,sink,INF);
                    }
                    else if(mp[i][j]==0)
                    {
                        add(source,i*(m+2)+j+1,INF);
                    }
                }
                else
                {
                    if(mp[i][j]==0)
                    {
                        add(i*(m+2)+j+1,sink,INF);
                    }
                    else if(mp[i][j]==1)
                    {
                        add(source,i*(m+2)+j+1,INF);
                    }
                }
                for(int k=0;k<4;k++)
                {
                    int x=i+jx[k];
                    int y=j+jy[k];
                    if(x>=0&&x<=n+1&&y>=0&&y<=m+1)
                    {
                        add(i*(m+2)+j+1,x*(m+2)+y+1,1);
                    }
                }
            }
        }
        int ans;
        ans=isap();
        printf("Case %d: %d\n",num,(n+1)*(m+2)+(n+2)*(m+1)-ans);
    }
    return 0;
}
