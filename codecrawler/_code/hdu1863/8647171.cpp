#include <iostream>
#include <algorithm>
#include <cstring>
#define N 105
using namespace std;
struct node {
    int a, b;
    int len;
    bool operator <(const node& x) const {
        return len <x.len;
    }
} edges[N*N];

int f[N];
int find(int x) {
    while(x!=f[x])
        x=f[x];
    return x;
}
int main() {
    int m, n, i, x, y, ans,cnt;
    node tmp;
    while(cin>>m>>n,m) {
        for(i=0; i<=n; f[i]=i, i++);
        for(i=0; i<m; i++)
            cin>>edges[i].a>>edges[i].b>>edges[i].len;
        sort(edges,edges+m);
        ans = cnt = 0;
        for(i=0; i<m; i++) {
            node& e = edges[i];
            x = find(e.a);
            y = find(e.b);
            if(x!=y) {
                f[x] = y;
                ans += e.len;
                if(++cnt==n-1) break;
            }
        }
        if(cnt==n-1) cout<<ans<<endl;
        else cout<<'?'<<endl;
    }
    return 0;
}








