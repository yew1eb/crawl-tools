#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const int maxn = 1000+5;
int T,n,m,X,Y,d[maxn][maxn], dd[maxn][maxn], maxdist, ans;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
struct node {
    int x, y, dist;
    node(int xx=0, int yy=0, int dd=0):x(xx), y(yy), dist(dd) {}
    bool operator < (const node& rhs) const {
        return dist < rhs.dist;
    }
}S,t,a[maxn*10];
void BFS1() {
    queue<node> q;
    maxdist = 0;
    for(int i=0;i<X;i++) 
        for(int j=0;j<Y;j++) d[i][j] = -1;
    for(int i=0;i<n;i++) {
       d[a[i].x][a[i].y] = 0;
       q.push(node(a[i].x,a[i].y,0));
    }
    while(!q.empty()) {
        node u = q.front(); q.pop();
        for(int i=0;i<4;i++) {
            node v = u;
            v.x = v.x + dx[i]; v.y = v.y + dy[i];
            v.dist++;
            if(v.x < 0 || v.x >= X || v.y < 0 || v.y >= Y) continue;
            if(d[v.x][v.y] == -1) {
                d[v.x][v.y] = v.dist;
                maxdist = max(maxdist, v.dist);
                q.push(v);
            }
        }
    }
}
bool BFS(int dist) {
    queue<node> q;
    if(d[S.x][S.y] < dist) return false;
    memset(dd,-1,sizeof(dd));
    dd[S.x][S.y] = 0;
    q.push(S);
    while(!q.empty()) {
        node u = q.front(); q.pop();
        if(u.x == t.x && u.y == t.y) {
            ans = dd[u.x][u.y];
            return true;
        }
        for(int i=0;i<4;i++) {
            node v = u;
            v.x += dx[i]; v.y += dy[i];
            if(v.x < 0 || v.x >= X || v.y < 0 || v.y >= Y) continue;
            v.dist = min(v.dist, d[v.x][v.y]);
            if(dd[v.x][v.y] == -1 && v.dist >= dist) {
                dd[v.x][v.y] = dd[u.x][u.y] + 1;
                q.push(v);
            }
        }
    }
    return false;
}
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&n,&X,&Y);
        scanf("%d%d%d%d",&S.x,&S.y,&t.x,&t.y);
        for(int i=0;i<n;i++) {
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        BFS1();
        S.dist = d[S.x][S.y];
        int l = 0, r = maxdist+10, m;
        while(r > l) {
            m = (r+l)/2;
            if(BFS(m)) l = m + 1;
            else r = m;
        }
        if(!BFS(m)) m--;
        printf("%d %d\n",m,ans);
    }
    return 0;
}
