#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

const int maxn = 2000000 + 10;
int c[maxn], a[maxn];
int lowbit(int x) {return x&(-x); }
void update(int i, int val){for(; i<maxn; i += lowbit(i)) c[i] += val; }
int query(int i){int ret =0;for(; i>0; i -= lowbit(i)) ret += c[i]; return ret; }

int main(){
    int T, n, x;
    scanf("%d", &T);
    for(int ca=1; ca<=T; ++ca){
        memset(c, 0, sizeof c );
        scanf("%d", &n);
        int ans = 0;
        for(int i=n-1; i>=0; --i) scanf("%d", &a[i]);
        for(int i=0; i<n; ++i){
            x = a[i];
            int tmp = query(x-1);
            if(tmp>0) ans++;
            update(x,1);
           }
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}