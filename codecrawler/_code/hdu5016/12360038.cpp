#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define N 200010
#define inf 2000010000
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
struct ww {
    int a,b;
    inline bool operator < (const ww &A) const {
        return a<A.a||a==A.a&&b<A.b;
    }
} gg[N],h[N];
int i,j,k,n,m,t,x,y,z,l,r,v,num;
int a[N],b[N],next[N],head[N],g[N*100],ty[N],ff[N],F[N],si[N],fa[N],an[N];
inline void add(int x,int y,int z) {
    a[++t]=y,b[t]=z,next[t]=head[x],head[x]=t;
    a[++t]=x,b[t]=z,next[t]=head[y],head[y]=t;
}
inline int getroot(int x) {
    int l,r,v,mi=N,an=0;
    g[l=r=1]=x; fa[x]=0;
    for (;l<=r;l++) for (v=head[g[l]];v;v=next[v])
    if (a[v]!=fa[g[l]]&&F[a[v]]!=num) {
        g[++r]=a[v]; fa[a[v]]=g[l];
    }
    for (l--;l;l--) {
        int A=g[l],ma=0;
        si[A]=1;
        for (v=head[A];v;v=next[v]) if (a[v]!=fa[A]&&F[a[v]]!=num) {
            ma=max(ma,si[a[v]]);
            si[A]+=si[a[v]];
        }
        ma=max(ma,r-si[A]);
        if (ma<mi) mi=ma,an=A;
    }
    return an;
}
inline void Do(int x,int y,int z,int t) {
    int l,r,v,i,s=0;
    g[l=r=1]=x; fa[x]=y,si[x]=z;
    for (;l<=r;l++) for (v=head[g[l]];v;v=next[v])
    if (a[v]!=fa[g[l]]&&F[a[v]]!=num) {
        g[++r]=a[v]; fa[a[v]]=g[l]; si[a[v]]=si[g[l]]+b[v];
    }
    For(i,1,r) {
        int A=g[i];
        h[++s]=(ww){gg[A].a-si[A],gg[A].b};
    }
    sort(h+1,h+s+1);
    For(i,1,r) {
        int A=g[i];
        if (ty[A]) continue;
        ww B={si[A],A};
        int L=1,R=s,mid;
        for (;L<=R;) {
            mid=(L+R)/2;
            if (B<h[mid]) R=mid-1;
            else L=mid+1;
        }
        an[A]+=(s-R)*t;
    }
}
void dfs(int x,int y) {
    int A=getroot(x),v;
    F[A]=num;
    for (v=head[A];v;v=next[v]) if (F[a[v]]!=num) Do(a[v],A,b[v],-1);
    Do(A,0,0,1);
    for (v=head[A];v;v=next[v]) if (F[a[v]]!=num) dfs(a[v],y+1);
}
inline void work() {
    ++num;
    For(i,1,n) an[i]=0;
    dfs(1,0);
    int ans=0;
    For(i,1,n) ans=max(ans,an[i]);
    printf("%d\n",ans);
}
int main() {
    //freopen("1010.in","r",stdin);
    for (;scanf("%d",&n)!=EOF;) {
        For(i,1,n) head[i]=0; t=0;
        For(i,1,n-1) {
            scanf("%d%d%d",&x,&y,&z);
            add(x,y,z);
        }
        For(i,1,n) gg[i].a=inf;
        l=1,r=0;
        For(i,1,n) {
            scanf("%d",&ty[i]);
            if (ty[i]) g[++r]=i,gg[i]=(ww){0,i};
        }
        for (;l<=r;l++) {
            int A=g[l];
            ff[A]=0;
            for (v=head[A];v;v=next[v]) {
                ww B={gg[A].a+b[v],gg[A].b};
                if (B<gg[a[v]]) {
                    gg[a[v]]=B;
                    if (!ff[a[v]]) ff[a[v]]=1,g[++r]=a[v];
                }
            }
        }
        work();
    }
    return 0;
}