#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int a[40005],dp[40005],n;

int bin(int size,int k)
{
    int l = 1,r = size;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(k>dp[mid])
            l = mid+1;
        else
            r = mid-1;
    }
    return l;
}

int LIS()
{
    int i,j,ans=1;
    dp[1] = a[1];
    for(i = 2; i<=n; i++)
    {
        if(a[i]<=dp[1])
            j = 1;
        else if(a[i]>dp[ans])
            j = ++ans;
        else
            j = bin(ans,a[i]);
        dp[j] = a[i];
    }
    return ans;
}

int main()
{
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i = 1;i<=n;i++)
        scanf("%d",&a[i]);
        printf("%d\n",LIS());
    }

    return 0;
}
