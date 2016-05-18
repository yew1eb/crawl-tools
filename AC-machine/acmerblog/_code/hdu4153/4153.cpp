#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,i,t,max,mode,a[1001],count[1001];
    double ans;
    while(~scanf("%d %d",&n,&m)&&(n,m))
    {
        memset(a,0,sizeof(a));
        memset(count,0,sizeof(count));
        mode=-1;ans=0.01;
        for(i=0;i<=n-1;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        max=a[n-1]/m;
        for(i=0;i<=n-1;i++)
        {
            t=a[i]/m;
            count[t]++;
        }
        for(i=0;i<=max;i++)
        {
            if(count[i]>mode)
            {
                mode=count[i];
            }
        }
        for(i=max;i>=0;i--)
        {
            ans=ans+(double)(i)/max*count[max-i]/mode;
        }
        printf("%.6lf\n",ans);
    }
    return 0;
}