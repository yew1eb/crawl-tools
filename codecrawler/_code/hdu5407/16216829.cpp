#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
using namespace std;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

typedef long long LL;
const double pi=4.0*atan(1.0);
const int M=1000000007;
const int MAXN=1000005;
int prime[MAXN];
LL a[MAXN];

void getprime()
{
    int i;
    for(i=1;i<MAXN;i++)
        prime[i]=i;

    for(i=2;i<MAXN;i++)
        if(prime[i]==i)
            for(int j=i+i;j<MAXN;j+=i)
                prime[j]=i;
}
LL quick_mod(LL a,int b,LL m)
{
    LL ans=1;
    while(b)
    {
        if(b&1)
            ans=ans*a%m;
        b>>=1;
        a=a*a%m;
    }
    return ans;
}
int check(int k)
{
    int t=prime[k];
    while(k%t==0&&k>1)
        k/=t;
    return k==1;
}

int main()
{

    int T;
    int n,k;
    int i,j;
    getprime();
    a[1]=1;
    for(i=2;i<MAXN;i++)
    {
        if(check(i))
            a[i]=a[i-1]*prime[i]%M;
        else
            a[i]=a[i-1];
    }

    while(scanf("%d",&T)!=EOF)
    {
        while(T--)
        {
            scanf("%d",&n);
            n++;
            printf("%I64d\n",a[n]*quick_mod(n,M-2,M)%M);

        }
    }
    return 0;
}