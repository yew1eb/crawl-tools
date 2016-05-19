#include<iostream>
#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define B(x) (1<<(x))
typedef __int64 ll;
typedef unsigned __int64 Ull;
const int oo=0x3f3f3f3f;
const ll OO=1LL<<61;
const Ull MOD=1000000;
const int maxn=20;
ll dp[maxn][10];
int bit[maxn];

ll dfs(int pos,int pre,int f,int z)
{
    if(pos<1) return 1;
    if(z==0&&!f&&dp[pos][pre]!=-1) return dp[pos][pre];
    int last= f ? bit[pos] : 9;
    ll res=0;
    for(int i=0;i<=last;i++)
    {
        if(z==0||(pre>=i&&i!=0&&pre%i==0))
            res+=dfs(pos-1,i,f&&i==last,z||i);
    }
    if(!f&&z==0) dp[pos][pre]=res;
    return res;
}

ll Cnt(int n)
{
    int len=0;
    while(n)
    {
        bit[++len]=n%10;
        n/=10;
    }
    return dfs(len,0,1,0);
}

int main()
{
    int L,R,T;
    memset(dp,-1,sizeof dp);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&L,&R);
        printf("%I64d\n",Cnt(R)-Cnt(L-1));
    }
    return 0;
}
/*
4 3
AT
AC
AG
AA

*/



