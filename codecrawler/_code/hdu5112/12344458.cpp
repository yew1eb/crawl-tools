#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 20000;
struct node{
    int t, x;
    bool operator <(const node & rhs)const{
        return t<rhs.t;
    }
};
node a[maxn];

int main(){
    int T, n;
    scanf("%d", &T);
    for(int ca=1; ca<=T; ++ca){
        scanf("%d", &n);
        for(int i=0; i<n; ++i) scanf("%d%d", &a[i].t, &a[i].x);
        sort(a,a+n);
        double ans =  0;
        for(int i=1; i<n; ++i){
            double tt =a[i].t - a[i-1].t;
            double xx =a[i].x - a[i-1].x;
            ans = max(ans, (double)abs(xx/tt));
        }
        printf("Case #%d: %.2f\n", ca, ans);
    }
    return 0;
}