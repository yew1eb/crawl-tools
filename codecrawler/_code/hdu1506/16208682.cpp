#include<iostream>
#include<string.h>
#define LL long long 
using namespace std;
const int maxn=100010;
int dpl[maxn],dpr[maxn];
LL height[maxn];
int main()
{
    LL ans;
    int i,j,n;
    while(scanf("%d",&n)&&n)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&height[i]);
            dpl[i]=dpr[i]=1;
        }
        for(i=2;i<=n;i++)
        {
            int s=i-1;
            while(height[i]<=height[s]&&s>=1)
            {
                dpl[i]+=dpl[s];
                s=s-dpl[s];//ç»§ç»­å¯»æ¾
            }
        }
        for(i=n-1;i>=1;i--)
        {
            int s=i+1;
            while(height[i]<=height[s]&&s<=n)
            {
                dpr[i]+=dpr[s];
                s=s+dpr[s];
            }
        }
        ans=0;
        for(i=1;i<=n;i++)
        {
            LL temp=(height[i]*(dpl[i]+dpr[i]-1));
            if(ans<temp) ans=temp;
        }
        cout<<ans<<endl;
    }
    return 0;
}