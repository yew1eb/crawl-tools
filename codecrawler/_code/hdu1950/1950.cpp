#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int a[50000],i,j,t,n,maxn,minn,dp[50000];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int sum=0;
        dp[0]=-9999999;
        for(i=1;i<=n;i++)
        {
            if(a[i]>=dp[sum])
            {
                dp[++sum]=a[i];
            }
            else if(a[i]<dp[sum])
            {
                minn=1;maxn=sum;
                int mid;
                while(minn<maxn-1)
                {
                    mid=(maxn+minn)/2;
                    if(a[i]>dp[mid])
                        minn=mid;
                    else
                        maxn=mid;
                }
                if(dp[minn]>a[i])
                    dp[minn]=a[i];
                else
                    dp[maxn]=a[i];
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}