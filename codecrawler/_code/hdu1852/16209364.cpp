#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <iterator>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

typedef long long LL;
const int N=52;
const LL II=29;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);

LL love(LL a,LL b,LL c)
{
    LL ans=1;
    while(b)
    {
        if(b&1) ans=(ans*a)%c;
        a=(a*a)%c;
        b=b>>1;
    }
    return ans%c;
}

int main()
{
    int i,j,T;
    LL n,k,t;
    while(scanf("%I64d%I64d",&n,&k)&&(n+k))
    {
        k=k*250;
        t=(love(2,3*n+1,k)-1)*(love(251,n+1,k)-1);
        t=(t%k+k)%k/250;

        k/=250;
        printf("%I64d\n",love(2008,t,k));
    }
    return 0;
}
/*
1 10000
0 0
*/
