//Edmondes-Karp
#include <cstdio>
#include <cstring>
#include <queue>
#define INF 0x7fffffff
using namespace std;
queue<int> q;
const int maxn = 200;
int n, m, ans;
int next[maxn+10], p[maxn+10], f[maxn+10][maxn+10], cap[maxn+10][maxn+10];
int Edmondes_Karp(int s, int t) {
    int ans = 0, v, u;
    queue<int> q;
    memset(f,0,sizeof(f));
    while(true) {
        memset(p,0,sizeof(p));
        p[s] = INF;
        q.push(s);
        while(!q.empty()) { //BFSÕÒÔö¹ãÂ·
            int u = q.front();
            q.pop();
            for(v=1; v<=m; v++)
                if(!p[v]&&cap[u][v]>f[u][v]) { //ÕÒµ½ÐÂ½Úµãv
                    next[v] = u;                //¼ÇÂ¼vµÄ¸¸Ç×£¬²¢¼ÓÈëFIFO¶ÓÁÐ
                    q.push(v);
                    p[v] = p[u] < cap[u][v]-f[u][v]?p[u] : cap[u][v] - f[u][v];
                    //s-vÂ·¾¶ÉÏµÄ×îÐ¡²ÐÁ¿
                }
        }
        if(!p[t]) break;    //ÕÒ²»µ½Ôö¹ãÂ·,Ôòµ±Ç°Á÷ÒÑ¾­ÊÇ×î´óÁ÷
        for(u=t; u!=s; u= next[u]) { //´Ó»ãµãÍù»Ø×ß
            f[next[u]][u] +=p[t];//¸üÐÂÕýÏòÁ÷Á¿
            f[u][next[u]] -=p[t];//¸üÐÂ·´ÏòÁ÷Á¿
        }
        ans += p[t];    //¸üÐÂ´ÓsÁ÷³öµÄ×ÜÁ÷Á¿
    }
    return ans;
}
int main() {
    int i, k, k1, k2, k3;
    while(~scanf("%d%d",&n,&m)) {
        memset(cap,0,sizeof(cap));
        for(i=1; i<=n; i++) {
            scanf("%d%d%d",&k1,&k2,&k3);
            cap[k1][k2] +=k3;
        }
        printf("%d\n",Edmondes_Karp(1,m) );
    }
    return 0;
}

