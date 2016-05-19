#include <stdio.h>

int num[100005],d[100005];

int main()
{
    int n,i,j,t;
    long long ans;

    while(~scanf("%d",&n))
    {
        for(i=0;i<=n;i++) d[i]=-1;

        for(i=0;i<=n;i++) scanf("%d",&num[i]);

        ans=0;

        for(i=n;i>=0;i--)
        {
            if(d[i]==-1)
            {
                t=0;

                for(j=0;;j++)
                {
                    if(!(i&(1<<j))) t+=1<<j;

                    if(t>=i) break;
                }

                t-=(1<<j);

                ans+=(i^t)+(i^t);

                d[i]=t;
                d[t]=i;
            }
        }

        printf("%I64d\n",ans);

        for(i=0;i<n;i++) printf("%d ",d[num[i]]);

        printf("%d\n",d[num[n]]);
    }
}