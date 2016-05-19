#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL __int64
const LL maxn=44;
LL dp[maxn]={0,1,1,2,4,9,20,48,115,286,719,1842,4766,12486,32973,87811,235381,634847,1721159,4688676,
                12826228,35221832,97055181,268282855,743724984,2067174645,5759636510,16083734329,
                45007066269,126186554308,354426847597,997171512998,2809934352700,7929819784355,
                22409533673568,63411730258053,179655930440464,509588049810620,1447023384581029,
                4113254119923150,11703780079612453};//可以直接打表了。。
LL e[maxn],t,s;
LL C(LL n,LL m)//求组合数
{
    m=min(m,n-m);
    LL i,s=1;
    for(i=1;i<=m;i++)
        s=s*(n-i+1)/i;
    return s;
}
void dfs(LL a,LL step,LL num,LL sum)
{
    LL i,j,k;
    if(sum>num)return;
    if(sum==num)
    {
        LL s=1;
        k=1;
        for(i=1;i<step;i++)
        {
            if(e[i]!=e[i-1])
            {
                s*=C(dp[e[i-1]]+k-1,k);
                k=0;
            }
            k++;
        }
        s*=C(dp[e[step-1]]+k-1,k);
        dp[num+1]+=s;
        return;
    }
    for(i=a;i<=num;i++)
    {
        e[step]=i;
        dfs(i,step+1,num,sum+i);
    }
}
void init()
{
    dp[1]=dp[2]=1;
    LL i,j,k;
    for(i=3;i<=40;i++)
    {
        dp[i]=0;
        dfs(1,0,i-1,0);
    }
}
int main()
{
    init();
    LL n;
    while(cin>>n)
    {
        cout<<dp[n]<<endl;
    }
    return 0;
}
/*
    可重复选择的组合。有n个元素，每个元素可以选多次，一共选k个袁术，有多少种选择？
    n=3,k=2,有6种:(1,1),(1,2),(1,3),(2,2),(2,3),(3,3)
    共 C(k+n-1,n-1)=C(n+k-1,k)种

    本题，求n个结点数的树有多少种，可采用整数划分n-1的方法
    n=5时，划分4=1+1+1+1=1+1+2=1+3=2+2=4。
    则dp[5]=C(dp[1]+4-1,4)+C(dp[1]+2-1,2)*dp[2]+dp[1]*dp[3]+dp[2]*dp[2]+dp[4]=9;

*/