#include <cstdio>
#include <stack>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <functional>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <iomanip>
#include <cmath>
#define LL long long
#define ULL unsigned long long
#define SZ(x) (int)x.size()
#define Lowbit(x) ((x) & (-x))
#define MP(a, b) make_pair(a, b)
#define MS(arr, num) memset(arr, num, sizeof(arr))
#define PB push_back
#define F first
#define S second
#define ROP freopen("input.txt", "r", stdin);
#define MID(a, b) (a + ((b - a) >> 1))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lrt rt << 1
#define rrt rt << 1|1
#define root 1,n,1
#define BitCount(x) __builtin_popcount(x)
#define BitCountll(x) __builtin_popcountll(x)
#define LeftPos(x) 32 - __builtin_clz(x) - 1
#define LeftPosll(x) 64 - __builtin_clzll(x) - 1
const double PI = acos(-1.0);
const LL INF = (((LL)1)<<62)+1;
using namespace std;
const double eps = 1e-5;
const int MAXN = 300 + 10;
const int MOD = 1000007;
const double M=1e-8;
const int N=100005;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
int n,m,a[N],d1,d2;
LL q[N] , d[N];
inline LL get(LL x)
{
    x+=1;
    return x*(x-1)>>1;
}
int main()
{
    int i,j;
    while(~scanf("%d%d%d",&n,&d1,&d2))
    {
        int t;
        LL ans=n;
        scanf("%d",a);
        for (i=1;i<n;i++) {
            scanf("%d",a+i);
            q[i]=a[i]-a[i-1];
        }
        if (n<=1) {
            puts("1");
            continue;
        }
        int k=0;
        LL cnt1=0,cnt2=0;
        for (i=1;i<n;i++) {
            if (q[i]==d1) {
                if (cnt2) {
                    ans+=get(cnt1)+get(cnt2)+cnt1*cnt2;
                    cnt1=cnt2=0;
                }
                cnt1++;
            }
            else if (q[i]==d2) cnt2++;
            else {
                ans+=get(cnt1)+get(cnt2)+cnt1*cnt2;
                cnt1=cnt2=0;
            }
        }
        ans+=get(cnt1)+get(cnt2)+cnt1*cnt2;
        printf("%lld\n",ans);
    }
}






















