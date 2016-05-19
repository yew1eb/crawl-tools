#include <iostream>
#include <algorithm>
using namespace std;
struct EDGE {
    int a, b, len;
    bool operator<(const EDGE t) const {
        return len <t.len;
    }
} edges[100];

int f[30];
int n;
char ch;
int v, u, e;
int find(int u) {
    while(f[u] !=u)
        u= f[u];
    return u;
}
void kruskal() {
    int i, j, sum = 0, num = 0, x, y;
    sort(edges,edges+e);
    for(i=0; i<=n; f[i]=i,i++);
    for(i=0; i<e; i++) {
        x = find(edges[i].a);
        y = find(edges[i].b);
        if(x!=y) {
            sum += edges[i].len;
            f[x] = y;
            if(++num==n-1)
                break;
        }
    }
    cout<<sum<<endl;
}
int main() {
    int i, k,vle, m ;
    while(cin>>n,n) {
        e = 0;
        m = n;
        while(--m) {
            cin>>ch;
            v = ch -'A';
            cin>>k;
            for(i=0; i<k; i++) {
                cin>>ch;
                cin>>vle;
                u = ch- 'A';
                edges[e].a = v;
                edges[e].b = u;
                edges[e].len = vle;
                e++;
            }
        }
        kruskal();
    }
}
