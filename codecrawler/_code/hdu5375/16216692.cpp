#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 2e5+10;

typedef long long LL;

char str[maxn];

LL dp[maxn][2];

int a[maxn];

int main()
{
    int n,t,cas=1;
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        n=strlen(str);
        for(int i=0;i<n;i++) scanf("%d",a+i);
        memset(dp,0,sizeof(dp));
        if(str[0]=='1'||str[0]=='?') dp[0][1]= a[0];
        for(int i=1;i<n;i++){
            if(str[i]=='?'){
                if(str[i-1]=='0')dp[i][1] = dp[i-1][0]+a[i],dp[i][0]=dp[i-1][0];
                if(str[i-1]=='1') dp[i][0] = dp[i-1][1]+a[i],dp[i][1]=dp[i-1][1];
                if(str[i-1]=='?'){
                    dp[i][0] = max(dp[i-1][0],dp[i-1][1]+a[i]);
                    dp[i][1] = max(dp[i-1][1],dp[i-1][0]+a[i]);
                }
            }
            else{
                if(str[i]=='1'&&str[i-1]=='?') dp[i][1] = max(dp[i-1][0]+a[i],dp[i-1][1]);
                if(str[i]=='1'&&str[i-1]=='1') dp[i][1] =dp[i-1][1];
                if(str[i]=='1'&&str[i-1]=='0') dp[i][1] =dp[i-1][0]+a[i];
                if(str[i]=='0'&&str[i-1]=='1') dp[i][0] = dp[i-1][1]+a[i];
                if(str[i]=='0'&&str[i-1]=='?') dp[i][0] = max(dp[i-1][1]+a[i],dp[i-1][0]);
                if(str[i]=='0'&&str[i-1]=='0') dp[i][0] =dp[i-1][0];
            }
        }
        printf("Case #%d: ",cas++);
        if(str[n-1]=='?') printf("%I64d\n",max(dp[n-1][0],dp[n-1][1]));
        if(str[n-1]=='0') printf("%I64d\n",dp[n-1][0]);
        if(str[n-1]=='1') printf("%I64d\n",dp[n-1][1]);
    }
    return 0;
}
