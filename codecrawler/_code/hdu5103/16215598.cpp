#include<iostream>
#include<cstring>
#include<cstdio>
#include<ostream>
#include<istream>
#include<algorithm>
#include<queue>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<vector>
#define fi first
#define se second
#define pii pair<int,int>
#define inf (1<<30)
#define eps 1e-8
#define ll long long
using namespace std;
const int maxn=110005;
const ll mod=1000000007;
int n;
int d[20][2];
int num[1<<14];
ll sum[1<<14];
ll sub[1<<14];
ll dp[1<<14][15];
ll Dp(int s,int c);
ll Sum(int s);
ll Sub(int s)
{
    if(s==0)
        return 1;
    if(sub[s]!=-1)
        return sub[s];
    sub[s]=0;
    int id[15];
    int cnt=0;
    for(int i=0;i<n;i++) {
        if(s&(1<<i)) {
            id[cnt++]=i;
        }
    }
    for(int i=1;i<(1<<cnt);i+=2) {
        int s1=0;
        for(int j=0;j<cnt;j++) {
            if(i&(1<<j)) {
                s1^=(1<<id[j]);
            }
        }
        sub[s]+=Sum(s1)*Sub(s^s1)%mod;
        sub[s]%=mod;
    }
    return sub[s];
}
ll Dp(int s,int c)
{
    return Sub(s^(1<<c));
}
ll Sum(int s)
{
    if(sum[s]!=-1)
        return sum[s];
    sum[s]=0;
    for(int i=0;i<n;i++) {
        if(s&(1<<i)) {
            if(num[s]>=d[i][0]&&num[s]<=d[i][1])
                sum[s]=(sum[s]+Dp(s,i))%mod;
        }
    }
    return sum[s];
}
void pre()
{
    memset(num,0,sizeof(num));
    for(int i=0;i<(1<<14);i++) {
        int o=0;
        for(int j=0;j<14;j++) {
            if(i&(1<<j))
                o++;
        }
        num[i]=o;
    }
}
int main()
{
    pre();
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d%d",&d[i][0],&d[i][1]);
        memset(sum,-1,sizeof(sum));
        memset(sub,-1,sizeof(sub));
        memset(dp,-1,sizeof(dp));
        printf("%I64d\n",Sum((1<<n)-1));
    }
    return 0;
}