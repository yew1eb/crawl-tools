#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
int const MAX = 10005;
int const MOD = 10007;
int mob[MAX], p[MAX], num[MAX], cnt[MAX]; //numè¡¨ç¤ºiçåæ°çä¸ªæ°ï¼cntè¡¨ç¤ºiçä¸ªæ°
bool noprime[MAX];
int ma, n;

void Mobius()
{
    int pnum = 0;
    mob[1] = 1;
    for(int i = 2; i < MAX; i++)
    {
        if(!noprime[i])
        {
            p[pnum ++] = i;
            mob[i] = -1;
        }
        for(int j = 0; j < pnum && i * p[j] < MAX; j++)
        {
            noprime[i * p[j]] = true;
            if(i % p[j] == 0)
            {
                mob[i * p[j]] = 0;
                break;
            }
            mob[i * p[j]] = -mob[i];
        }
    }
}   

int cal()
{
    memset(num, 0, sizeof(num));
    for(int i = 1; i <= ma; i++)
        for(int j = i; j <= ma; j += i)
            num[i] += cnt[j];
    ll ans = 0;
    for(int i = 1; i <= ma; i++)
    {
        for(int j = i; j <= ma; j += i)
        {
            ll tmp = (ll) (num[j] * num[j] % MOD); //jçåæ°çäºåç»æ°
            ans = (ans % MOD + (ll) mob[j / i] * tmp * i * (i - 1) % MOD + MOD) % MOD; //å®¹æ¥
        }
    }
    return ans;
}

int main()
{
    Mobius();
    while(scanf("%d", &n) != EOF)
    {
        memset(cnt, 0, sizeof(cnt));
        int tmp;
        ma = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            cnt[tmp] ++;
            ma = max(ma, tmp);
        }
        printf("%d\n", cal());
    }
}