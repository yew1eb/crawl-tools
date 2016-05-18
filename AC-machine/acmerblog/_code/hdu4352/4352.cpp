#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<math.h>
using namespace std;
typedef long long lld;
#define oo 0x3f3f3f3f
#define mod 1000000007
#define maxn 30+5
lld dp[maxn][1<<10][15];
int bit[maxn];
lld L,R,K;

int NextSt(int st,int x)
{
    //找到第一个大于x的数并且替换他，nlogn求最长递增子序列的思想
    for(int i=x;i<10;i++)
        if(st&(1<<i)) return ((st^(1<<i))|(1<<x));
    return st|(1<<x);
}

int GetLen(int st)
{
    int cnt=0;
    while(st)
    {
        if(st&1) cnt++;
        st>>=1;
    }
    return cnt;
}

lld dfs(int pos,int st,int zero,int f)
{
    if(pos<1) return GetLen(st)==K;
    if(!f&&dp[pos][st][K]!=-1) return dp[pos][st][K];
    int last= f ? bit[pos] : 9;
    lld res=0;
    for(int i=0;i<=last;i++)
    {
        res+=dfs(pos-1,(zero==0&&i==0)?0:NextSt(st,i),zero||i,f&&(i==last));
    }
    if(!f) dp[pos][st][K]=res;
    return res;
}

lld GetAns(lld n)
{
    int len=0;
    while(n)
    {
        bit[++len]=n%10;
        n/=10;
    }
    return dfs(len,0,0,1);
}

int main()
{
    int T;
    memset(dp,-1,sizeof dp);
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        cin>>L>>R>>K;
        cout<<"Case #"<<cas<<": "
            <<GetAns(R)-GetAns(L-1)<<endl;
    }
	return 0;
}
