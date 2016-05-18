#include<stdio.h>
#include<math.h>
int main()
{
    int n,i;
    double a[22],mmax,mmin,sum,mid;
    while(scanf("%d",&n)!=EOF)
    {
        if(!n)break;
        sum=0;mmax=0;mmin=10;
        for(i=1;i<=n;i++)
        {
            scanf("%lf",&a[i]);
            sum+=a[i];
            if(mmax<a[i])  mmax=a[i];
            if(mmin>a[i])  mmin=a[i];
        }
        double best=(sum-mmax-mmin)/(double)(n-2);
        int pos;
        mmin=11;
        for(i=1;i<=n;i++)
        {
              mid=fabs(best-a[i]);
              if(mid<mmin)  {mmin=mid;pos=i;}
        }
        printf("%d\n",pos);
    }

    return 0;
}
