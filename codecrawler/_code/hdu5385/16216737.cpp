//#include <bits/stdc++.h>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <time.h>
#include <vector>
#include <cstdio>
#include <string>
#include <iomanip>
///cout << fixed << setprecision(13) << (double) x << endl;
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1
#define pi acos(-1.0)
#define eps 1e-8
#define Mp(a, b) make_pair(a, b)
#define asd puts("asdasdasdasdasdf");
#pragma comment(linker, "/STACK:102400000,102400000")
typedef long long ll;
typedef pair <int, int> pl;
//typedef __int64 LL;
const int inf = 0x3f3f3f3f;
const int N = 100010;

struct node{
    int v, nxt, id;
}e[N<<1];

struct E{
    int u, v;
}A[N];

int head[N];
int n, m, cnt;
int ans[N], dis[N];
bool vis[N];

void init()
{
    cnt = 0;
    memset( head, -1, sizeof( head ) );
    memset( vis, 0, sizeof( vis ) );
    memset( ans, 0, sizeof( ans ) );
}

void add( int u, int v, int id )
{
    e[cnt].v = v;
    e[cnt].id = id;
    e[cnt].nxt = head[u];
    head[u] = cnt++;
}

int main()
{
    int tot;
    for( scanf("%d", &tot); tot--; ) {
        scanf("%d%d", &n, &m);
        init();
        for( int i = 1, u, v; i <= m; ++i ) {
            scanf("%d%d", &u, &v);
            add( u, v, i );
            A[i].u = u, A[i].v = v;
        }
        int l = 1, r = n, t = 0;
        vis[l] = 1;
        while( l <= r ) {
            if( vis[l] ) {
                dis[l] = ++t;
                for( int i = head[l]; ~i; i = e[i].nxt ) {
                    int v = e[i].v;
                    if( !vis[v] ) {
                        vis[v] = 1;
                        ans[e[i].id] = 1;
                    }
                }
                l++;
            }
            if( vis[r] ) {
                dis[r] = ++t;
                for( int i = head[r]; ~i; i = e[i].nxt ) {
                    int v = e[i].v;
                    if( !vis[v] ) {
                        vis[v] = 1;
                        ans[e[i].id] = 1;
                    }
                }
                r--;
            }
        }
        for( int i = 1; i <= m; ++i ) {
            if( ans[i] )
                printf("%d\n", abs( dis[A[i].u] - dis[A[i].v] ) );
            else
                printf("%d\n", n);
        }
    }
    return 0;
}
