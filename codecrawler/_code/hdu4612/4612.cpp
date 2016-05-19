#pragma comment(linker, "/STACK:102400000,102400000")
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<utility>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
#define SZ(v) ((int)(v).size())
#define INF 999999999999
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define repf(i, a, b) for(int i = (a); i <= (b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (b); i --)
#define flin freopen( "a.in" , "r" , stdin )
#define flout freopen( "a.out" , "w" , stdout )
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long int64;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;
const int MAXN = 201000;
const int MAXM = 1110000;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

struct node
{
    int id;
    int v;
};
vector<node> G[MAXN];
int dfn[MAXN],low[MAXN],time_cnt=0,br_cnt=0,n,m;
bool brige[MAXM];
void dfs(int u,int faedge)

{
    int v;
    low[u]=dfn[u]=++time_cnt;
    for(int i = 0; i<G[u].size(); i++){
        v=G[u][i].v;
        if(!dfn[v]){
            dfs(v,G[u][i].id);
            low[u]=min(low[v],low[u]);
            if(dfn[u]<low[v]){
                brige[G[u][i].id]=true;
                br_cnt++;
            }
        }
        else if(G[u][i].id!=faedge)
            low[u]=min(low[u],dfn[v]); 
     }
}

void find_brige()
{
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(brige,0,sizeof(brige));
	time_cnt = br_cnt = 0;
	for(int i = 1 ; i <= n ; i++) {
		if (!dfn[i])
			dfs(i, -1);
	}
}
#define edge G
#define hash brige
#define br br_cnt
#define tarjan find_brige
int color[MAXN],vis[MAXN],ans;
void DFS_visit(int u,int c)
{
//    out(u);
//    out(c);
    int v,eid;
    color[u]=c;
    rep(i,SZ(edge[u])){
        v=edge[u][i].v;
        eid=edge[u][i].id;
        if(!hash[eid]&&!color[v]) 
            DFS_visit(v,c);

    }

}

int DFS()
{
    int cnt=0;
    repf(i,1,n)
        if(!color[i]) DFS_visit(i,++cnt);
    return cnt;
}
int ltp;
void maxdis(int u,int dis)
{
    
//    out(u);
//    out(dis);
    int v;
    vis[u]=true;
    if(ans<dis)
    {
        ans=dis;
        ltp=u;
    }
    rep(i,SZ(edge[u])){
        v=edge[u][i].v;
//        out(v);
        if(!vis[v]) 
        {
//            out(u);
//            out(v);
            maxdis(v,dis+(color[u]!=color[v]));
        }
    }

}


void solve()
{
    tarjan();
//    out(br);
   int t= DFS();
//   out(t);
//    cout<<"!!!\n";
    CLR(vis);
    maxdis(1,0);   
    CLR(vis);
    maxdis(ltp,0);
//    out(ans);
    ans=br-ans;
    cout<<ans<<endl;
}


void init()
{
    br=ans=0;    
    ltp=1;
    int x, y;
    rep(i,n+1){
        edge[i].clear();
    }
    CLR(dfn);
    CLR(low);
    CLR(hash);
    CLR(color);
    node t;
    rep(i,m){
        scanf("%d%d",&x,&y);
        t.id=i+1;
        t.v=y;
        edge[x].PB(t);
        t.v=x;
        edge[y].PB(t);
    }
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    //std::ios::sync_with_stdio(false);
    while(1){
        scanf("%d%d",&n,&m);
        if(!n) break;
        init();
        solve();
    }
    return 0;
}