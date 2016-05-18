#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

const int inf = 1<<30;
const int maxn = 1010;
struct Edge {

    int to, w;
};

struct node {

    int v,dist;
    int mark;
    bool friend operator < (const node &a, const node &b) {

         if(a.dist != b.dist)
            return a.dist > b.dist;
         return a.v > b.v;
    }
};

priority_queue<node>Q;
vector<Edge>gra[maxn*10];
int dp[maxn][3];
int vis[maxn][3];
int dis[maxn][3];
int T,N,M,A,B,L;

void init() {

    for(int i = 0; i < maxn; i++) {

        dp[i][1] = dp[i][2] = 0;
        vis[i][1] = vis[i][2] = 0;
        dis[i][1] = dis[i][2] = inf;
    }
}

void Dijstra(int st, int ed) {


    dis[st][1] = 0;
    dp[st][1]= 1;
    node q, p;
    p.dist = 0;
    p.mark = 1;
    p.v = st;
    Q.push(p);
    while(!Q.empty()) {

        q = Q.top();
        Q.pop();
        if(vis[q.v][q.mark])
            continue;
        vis[q.v][q.mark] = 1;
        for(int i = 0; i < gra[q.v].size(); i++){

            int vv = gra[q.v][i].to;
            int ww = gra[q.v][i].w;
            if(!vis[vv][1] && dis[vv][1] > q.dist + ww) {

                if(dis[vv][1] != inf) {

                    dis[vv][2] = dis[vv][1];
                    dp[vv][2] = dp[vv][1];
                    p.dist = dis[vv][2];
                    p.mark = 2;
                    p.v = vv;
                    Q.push(p);
                }
                dis[vv][1] = q.dist + ww;
                dp[vv][1] = dp[q.v][q.mark];
                p.mark = 1;
                p.dist = dis[vv][1];
                p.v = vv;
                Q.push(p);
            }
            else if(!vis[vv][1]&& dis[vv][1]== q.dist + ww)
            {
                dp[vv][1] += dp[q.v][q.mark];
            }
            else if(!vis[vv][2] && dis[vv][2] > q.dist + ww) {

                dis[vv][2] = q.dist + ww;
                dp[vv][2] = dp[q.v][q.mark];
                p.mark = 2;
                p.dist = dis[vv][2];
                p.v = vv;
                Q.push(p);

            }
            else if(!vis[vv][2] && dis[vv][2] == q.dist + ww)
            {

                dp[vv][2] += dp[q.v][q.mark];
            }
        }
    }
}

int main()
{
    scanf("%d", &T);
    Edge tem;
    int st, ed;
    while(T--) {

        init();
        for(int i = 0; i < maxn*10; i++) {

            gra[i].clear();
        }
        scanf("%d%d", &N, &M);
        for(int i = 0; i < M; i++) {
        scanf("%d%d%d", &A, &B, &L);
            tem.to = B;
            tem.w = L;
            gra[A].push_back(tem);
        }
        scanf("%d%d", &st, &ed);
        Dijstra(st, ed);
        if(dis[ed][1] + 1 == dis[ed][2])
            printf("%d\n", dp[ed][1] + dp[ed][2]);
        else
            printf("%d\n", dp[ed][1]);
    }
    return 0;
}