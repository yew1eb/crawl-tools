#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int const MAX = 1e5 + 5;
int  L, n, k;
ll x[MAX], disl[MAX], disr[MAX];
vector <ll> l, r;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        memset(disl, 0, sizeof(disl));
        memset(disr, 0, sizeof(disr));
        l.clear();
        r.clear();
        scanf("%d %d %d", &L, &n, &k);
        int cnt = 1;
        for(int i = 1; i <= n; i++) 
        {
            ll pos, num;
            scanf("%lld %lld", &pos, &num);
            for(int j = 1; j <= num; j++)
                x[cnt ++] = (ll) pos;   //ç¦»æ£æä½
        }
        cnt --;
        for(int i = 1; i <= cnt; i++)
        {
            if(2 * x[i] < L)
                l.push_back(x[i]);
            else
                r.push_back(L - x[i]);  //è®°å½ä½ç½®
        }   
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());
        int szl = l.size(), szr = r.size();
        for(int i = 0; i < szl; i++)
            disl[i + 1] = (i + 1 <= k ? l[i] : disl[i + 1 - k] + l[i]);
        for(int i = 0; i < szr; i++)
            disr[i + 1] = (i + 1 <= k ? r[i] : disr[i + 1 - k] + r[i]);
        ll ans = (disl[szl] + disr[szr]) * 2;
        for(int i = 0; i <= szl && i <= k; i++)
        {
            int p1 = szl - i;
            int p2 = max(0, szr - (k - i));
            ans = min(ans, 2 * (disl[p1] + disr[p2]) + L);
        }
        printf("%I64d\n", ans);
    }
}

