#include <bits/stdc++.h>
using namespace std;
#define prt(k) cerr<<#k" = "<<k<<endl
#define pb push_back
#define MP make_pair
#define fi  first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)
#define SZ(X) ((int)(v).size())
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define READ freopen("a.in","r",stdin);freopen("a.out","w",stdout)
void read(string t)
{
    freopen((t+".in").c_str(),"r",stdin);
    freopen((t+".out").c_str(),"w",stdout);
}
const int inf = 0x3f3f3f3f;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef pair<int,int> pii;
template <class T>
void Max(T &a, T b) { a=max(a, b); }
const int N = 2333;
ll a[N];
ll gcd(ll a, ll b)
{
    return b==0 ? a : gcd(b, a%b);
}
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}
int n, Q;
struct P
{
    int l, r, a;
} q[N];
int main()
{
    int re,ca=1; cin>>re;
    while (re--) {
        cin>>n>>Q;
        for (int i=1;i<=n;i++) a[i] = 1;
        for (int i=0;i<Q;i++) {
            scanf("%d%d%d", &q[i].l, &q[i].r, &q[i].a);
            int l=q[i].l, r = q[i].r;
            for (int j = l; j <= r; j++) {
                                a[j] = lcm(a[j], q[i].a);

            }
        }
        bool ok = true;

        for (int i=0;i<Q;i++) {
            int l=q[i].l, r = q[i].r;
            ll g = a[l];
            for (int j=l+1;j<=r;j++) g = gcd(g, a[j]);

            if (g != q[i].a) ok = false;
        }
        if (!ok) {
            puts("Stupid BrotherK!");
            continue;
        }
        for (int i=1;i<=n;i++) {
            printf("%I64d%c", a[i], i<n ? ' ' : 10);
        }
    }
    return 0;
}
