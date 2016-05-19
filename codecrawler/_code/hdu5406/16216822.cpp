#include<queue>
#include<limits>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
const int inf = ~0U>>2;
const int N = 2005 , M = 2000005;
typedef pair<int,int> pii;
struct MCMF{
    int h[N] , dis[N] , ing[N] , pre[N] , s , t , n;
    int to[M] , ne[M] , cap[M] , cost[M] , e;
    void ini(){
        fill(h,h+N,-1);
        e = 0;
    }
    void liu(int u,int v,int c,int w){
        to[e] = v , ne[e] = h[u] , cap[e] = c , cost[e] = w;
        h[u] = e++;
    }
    void link(int u,int v,int c,int w){
        liu(u,v,c,w);
        liu(v,u,0,-w);
    }
    int st[N];
    bool spfa(){
//        queue<int> Q;
        int top=0;
        fill(ing,ing+n,0);
        fill(pre,pre+n,-1);
        fill(dis,dis+n,inf);
        ing[s] = true , dis[s] = 0;
       st[top++]=s;
        while(top>0){
            top--;
            int c=st[top];
//            int c = Q.front();Q.pop();
            ing[c] = false;
            for(int k=h[c];~k;k=ne[k]){
                int v = to[k];
                if(cap[k] <= 0) continue;
                if(dis[c] +  cost[k] < dis[v]){
                    dis[v] = dis[c] + cost[k];
                    pre[v] = k;
                    if(!ing[v]) {
                        st[top++]=v;
                        ing[v]=true;
//                        Q.push(v) , ing[v] = true;
                    }
                }
            }
        }
        return dis[t] != inf;
    }
    int flow , mincost;
    pii run(int _s,int _t,int _n){
        s = _s , t = _t , n = _n;
        flow = mincost = 0;
        while(spfa()){
            int pl = inf , p , k;
            for(p=t;p!=s;p=to[k^1]){
                k = pre[p];
                pl = min(pl,cap[k]);
            }
            for(p=t;p!=s;p=to[k^1]){
                k = pre[p];
                cap[k] -= pl;
                cap[k^1] += pl;
            }
            mincost += pl * dis[t];
            flow += pl;
        }
        return make_pair(flow,mincost);
    }
};
struct g{
    int h,v;
}a[2000];
bool cmp(g a,g b)
{
    if (a.h==b.h) return a.v<b.v;
    return a.h>b.h;
}
int n,i,j,s,t,ss;
const int MAXN = 3000;
MCMF mcmf;
int main()
{
    int test;
    scanf("%d",&test);
    while (test--)
    {
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        scanf("%d%d",&a[i].h,&a[i].v);
    sort(a+1,a+1+n,cmp);
    s=0;t=2*n+2;ss=2*n+1;
    mcmf.ini();

    mcmf.link(s,ss,2,0);
    for (i=1;i<=n;i++)
    {
        mcmf.link(ss,i,1,0);
        mcmf.link(i,n+i,1,-1);
        mcmf.link(n+i,t,1,0);
    }
    for (i=1;i<=n;i++)
        for (j=i+1;j<=n;j++)
            if (a[i].v<=a[j].v)
                mcmf.link(n+i,j,1,0);

    pair<int,int> ans=mcmf.run(s,t,2*n+3);
    printf("%d\n",-ans.second);
    }
}