#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<stack>
#include<cmath>
#include<queue>
#define INF 0x0f0f0f0f
using namespace std;

int main()
{
    long long int i,j,k,l,r,n,t,m,mid;
    long long int a[100005];
    scanf("%d",&t);
    while(t--)
    {
        long long int ans=0;
        scanf("%I64d%I64d",&n,&k);
        for(i=0;i<n;i++)
        {
            scanf("%I64d",&a[i]);
        }
        sort(a,a+n);
        r=1;
        for(i=0;i<n;i++)
        {
            l=i+1;
            r=n-1;
            while(l<=r)
            {
                mid=(l+r)/2;
                if(a[mid]-a[i]>k)    r=mid-1;
                else l=mid+1;
            }

            ans=ans+r-i;
            
        }
        printf("%I64d\n",ans);
    }
} 