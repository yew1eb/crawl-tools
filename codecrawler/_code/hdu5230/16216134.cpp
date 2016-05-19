#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=100000+100;
const int mod= 998244353;
const int maxm=450;
int dp[2][maxn+5];
int s[maxn+5];
int main()
{
    int t,n;
    dp[1][1]=1;
    int it=1;//æ»å¨æ°ç»æ è®°
    for(int i=1; i<=maxm; i++,it=!it)
    {
        for(int j=1; j<=maxn; j++)
        {
            if(j+i<=maxn)
                dp[it][j+i]=(dp[it][j+i]+dp[it][j])%mod;
            if(j+i+1<=maxn)
                dp[!it][j+i+1]=(dp[it][j]+dp[!it][j+i+1])%mod;
            s[j]=(s[j]+dp[it][j])%mod;//åçå¼ä¸ºjçå
            dp[it][j]=0;//ä¸ºä¸ä¸è¡åå§å
        }
    }
    for (int j = 1; j < maxn; j++)//åç¼å
    s[j] = (s[j] + s[j - 1]) % mod;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int c,l,r;
        scanf("%d%d%d",&c,&l,&r);
        r=r-c;
        l=l-c;
        int ans=s[r];
        if(l>0)
        ans=(ans-s[l-1]+mod)%mod;
        if(l==0)//å¨é¨ä¸åæ¶
        ans++;
        printf("%d\n",ans);
    }
    return 0;
}
