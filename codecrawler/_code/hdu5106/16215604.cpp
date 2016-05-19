#include <iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define mod 1000000007
using namespace std;

ll dp[1005][1005],c[1005][1005];
ll twop[1005];

void Pow()
{
    int i;
    twop[0]=1;
    for(i=1;i<=1000;i++){
        twop[i]=(twop[i-1]<<1)%mod;
    }
}

void init()
{
    int i,j;
    Pow();
    c[0][0]=1;
    for(i=1;i<=1000;i++){
        c[i][0]=1;
        for(j=1;j<=i;j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    }
    for(i=1;i<=1000;i++){
        for(j=1;j<=i;j++) dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]+c[i-1][j-1]*twop[i-1]%mod)%mod;
    }
}

ll solve(int n,char *str)
{
    int i,len=strlen(str),j;
    int num[1005]={0};
    for(i=0;i<len;i++){
        num[i+1]=str[len-i-1]-'0';
    }
    ll ans=0,tmp=0;
    int tot=0;
    for(i=len;i>0;i--){
        if(n<tot) break;
        if(num[i]){
            ans+=(c[i-1][n-tot]*tmp%mod+dp[i-1][n-tot])%mod;
            ans%=mod;
            tot++,tmp+=twop[i-1],tmp%=mod;
        }
    }
    return ans%mod;
}

int main()
{
    int n;
    char str[1005]={0};
    init();
    while(~scanf("%d%s",&n,str)){
        printf("%I64d\n",solve(n,str));
    }
    return 0;
}
