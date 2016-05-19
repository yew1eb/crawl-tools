#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define INF 99999999
using namespace std;
struct node
{
    int u,v,w;
};
node edge[1005];
int p[205];
bool operator<(node a,node b)
{
    return a.w<b.w;
}
void make_set(int n)
{
    int i;
    for(i=0;i<=n;i++)
        p[i]=i;
}
int find_set(int i)
{
    int j=i;
    while(j!=p[j])
        j=p[j];
    return p[i]=j;
}
int Union(int x,int y)
{
    x=find_set(x);
    y=find_set(y);
    if(x==y)
        return 0;
    else
    {
        p[x]=y;
        return 1;
    }
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(edge,0,sizeof(edge));
        int i;
        for(i=0;i<m;i++)
            scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
        int q;
        sort(edge,edge+m);
        scanf("%d",&q);
        while(q--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            int j;
            int res=INF;
            for(i=0;i<m;i++)
            {
                make_set(n);
                for(j=i;j<m;j++)
                {
                    Union(edge[j].u,edge[j].v);
                    if(find_set(u)==find_set(v))
                    {
                        if(edge[j].w-edge[i].w<res)
                            res=edge[j].w-edge[i].w;
                        break;
                    }
                }
            }
            if(res==INF)
                printf("-1\n");
            else
                printf("%d\n",res);
        }
    }
    return 0;
}
