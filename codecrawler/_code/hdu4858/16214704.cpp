#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long LL;

const int mod=1e9+7;
const int MX=100100+5;
const int INF=0x3f3f3f3f;

struct Edge{
    int u,v;
}E[MX];

int n,m,unit,Q;
int P[MX],sum[MX],A[MX];
vector<int>G[MX];

void update(int x,int d){
    A[x]+=d;
    for(int i=0;i<G[x].size();i++){
        int nxt=G[x][i];
        sum[nxt]+=d;
    }
}

int query(int x){
    if(P[x]<unit){
        sum[x]=0;
        for(int i=0;i<G[x].size();i++){
            int nxt=G[x][i];
            sum[x]+=A[nxt];
        }
        return sum[x];
    }else{
        return sum[x];
    }
}

int main(){
    int T;
    scanf("%d",&T);

    while(T--){
        scanf("%d%d",&n,&m);

        memset(A,0,sizeof(A));
        memset(P,0,sizeof(P));
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++) G[i].clear();

        for(int i=1;i<=m;i++){
            scanf("%d%d",&E[i].u,&E[i].v);
            P[E[i].u]++;
            P[E[i].v]++;
        }

        unit=sqrt(m+0.5);
        for(int i=1;i<=m;i++){
            int u=E[i].u,v=E[i].v;

            if(P[u]<unit) G[u].push_back(v);
            else if(P[v]>=unit) G[u].push_back(v);

            if(P[v]<unit) G[v].push_back(u);
            else if(P[u]>=unit) G[v].push_back(u);
        }

        scanf("%d",&Q);
        while(Q--){
            int cmd,a,b;
            scanf("%d",&cmd);

            if(cmd==0){
                scanf("%d%d",&a,&b);
                update(a,b);
            }
            else{
                scanf("%d",&a);
                printf("%d\n",query(a));
            }
        }
    }
    return 0;
}
