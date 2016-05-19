#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1009;
int nn;
int a[N],b[N];
int h[N * 2];
struct BIT{
    int c[2*N];
    int lowbit(int x){return x & -x;}
    void update(int x, int k){
        while(x <= nn){
            c[x] = max(c[x], k);
            x += lowbit(x);
        }
    }
    int query(int x){
        int ret = 0;
        while(x > 0){
            ret = max(ret ,c[x]);
            x -= lowbit(x);
        }
        return ret;
    }
}t[N];
int main(){
    int T;scanf("%d", &T);
    while(T--){
        int m, n;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++){
            scanf("%d%d", &a[i], &b[i]);
            h[i] = a[i]; h[i+n] = b[i];
        }
        sort(h, h + 2 * n);
        nn = unique(h, h + 2 * n) - h;
        for(int i = 0; i < n; i++){
            a[i] = lower_bound(h, h + nn, a[i]) - h + 1;
            b[i] = lower_bound(h, h + nn, b[i]) - h + 1;
        }
        int ma = 1;
        memset(t, 0, sizeof(t));
        for(int i = 0; i < n; i++){
            for(int j = m; j >= 0; j--){
                int x1 = t[j].query(a[i] - 1) + 1;
                if(x1 > ma) ma = x1;
                t[j].update(a[i], x1);
                if(j > 0){
                    int x2 = t[j-1].query(b[i] - 1) + 1;
                    if(x2 > ma) ma = x2;
                    t[j].update(b[i], x2);
                }
            }
        }
        printf("%d\n", ma);
    }
    return 0;
}
