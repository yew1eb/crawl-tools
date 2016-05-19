#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
typedef long long LL;

struct Nod{
    LL x,a;
    bool operator < (const Nod &z) const{
        return x < z.x;
    }
}in[100005];


LL dp[2][100005];
LL l,n,k,sum;
LL x[100005],a[100005];

void init(){
    memset(dp,0,sizeof(dp));
    sum = 0;
}

void solve(){
    dp[0][0] = dp[1][0] = 0;
    LL num = 1, pre;
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i];j++){
            pre = num - k > 0 ? num - k : 0;
            dp[0][num] = dp[0][pre] + (2*x[i] > l ? l : 2*x[i]);
            num++;
        }
    }
    num = 1;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<a[i];j++){
            pre = num - k > 0 ? num - k : 0;
            dp[1][num] = dp[1][pre] + (2*l - 2*x[i] > l ? l : 2*l - 2*x[i]);
            num++;
        }
    }
    LL res = 0x3f3f3f3f3f3f3f3f;
    for(int i=0;i<=sum;i++)
        res = min(res,dp[0][i]+dp[1][sum-i]);
    printf("%I64d\n",res);
}

int main(){
    int cas;
    scanf("%d",&cas);
    while(cas--){
        init();
        scanf("%I64d%I64d%I64d",&l,&n,&k);
        for(int i=0;i<n;i++) scanf("%I64d%I64d",&in[i].x,&in[i].a);
        sort(in,in+n);
        for(int i=0;i<n;i++){
            x[i] = in[i].x;
            a[i] = in[i].a;
            sum += a[i];
        }
        solve();
    }
    return 0;
}
