#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 3e5 + 10;
const int inf = 1e8;
int pos[maxn],depth[maxn],head[maxn];
int d[maxn<<1][20],width[maxn<<1],tot,e;
typedef pair<int,int> Edge;
Edge edges[maxn<<1];
void AddEdge(int u,int v)
{
    edges[++e] = make_pair(v,head[u]);head[u] = e;
    edges[++e] = make_pair(u,head[v]);head[v] = e;
}
void pre(int u,int fa,int dep = 0)
{
    d[++tot][0] = u;
    if(!pos[u]) {
        pos[u] = tot;
        depth[u] = dep; 
    }
    for(int eid = head[u]; eid ; eid = edges[eid].second) {
        int &v = edges[eid].first;
        if(v==fa)continue;
        pre(v,u,dep+1);
        d[++tot][0] = u;
    }
}
void RMQ_init(int n)
{
    for(int j = 1; (1<<j) <= n; j++) {
        for(int i = 1; i + (1<<j) - 1 <= n; i++) {
            d[i][j] = depth[d[i][j-1]] < depth[d[i+(1<<(j-1))][j-1]] ? d[i][j-1] : d[i+(1<<(j-1))][j-1];
        }
    }
    for(int i = 1,w = 1; i <= n; i++) {
        if((1<<w) <= i) w++;
        width[i] = w;
    }
}
int LCA(int u,int v)
{
    int L = pos[u],R = pos[v];
    if(L > R) swap(L,R);
    int k = width[R-L+1] - 1;
    return depth[d[L][k]] < depth[d[R-(1<<k)+1][k]] ? d[L][k] : d[R-(1<<k)+1][k];
}
int seg[maxn<<1];
void built(int o,int L,int R)
{
    if(L==R) {
        seg[o] = L;
        return;
    }
    int mid = (L + R) >> 1;
    built(o<<1,L,mid);
    built(o<<1|1,mid+1,R);
    seg[o] = LCA(seg[o<<1],seg[o<<1|1]);
}
int ql,qr;
int Query(int o,int L,int R)
{
    if(ql<=L&&qr>=R) {
        return seg[o];
    }
    int mid = (L + R) >> 1;
    int ans = -1;
    if(ql <= mid) ans = Query(o<<1,L,mid);
    if(qr > mid) {
        int t = Query(o<<1|1,mid+1,R);
        if(ans==-1) ans = t;
        else ans = LCA(ans,t);
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int n;
    while(scanf("%d",&n)==1) {

        memset(head,0,sizeof(head[0])*(n+1));
        for(int i = 1; i < n; i++) {
            int u, v;scanf("%d%d",&u,&v);
            AddEdge(u,v);
        }
        e = tot = 0;
        memset(pos,0,sizeof(pos[0])*(n+1));
        pre(1,-1);
        RMQ_init(tot);
        built(1,1,n);
        int Q;scanf("%d",&Q);
        while(Q--) {
            scanf("%d%d",&ql,&qr);
            if(ql > qr) swap(ql,qr);
            printf("%d\n", Query(1,1,n));
        } 
    }
    return 0;
}
