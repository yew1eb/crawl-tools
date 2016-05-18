#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
using namespace std;
typedef long long ll;
bool vis[105][6][6][202];
int g[105][6][6][202];
int n,m,b,r,k,t,numtt;
int trade[105][6];
inline int getint() {
    char c = getchar();
    int t = 0;
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        t = t * 10 + c - '0';
        c = getchar();
    }
    return t;
}
struct Edge
{
    int v,wt,wm,next;
}edge[202];
int ge[105];
struct sta
{
    int id,b,k,t;
    sta(){};
    sta(int x1,int x2,int x3,int x4)
    {
        id=x1;
        b=x2;
        k=x3;
        t=x4;
    }
//    bool operator>(const sta& s1)const
//    {
//
//        return t>s1.t;
//    }

    bool operator<(const sta& s1)const
    {
        return t<s1.t;
    }
};
int en;

void bfs()
{
    memset(vis,false,sizeof vis);
    memset(g,-1,sizeof g);
    priority_queue<sta> q;
    vis[1][0][0][t]=true;
    g[1][0][0][t]=r;
    q.push(sta(1,0,0,t));
    while(!q.empty())
    {
        sta now=q.top();
        sta tmp=now;
        q.pop();

//        vis[now.id][now.b][now.k][now.t]=false;
        int tid=now.id,tb=now.b,tk=now.k,tt=now.t;
        int fee;
        if (tt>0 && tid!=n && tid!=1)
        {
            tk++;
            if (tk==k) tk=0;
            tt--;
            if (g[tid][tb][tk][tt]<g[now.id][now.b][now.k][now.t])
            {
                g[tid][tb][tk][tt]=g[now.id][now.b][now.k][now.t];
                if (!vis[tid][tb][tk][tt])
                {
                    q.push(sta(tid,tb,tk,tt));
                    vis[tid][tb][tk][tt]=true;
                }
            }
                int ttk=tk,ttid=tid,ttb=tb,ttt=tt;
                fee=g[now.id][now.b][now.k][now.t];

                if (fee>=trade[ttid][ttk] && ttb<b)
                {
                    fee-=trade[ttid][ttk];
                    ttb++;
                    if (g[ttid][ttb][ttk][ttt]<fee)
                    {
                        g[ttid][ttb][ttk][ttt]=fee;
                        if (!vis[ttid][ttb][ttk][ttt])
                        {
                            q.push(sta(ttid,ttb,ttk,ttt));
                            vis[ttid][ttb][ttk][ttt]=true;
                        }
                    }
                }
                ttk=tk; ttid=tid; ttb=tb; ttt=tt;
                fee=g[now.id][now.b][now.k][now.t];
                if (ttb>0)
                {
                    fee+=trade[ttid][ttk];
                    ttb--;
                    if (g[ttid][ttb][ttk][ttt]<fee)
                    {
                        g[ttid][ttb][ttk][ttt]=fee;
                        if (!vis[ttid][ttb][ttk][ttt])
                        {
                            q.push(sta(ttid,ttb,ttk,ttt));
                            vis[ttid][ttb][ttk][ttt]=true;
                        }
                    }
                }


        }
        for (int j=ge[now.id]; j!=-1; j=edge[j].next)
        {
            tid=now.id;
            tb=now.b;
            tk=now.k;
            tt=now.t;
            fee=g[tid][tb][tk][tt];
            int u=now.id;
            int v;
            if (fee>=edge[j].wm && tt>=edge[j].wt)
            {
                v=edge[j].v;
                if ((v==1 || v==n) && tk!=0) continue;

                fee-=edge[j].wm;
                tt-=edge[j].wt;

                if (g[v][tb][tk][tt]<fee)
                {
                    g[v][tb][tk][tt]=fee;
                    if (!vis[v][tb][tk][tt] && v!=n)
                    {
                        q.push(sta(v,tb,tk,tt));
                        vis[v][tb][tk][tt]=true;
                    }
                }
                    if (v!=n && v!=1)
                    {
                        int ttk=tk,ttid=v,ttb=tb,ttt=tt;
                        fee=g[now.id][now.b][now.k][now.t]-edge[j].wm;
                        if (fee>=trade[v][tk] && ttb<b)
                        {
                            fee-=trade[v][tk];
                            ttb++;
                            if (g[ttid][ttb][ttk][ttt]<fee)
                            {
                                g[ttid][ttb][ttk][ttt]=fee;
                                if (!vis[ttid][ttb][ttk][ttt])
                                {
                                    q.push(sta(ttid,ttb,ttk,ttt));
                                    vis[ttid][ttb][ttk][ttt]=true;
                                }
                            }
                        }

                        ttb=tb;
                        fee=g[now.id][now.b][now.k][now.t]-edge[j].wm;

                        if (ttb>0)
                        {
                            fee+=trade[v][tk];
                            ttb--;
                            if (g[v][ttb][ttk][ttt]<fee)
                            {
                                g[v][ttb][ttk][ttt]=fee;
                                if (!vis[v][ttb][ttk][ttt])
                                {
                                    q.push(sta(v,ttb,ttk,ttt));
                                    vis[v][ttb][ttk][ttt]=true;
                                }
                            }
                        }

                    }

            }
        }
    }

}
int main()
{
//    freopen("in.txt","r",stdin);

//    scanf("%d",&numtt);
    numtt=getint();
    for (int ii=1; ii<=numtt; ii++)
    {
        memset(ge,-1,sizeof ge);
//        scanf("%d%d%d%d%d%d",&n,&m,&b,&k,&r,&t);
        n=getint(); m=getint();b=getint(); k=getint(); r=getint(); t=getint();

        for (int i=0; i<k; i++)
         for (int j=1; j<=n; j++)
//         scanf("%d",&trade[j][i]);
            trade[j][i]=getint();

        int x,y,z1,z2;
        en=0;
        for (int i=1; i<=m; i++)
        {
//            scanf("%d%d%d%d",&x,&y,&z1,&z2);
            x=getint(); y=getint(); z1=getint(); z2=getint();
            edge[en].v=y;
            edge[en].wt=z1;
            edge[en].wm=z2;
            edge[en].next=ge[x];
            ge[x]=en;
            en++;

        }
        bfs();
        int ans=-1;
       printf("Case #%d: ",ii);
        for (int i=0; i<=t; i++)
         for (int j=0; j<=b; j++)
         ans=max(ans,g[n][j][0][i]);
        if (ans>=0) printf("%d\n",ans);
        else puts("Forever Alone");

    }
    return 0;
}