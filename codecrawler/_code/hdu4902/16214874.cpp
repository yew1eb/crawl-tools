#include<cstdio>
#include<stack>
using namespace std;
typedef __int64 LL;
const int N = 1e5 + 10;
struct opertion
{
    int t, l, r;
    LL x;
}o[N];
LL a[N];
LL gcd(LL x, LL y)
{
    while(y) {
        LL r = x % y;
        x = y;
        y = r;
    }
    return x;
}
int main()
{
    int T, n, i, j, Q;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(i = 1; i <= n; i++)
            scanf("%I64d",&a[i]);
        scanf("%d",&Q);
        for(i = 0; i < Q; i++)
            scanf("%d%d%d%I64d",&o[i].t, &o[i].l, &o[i].r, &o[i].x);
        for(i = 1; i <= n; i++) {
            stack<LL> s;
            int flag = 0;
            for(j = Q - 1; j >= 0; j--) {
                if(i >= o[j].l && i <= o[j].r) {
                        s.push(o[j].x);
                        if(o[j].t == 1) {
                            flag = 1;
                            break;
                        }
                }
            }
            if(!flag)  //æ²¡æéå°1æä½
                s.push(a[i]);
            while(s.size() > 1) {
                LL ans = s.top(); s.pop();
                LL tmp = s.top(); s.pop();
                if(ans > tmp)
                    ans = gcd(ans, tmp);
                s.push(ans);
            }
            printf("%I64d ", s.top());
        }
        printf("\n");
    }
    return 0;
}