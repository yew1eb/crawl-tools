#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define prt(k) cout<<#k" = "<<k<<endl;
typedef long long ll;
#include <algorithm>

const ll mod = 1e9 + 7;
const int N = 52;
ll S[N];
int DP[N][8];
int n,m ;
int i, j, k;
int g( ll s)
{
    int ret = 0;
    if (s >> i & 1) ret ^= 1;
    if (s >> j & 1) ret ^= 2;
    if (s >> k & 1) ret ^= 4;
    return ret;
}
void add(int &a, int b) { a=(a+b)%mod; }
int main()
{
    int re; int ca=1;
    cin>>re;
    while (re--)
    {
        cin>>n>>m;
        for (int i=0;i<m;i++)
        {
            ll t = 0;
            int k; cin>>k;
            while (k--)
            {
                int x ;scanf("%d", &x);
                x--;
                t |= (1ll<<x);
            }
            S[i] = t;
        }
        int ans = 0;
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                for (k=0;k<n;k++)
                {
                    memset(DP, 0, sizeof DP);
                    DP[0][0] = 1;
                    for (int t=0;t<m;t++)
                    {
                        int s = g(S[t]);
                        for (int x=0;x<8;x++)
                        {
                            add(DP[t+1][x^s], DP[t][x]);
                            add(DP[t+1][x], DP[t][x]);
                        }
                    }
                    add(ans, DP[m][7]);
                }
            }
        }
        printf("Case #%d: %d\n", ca++, ans);
    }
    return 0;
}
