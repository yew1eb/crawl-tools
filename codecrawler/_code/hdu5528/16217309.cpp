//æ²¡å©ç¨ç§¯æ§çæ§è´¨.
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

const int N = 1e5;

ull ans;
int n;
int p[N], tot;
int xp[N], num[N], xpn;
int b[N], bn;
bool flag[N];

int Euler() {
    int tmp;
    tot = 0;
    memset(flag, 0, sizeof(flag));
    for(int i = 2; i < N; ++i) {
        if(!flag[i]) {
            p[tot++] = i;
        }
        for(int j = 0; j < tot && 1ll * i * p[j] < N; ++j) {
            tmp = i * p[j];
            flag[tmp] = true;
            if(i % p[j]) {
                ;
            }
            else {
                break;
            }
        }
    }
}

void yue(int x)
{
    int xx = x;
    xpn = 0;
    ans = 0;
    for(int i = 0;i<tot&&p[i]*p[i]<=x;i++)
    {
        if(x%p[i]==0)
        {
            xp[xpn] = p[i];
            num[xpn] = 0;
            while(x%p[i]==0)
            {
                num[xpn]++;
                x /= p[i];
            }
            xpn++;
            if(x==1)
                break;
        }
    }
    if(x!=1)
    {
        xp[xpn] = x;
        num[xpn] = 1;
        xpn++;
    }
    b[0] = xx;
    bn = 1;
    for(int i = 0;i<xpn;i++)
    {
        int tmpbn = bn;
        int tmp = 1;
        for(int j = 1;j<=num[i];j++)
        {
            tmp *= xp[i];
            for(int k = 0;k<tmpbn;k++)
            {
                b[bn] = b[k]/tmp;
                bn++;
            }

        }
    }

    for (int i = 0;i < bn;i++)
    {
        ull bx = b[i];
        ull nn = n;
        ans += bx * bx;
        ans -= nn;
    }
    printf("%I64u\n",ans);
}

int main() {
 //   freopen("in.txt","r",stdin);
    int T;
    scanf("%d", &T);
    Euler();
    while (T--) {
        scanf("%d",&n);
        yue(n);
    }
    return 0;
}