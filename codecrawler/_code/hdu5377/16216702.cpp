#include<iostream>
#pragma comment(linker,"/STACK:1024000000,1024000000")
#include<cstring>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 1;
const int maxv = 1e5 + 1;
bool isnp[maxv];
int prime[maxv], pnum;//ç´ æ°æ»ä¸ªæ°
int cas;
void get_prime()//ç´ æ°ç­
{
    pnum = 0;
    int i, j;
    memset(isnp, 0, sizeof(isnp));
    isnp[0] = isnp[1] = true;
    for (i = 2; i<maxv; i++)
    {
        if (!isnp[i])prime[pnum++] = i;
        for (j = 0; j<pnum&&prime[j] * i<maxv; j++)
        {
            isnp[i*prime[j]] = true;
            if (i%prime[j] == 0)break;
        }
    }
}
ll qukpow(ll k, ll base, ll p)//å¿«éå¹ base^k%p
{
    ll res = 1;
    for (; k; k >>= 1)
    {
        if (k & 1)res = (res*base) % p;
        base = (base*base) % p;
    }
    return res;
}
ll fpr[maxv];//å­å¨p-1çè´¨å å­
ll find_primitive_root(ll p)//æ±åºp-1ææè´¨å å­ï¼æ¾å¥fprï¼è¿åpæå°åæ ¹
{
    ll cnt = 0, num = p - 1, res;
    int i;
    if (p == 2)return 1;
    for (i = 0; i<pnum&&prime[i] * prime[i] <= num&&num>1; i++)//æ±åºp-1ææä¸åçè´¨å å­
    {
        if (num%prime[i] == 0)
        {
            fpr[cnt++] = prime[i];
            while (num%prime[i] == 0)num /= prime[i];
        }
    }
    if (num>1)fpr[cnt++] = num;
    /*æ±åºp-1ææä¸åçè´¨å å­p1,p2...pmï¼å¯¹äºä»»ä½2<=a<=x-1,å¤å®aæ¯å¦ä¸ºxçåæ ¹ï¼åªéè¦æ£éª
    a^((x-1)/p1),a^((x-1)/p2),...a^((x-1)/pm)è¿mä¸ªæ°ä¸­ï¼
    æ¯å¦å­å¨ä¸ä¸ªæ°mod xä¸º1ï¼è¥å­å¨ï¼aä¸æ¯xçåæ ¹ï¼å¦åå°±æ¯xçåæ ¹ã*/
    for (res = 2; res <= p - 1; res++)//æä¸¾åæ ¹
    {
        for (i = 0; i<cnt; i++)
        if (qukpow(p / prime[i], res, p) == 1)break;
        if (i >= cnt)return res;
    }
    return -1;
};
const int mod = 1e6 + 7;
struct solve
{
    struct HashTable
    {
        int top, head[mod];
        struct Node
        {
            int x, y, next;//xæ¯åæ ¹pçå¹ï¼yæ¯å¹æ¬¡æ°ï¼nextæ¯y+1æ¬¡å¹æå¨çheadæ¡¶
        }node[mod];
        void init()
        {
            top = 0;
            memset(head, 0, sizeof(head));
        }
        void insert(ll x, ll y)
        {
            node[top].x = x; node[top].y = y; node[top].next = head[x%mod];
            head[x%mod] = top++;
        }
        ll query(ll x)//æ±åºxæ¯åæ ¹prootçå æ¬¡å¹
        {
            for (int tx = head[x%mod]; tx; tx = node[tx].next)
            if (node[tx].x == x)return node[tx].y;
            return -1;
        }
    }mp;

    ll p;//sumçè´¨å å­
    ll discretelog(ll prt, ll a)//æ±log prt(a)ï¼aæ¯prtçå æ¬¡å¹
    {
        ll res, am = qukpow(maxn - 1, prt, p), inv = qukpow(p - 2, a, p), x = 1;
        for (ll i = maxn - 1;; i += (maxn - 1))
        {
            if ((res = mp.query((x = x*am%p)*inv%p)) != -1)
            {

                return i - res;
            }
            if (i>p)break;
        }
        return -1;
    }
    //æ©å±æ¬§å éå¾·  ax+by=d
    void ex_gcd(long long a, long long b, long long &d, long long &x, long long &y)
    {
        if (!b){ d = a; x = 1; y = 0; }
        else { ex_gcd(b, a%b, d, y, x); y -= x*(a / b); }
    }
    ll proot;//è´¨å å­pçåæ ¹
    void init()
    {
        mp.init();
        ll tmp, x, y, d;
        int i;
        proot = find_primitive_root(p);//proot è´¨å å­pçåæ ¹
        for (i = 0, tmp = 1; i<maxn - 1; i++, tmp = tmp*proot%p)mp.insert(tmp%p, i * 1ll);//åæ ¹pçå¹ï¼å¹æ¬¡æ°
    }
    ll query(ll x, ll y)
    {
        ll d;
        x %= p;
        y %= p;
        if (y == 1)return 0; //x^k==1,k=0
        else if (x == 0)
        {
            if (y == 0)return 1;//0^k==0,k=1;
            else return -1;//0^k==-1,kæ è§£
        }
        else if (y == 0)return -1; //x^k==0,x!=0,kæ è§£
        else
        {
            ll s = discretelog(proot, x);//ä»¤s=logd(x),
            ll t = discretelog(proot, y);//t=logd(y),
            ex_gcd(s, p - 1, d, x, y);//ç±æ¬§å éå¾æ©å±å®çæ±åºkåm ,kks+m(p-1)=gcd(s,p-1)=D
            if (t%d)return -1;//tå¿é¡»ä¸ºgcd(s,p-1)çåæ°ææè§£
            else
            {//å¼å­ä¸¤è¾¹ä¹ä»¥t/Dæ¢å¤åå¼ ï¼kk*s*t/D+m(p-1)*t/D==D*t/D
                //æä»¥æåç»æå°±æ¯k = kk*t / D.
                ll dx = (p - 1) / d;
                x = (x%dx + dx) % dx;
                x *= (t / d);
                x = (x%dx + dx) % dx;
                return x;
            }
        }
    }
}sol[32];//sol[i]è¡¨ç¤ºsumç¬¬iä¸ªè´¨å å­ï¼æ±åºå¶å¯¹åºçåæ ¹ï¼å¹¶æ£éª
int main()
{
    int i, j, q, con, T;
    ll sum, x, y;
    scanf("%d", &T);
    get_prime();
    for (cas = 1; cas <= T; cas++)
    {
        con = 0;//sumè´¨å å­ä¸ªæ°
        scanf("%I64d %d", &sum, &q);
        for (i = 0; i<pnum&&prime[i] * prime[i] <= sum&&sum != 1; i++)
        {
            if (sum%prime[i] == 0)
            {
                sol[con].p = prime[i];//ç­åºsumçè´¨å å­
                sol[con].init();
                con++;
                while (sum%prime[i] == 0)sum /= prime[i];
            }
        }
        if (sum>1)
        {
            sol[con].p = sum;
            sol[con].init();
            con++;
        }
        printf("Case #%d:\n", cas);
        for (i = 0; i<q; i++)
        {
            scanf("%lld %lld", &x, &y);
            ll res = 1e18, tmp;
            for (j = 0; j<con; j++)
            {
                tmp = sol[j].query(x, y);
                if (tmp != -1)res = min(res, tmp);
            }
            if (res == 1e18)res = -1;
            printf("%I64d\n", res);
        }
    }
    return 0;
}