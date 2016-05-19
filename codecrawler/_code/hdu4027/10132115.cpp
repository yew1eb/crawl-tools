#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 100100;
typedef long long LL;
LL c[maxn], a[maxn];
int n;
int lowbit(int x) {return x&(-x);}
void update(int i, LL val) {for(; i<=n; i += lowbit(i)) c[i] += val;}
LL getsum(int i) {LL ret = 0; for(; i>0; i -= lowbit(i)) ret += c[i]; return ret; }

int main()
{
    int i, j, m;
    LL x;
    int v, l, r;
    int cas = 1;
    while(~scanf("%d",&n))
    {
        memset(c, 0, sizeof c );
        for(i=1; i<=n; ++i)
        {
            scanf("%I64d", &a[i]);
            update(i, a[i]);
        }
        scanf("%d",&m);
        printf("Case #%d:\n",cas++);
        while(m--)
        {
            scanf("%d%d%d",&v,&l,&r);
            if(l>r) swap(l, r);
            if(v==0)
            {
                if(getsum(r) - getsum(l-1) <= r - l + 1)
                    continue;
                else
                {
                    for(j=l; j<=r; ++j)
                    {
                        if(a[j] <= 1) continue;
                        update(j, -a[j]);
                        a[j] = (LL)sqrt(a[j]);
                        update(j,a[j]);
                    }
                }
            }else
            {
                LL ans = getsum(r) - getsum(l-1);
                printf("%I64d\n",ans);
            }
        }
        printf("\n");
    }
    return 0;
}
