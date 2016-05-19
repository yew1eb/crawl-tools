#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int cap[500][500];
int flow[500][500];
int a[500];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i;
        int si,ei,ci;
        memset(cap,0,sizeof(cap));
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&si,&ei,&ci);
            cap[si][ei]+=ci;
        }
        queue<int> q;
        memset(flow,0,sizeof(flow));
        int f=0;
        int p[210];
        for(;;)
        {
            memset(a,0,sizeof(a));
            a[1]=88888888;
            q.push(1);
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                for(int v=1;v<=m;v++)
                {
                    if(!a[v]&&cap[u][v]>flow[u][v])
                    {
                        p[v]=u;
                        q.push(v);
                        a[v] = a[u]<cap[u][v]-flow[u][v]?a[u]:cap[u][v]-flow[u][v];
                    }
                }

            }
            if(a[m]==0)
                break;
            for(int u=m;u!=1;u=p[u])
            {
                flow[p[u]][u]+=a[m];
                flow[u][p[u]]-=a[m];
            }
            f+=a[m];
        }
        printf("%d\n",f);
    }
    return 0;
}
