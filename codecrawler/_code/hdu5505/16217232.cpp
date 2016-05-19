#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<stdio.h>
#include<string.h>
#include<queue>
#include<stack>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<stdlib.h>
#include<cmath>
#include<string>
#include<algorithm>
#include<iostream>
#define exp 1e-10
using namespace std;
const int N = 1000000;
const int inf = 1000000000;
const int mod = 2009;
__int64 gcd(__int64 a,__int64 b)
{
    if(a%b)
        return gcd(b,a%b);
    return b;
}
int main()
{
    int t,i,k,ans;
    __int64 n,m;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%I64d%I64d",&n,&m);
        while(n!=m)
        {
            if(m%n)
            {
                puts("-1");
                break;
            }
            k=gcd(m/n,n);
            if(k==1)
            {
                puts("-1");
                break;
            }
            n*=k;
            ans++;
        }
        if(n==m)
            printf("%d\n",ans);
    }
    return 0;
}