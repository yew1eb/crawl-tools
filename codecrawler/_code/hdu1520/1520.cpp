/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: [email protected]/* <![CDATA[ */!function(t,e,r,n,c,a,p){try{t=document.currentScript||function(){for(t=document.getElementsByTagName('script'),e=t.length;e--;)if(t[e].getAttribute('data-cfhash'))return t[e]}();if(t&&(c=t.previousSibling)){p=t.parentNode;if(a=c.getAttribute('data-cfemail')){for(e='',r='0x'+a.substr(0,2)|0,n=2;a.length-n;n+=2)e+='%'+('0'+('0x'+a.substr(n,2)^r).toString(16)).slice(-2);p.replaceChild(document.createTextNode(decodeURIComponent(e)),c)}p.removeChild(t)}}catch(u){}}()/* ]]> */
 *===========================================*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;

typedef long long int64;
const int INF = 0x3f3f3f3f;
const double PI  = acos(-1.0);

const int MAXN = 6010;

vector<int>adj[MAXN];
int indeg[MAXN];
int val[MAXN];
int f[MAXN][2];
int vis[MAXN];
int n, m;

void dfs(int u){
    vis[u] = true;
    f[u][0] = 0;
    f[u][1] = val[u];
    for(int i=0; i<adj[u].size(); ++i){
        int v = adj[u][i];
        if(vis[v]) continue;
        dfs(v);
        f[u][0] += max(f[v][1], f[v][0]);
        f[u][1] += f[v][0];
    }
}

int main(){

    while(~scanf("%d", &n) && n){

        for(int i=1; i<=n; ++i) adj[i].clear();

        for(int i=1; i<=n; ++i)
            scanf("%d", &val[i]);

        memset(indeg, 0, sizeof(indeg));

            int u, v;
        while(~scanf("%d%d", &v, &u) && v+u){
            adj[u].push_back(v);
            ++indeg[v];
        }

        memset(f, 0, sizeof(f));
        for(int i=1; i<=n; ++i)if(!indeg[i]){
            memset(vis, 0, sizeof(vis));
            dfs(i);
            printf("%d\n", max(f[i][0], f[i][1]));
            break;
        }
    }

    return 0;
}