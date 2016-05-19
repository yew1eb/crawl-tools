#include<cstdio>
#include<algorithm>
using namespace std;
#define s(a) scanf("%d",&a)
int t,c=1,n,a[100005],i,flag,ans;
main()
{
    s(t);
    while(t--)
    {
        s(n);
        for(i=0,flag=1,ans=2; i<n; i++)
            s(a[i]);
        if(a[0]>3||a[0]==0)
            flag=0;
        if(flag)
        {
            for(i=1; i<n; i++)
            {
                if(a[i]-a[i-1]>3||a[i-1]-a[i]>3||(a[i]==a[i-1]&&a[i]!=1))
                {
                    flag=0;
                    break;
                }
                if((a[i]==2&&a[i-1]==1)||(a[i]==1&&a[i-1]==2))
                    ans+=2;
            }
            if(a[n-1]==0)
                ans/=2;
        }
        printf("Case #%d: %d\n",c++,flag?ans:0);
    }
}
