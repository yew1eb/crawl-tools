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
typedef unsigned int uint;
const int N = 10000003;
struct P
{
    uint l, r;
    bool operator < (P b) const {
        return r < b.r;
    }
} p[N];
uint n, l1, r1, a, b, c, d;
int main()
{
    int re, ca=1; cin>>re;
    while (re--) {
        cin>>n>>l1>>r1>>a>>b>>c>>d;
        p[1].l = l1; p[1].r = r1;
        for (int i=2;i<=n;i++)
        {
            p[i].l = (p[i-1].l * a + b) ;
            p[i].r = (p[i-1].r * c + d);
        }
        for (int i=1;i<=n;i++) if (p[i].l > p[i].r) swap(p[i].l, p[i].r);
        sort(p+1, p+n+1);
        uint L, R;
        int cnt = 0;
        cnt = 1;
        int last = 1;
        while (cnt <3)  {
            bool ok = false;
            for (int i = last + 1 ; i<=n  ; i++)
            {
                if (p[last].r < p[i].l)
                {
                    ok = true;
                    last = i;
                    break;
                }
            }
            if (!ok) break;
            else cnt++;
        }
        if (cnt >= 3) puts("YES");
        else puts("NO");
    }
    return 0;
}
