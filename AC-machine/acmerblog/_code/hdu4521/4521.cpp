#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int ans,a[100005],dp[100005],c[100005],n,k;
//a数组存放序列
//dp记录在i点时最长的递增子序列长度
//c数组为每次查找时候的标记，记录路径

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
        if(dp[i]>ans)//更新最长长度
            ans = dp[i];
        j = i-k;//因为需要相隔为K
        if(j>0 && c[dp[j]]>a[j])//查找标记
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
