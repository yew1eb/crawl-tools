#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int ans,a[100005],dp[100005],c[100005],n,k;
//aæ°ç»å­æ¾åºå
//dpè®°å½å¨iç¹æ¶æé¿çéå¢å­åºåé¿åº¦
//cæ°ç»ä¸ºæ¯æ¬¡æ¥æ¾æ¶åçæ è®°ï¼è®°å½è·¯å¾

int bin(int t)
{
    int l = 1,r = n;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(t>c[mid])
            l = mid+1;
        else
            r = mid-1;
    }
    return l;
}

int LIS()
{
    int i,j;
    ans = 0;
    for(i = 1; i<=n; i++)
    {
        dp[i] = bin(a[i]);
        if(dp[i]>ans)//æ´æ°æé¿é¿åº¦
            ans = dp[i];
        j = i-k;//å ä¸ºéè¦ç¸éä¸ºK
        if(j>0 && c[dp[j]]>a[j])//æ¥æ¾æ è®°
            c[dp[j]] = a[j];
    }
    return ans;
}

int main()
{
    int t,i;
    while(~scanf("%d%d",&n,&k))
    {
        for(i = 1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            c[i] = 10000000;
        }
        printf("%d\n",LIS());
    }

    return 0;
}
