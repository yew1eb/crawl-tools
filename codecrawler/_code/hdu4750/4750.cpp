#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 10010
#define M 500500
struct Edge
{
    int u,v,w;
}edge[M];
bool cmp(Edge u,Edge v)
{
    return u.w<v.w;
}
struct Q
{
    int t,idx,val;
    Q(int t=0,int idx=0,int val=0)
    {
        this->t=t;this->idx=idx;this->val=val;
    }
}q[N*14];
bool cmp2(Q u,Q v)
{
    return u.t<v.t;
}
int n,m,p,fa[N],num[N],ans[N*10];
int _find(int u)
{
    return fa[u]==u?u:fa[u]=_find(fa[u]);
}
void update(int f,int val)
{
    int left=0,right=p,mid;
    while(left<right)
    {
        mid=left+right>>1;
        if(q[mid].t<=f) left=mid+1;
        else right=mid;
    }
    if(q[left].val>f) return;
    q[0].val+=val;
    q[left].val-=val;
}
int main ()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<m;++i)
            scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
        scanf("%d",&p);
        for(int i=0;i<p;++i)
        {
            scanf("%d",&q[i].t);
            q[i].idx=i;q[i].val=0;
        }
        sort(q,q+p,cmp2);
        sort(edge,edge+m,cmp);

        for(int i=0;i<n;++i) fa[i]=i,num[i]=1;
        int cc=0;
        for(int i=0;i<m;++i)
        {
            int u=_find(edge[i].u);
            int v=_find(edge[i].v);
            if(u==v) continue;
            update(edge[i].w,num[u]*num[v]*2);
            fa[u]=v;
            num[v]+=num[u];

            if(++cc>=n-1) break;
        }
        for(int i=0,k=0;i<p;++i)
        {
            k+=q[i].val;
            q[i].val=k;
        }
        for(int i=0;i<p;++i) ans[q[i].idx]=q[i].val;
        for(int i=0;i<p;++i) printf("%d\n",ans[i]);
    }
    return 0;
}
