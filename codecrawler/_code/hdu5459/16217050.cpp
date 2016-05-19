#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-6;
const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MOD = 530600414;
#define ll long long
#define CL(a) memset(a,0,sizeof(a))

ll ans[300000];//ç­æ¡
ll c[300000];//cçä¸ªæ°
ll s[300000];//cçåæ å
ll d[300000];//é¿åº¦

int main()
{
    ans[1]=0; ans[2]=0; ans[3]=1;
    ans[4]=1; c[4]=1; s[4]=3; d[4]=3;
    ans[5]=5; c[5]=2; s[5]=7; d[5]=5;
    ans[6]=16; c[6]=3; s[6]=20; d[6]=8;
    for(int i=7; i<=201314; i++)
    {
        ans[i]=(ans[i-1]+ans[i-2]+(((c[i-2]*d[i-1]-s[i-2])%MOD)*c[i-1])%MOD+(c[i-2]*s[i-1])%MOD)%MOD;
        c[i]=(c[i-1]+c[i-2])%MOD;
        s[i]=(s[i-1]+s[i-2]+c[i-1]*d[i-1])%MOD;//ç¬¬(i-1)ä¸ªå­ç¬¦ä¸²éçcåæ é½è¦å ä¸ç¬¬(i-2)ä¸ªä¸²çé¿åº¦
        d[i]=(d[i-1]+d[i-2])%MOD;
    }

    int T,n;
    scanf ("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        scanf ("%d",&n);
        printf ("Case #%d: ",cas);
        printf ("%lld\n",ans[n]);
    }
    return 0;
}
