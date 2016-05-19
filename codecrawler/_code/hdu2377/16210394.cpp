/*
ID: j.sure.1
PROG:
LANG: C++
*/
/****************************************/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;
/****************************************/
int n, bus;
const int MAXE = 200005, MAXN = 10000;
bool inq[MAXN];
int dis[MAXN], node[MAXN], maxd[MAXN], head[MAXN], id[MAXN];
struct Edge
{
    int u, v;
    int next;
} edge[MAXE];
int cnt;

void init()
{
    memset(head, -1, sizeof(head));
    cnt = 0;
    memset(maxd, 0, sizeof(maxd));
}

void add(int u, int v)
{
    edge[cnt].u = u;
    edge[cnt].v = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void spfa(int st)
{
    memset(inq, 0, sizeof(inq));
    memset(dis, 0x7f, sizeof(dis));
    queue <int> q;
    q.push(st);
    dis[st] = 0;
    inq[st] = true;
    int tmp;
    while(!q.empty()) {
        tmp = q.front(); q.pop();
        inq[tmp] = false;
        for(int i = head[tmp]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            if(dis[v] > dis[tmp] + 1) {
                dis[v] = dis[tmp] + 1;
                if(!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("2377.in", "r", stdin);
    freopen("2377.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for(int cas = 0; cas < T; cas++) {
        scanf("%d%d", &n, &bus);
        int adj;
        init();
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &id[i], &adj);
            int v;
            while(adj--) {
                scanf("%d", &v);
                add(id[i], v);
                //add(v, id[i]);//å ä¸ºæ°æ®é½å¨æä»¥ä¸éè¦
            }
        }
        while(bus--) {
            int stop;
            scanf("%d", &stop);
            while(stop--) {
                int st;
                scanf("%d", &st);
                spfa(st);
                for(int i = 0; i < n; i++) {
                    if(dis[id[i]] > maxd[id[i]]) {
                        maxd[id[i]] = dis[id[i]];
                    }
                }
            }
        }
        //å¦æå­å¨å¤ä¸ªè§£ æ¾å°ç¼å·æå°ç
        int ans = 2e9, ans_id;
        sort(id, id+n);
        for(int i = 0; i < n; i++) if(ans > maxd[id[i]]) {
            ans = maxd[id[i]];
            ans_id = id[i];
        }
        printf("%d %d\n", ans+1, ans_id);
    }
    return 0;
}
