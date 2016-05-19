#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#define N 100 + 5
using namespace std;
int f[N];
int n;
int map[N][N];
struct node {
    int v, u, len;
    bool operator < (const node & t)const {
        return len > t.len;
    }
};
int find(int u) {
    while(f[u] != u) {
        u = f[u];
    }
    return u;
}
priority_queue<node> q;
void kruskal() {
    int ans = 0, i, num = 0, x, y;
    node now;
    for(i=0; i<=n; f[i] = i,i++);
    while(!q.empty()) {
        now = q.top();
        q.pop();
        x = now.v;
        y = now.u;
        x = find(x);
        y = find(y);
        if(x != y) {
            f[x] = y;
            ans += now.len;
            if(++num==n-1) break;
        }
    }
    printf("%d\n",ans);
}
int main() {
    int i, j, t;
    while(cin>>n){
    for(i=0; i<n; i++)
        for(j=0; j<n; j++) {
            cin>>map[i][j];
        }
    cin>>t;
    while(t--) {
        cin>>i>>j;
        map[i-1][j-1]  = 0;
    }
    while(!q.empty()) q.pop();
    node tmp;
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++) {
            tmp.v = i;
            tmp.u = j;
            tmp.len = map[i][j];
            q.push(tmp);
        }

    kruskal();
    }
    return 0;
}
