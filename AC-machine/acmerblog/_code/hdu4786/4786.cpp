#include <cstdio>
#include <algorithm>

using namespace std;

struct Edge {
    int s,e,c;
    Edge(int ss=0,int ee=0,int cc=0):s(ss),e(ee),c(cc) {}
    bool operator < (const Edge& a) const {
        return c<a.c;
    }
}g[100005];

int par[100005],pa,pb,f[25];

int getPar(int a) {
    if(par[a]!=a)
        par[a]=getPar(par[a]);
    return par[a];
}

void Merge(int a,int b) {
    pa=getPar(a),pb=getPar(b);
    if(pa!=pb)
        par[pb]=pa;
}

int main() {
    int n,m,i,T,kase=0,cnt,low,hig;
    bool flag;
    i=1,f[0]=1,f[1]=2;
    while(f[i]<100005) {
        f[i+1]=f[i]+f[i-1];
        ++i;
    }
    scanf("%d",&T);
    while(kase<T) {
        scanf("%d%d",&n,&m);
        low=hig=0,cnt=1;
        for(i=0;i<m;++i)
            scanf("%d%d%d",&g[i].s,&g[i].e,&g[i].c);
        for(i=1;i<=n;++i)
            par[i]=i;
        sort(g,g+m);
        for(i=0;i<m&&cnt!=n;++i) {
            if(getPar(g[i].s)!=getPar(g[i].e)) {
                Merge(g[i].s,g[i].e);
                ++cnt;
                low+=g[i].c;
            }
        }
        flag=false;
        if(cnt==n) {//如果图是连通的
            cnt=1;
            for(i=1;i<=n;++i)
                par[i]=i;
            for(i=m-1;i>=0&&cnt!=n;--i) {
                if(getPar(g[i].s)!=getPar(g[i].e)) {
                    Merge(g[i].s,g[i].e);
                    ++cnt;
                    hig+=g[i].c;
                }
            }
            i=0;
            while(f[i]<low)
                ++i;
            if(f[i]<=hig)
                flag=true;
        }
        printf("Case #%d: %s\n",++kase,flag?"Yes":"No");
    }
    return 0;
}
