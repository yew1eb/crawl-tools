#include<iostream>
#include<cstdlib>
#include<stdio.h>
#define ll __int64
using namespace std;
const int N=1000;
int prime[N]={0},num=1;
int isprime[N]={1,1};
ll dp[200][1010];
void sushu()
{
    for(int i=2;i<N;i++)
    {
        if(!isprime[i])
        prime[num++]=i;
        for(int j=1;j<num&&i*prime[j]<N;j++)
        {
            isprime[i*prime[j]]=1;
            if(!(i%prime[j]))
            break;
        }
    }
}
int main()
{
    sushu();
    //cout<<num<<endl;
    dp[0][0]=1;
    num--;
    for(int i=1;i<=num;i++)
    {
        for(int j=0;j<=1000;j++)
        dp[i][j]=dp[i-1][j];//前i个质数和为j的不同最小公倍数个数
        int res=prime[i];
        while(res<=1000)
        {
            for(int j=0;j+res<=1000;j++)
            if(dp[i-1][j]) dp[i][j+res]+=dp[i-1][j];
            res*=prime[i];
        }
    }
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        ll ans=0;
        for(int j=1;j<=n;j++)
        ans+=dp[num][j];
        printf("%I64d\n",ans+1);
    }
}
