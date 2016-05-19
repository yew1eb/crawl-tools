#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <bitset>
#include <algorithm>
#include <climits>
using namespace std;

#define ls 2*i
#define rs 2*i+1
#define UP(i,x,y) for(i=x;i<=y;i++)
#define DOWN(i,x,y) for(i=x;i>=y;i--)
#define MEM(a,x) memset(a,x,sizeof(a))
#define W(a) while(a)
#define gcd(a,b) __gcd(a,b)
#define LL long long
#define N 1005
#define INF 0x3f3f3f3f
#define EXP 1e-8
#define rank rank1
const int mod = 1000000007;
LL ppow(LL a,LL b)
{
    LL c=1;
    while(b)
    {
        if(b&1) c=c*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return c;
}
int main()
{
    int t;
    LL n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        printf("%I64d\n",ppow(2,n-1)-1);
    }

    return 0;
}