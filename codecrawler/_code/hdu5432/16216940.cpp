#include<stdio.h>
#include<string.h>
#include<math.h>
#define eps 0.0000000001
double V;
int n;
 double a[10005],b[10005],h[10005],sum;
double cal(double h,double a,double b)
{
    if(h>=a)return 0;      //å¦æå½åé«åº¦å¤§äºè¿ä¸ªé¥ä½çé«åº¦ï¼å°±æ¯è¿ä¸ªé¥ä½æ²¡æè¢«åå²ï¼ä½ç§¯å°±æ¯0.
    double ans,d;
    d=b*(a-h)/a;
    ans=d*d*(a-h)/3;
    return ans;
}
double erfen(double l,double r)
{
    double x=r;
    double d,v,mid;
      int f=0;

    while(fabs(l-r)>eps)
    {
        v=0;
        mid=(l+r)/2;
        for(int i=1;i<=n;i++)
            v+=cal(mid,a[i],b[i]);   //è®¡ç®ä½ç§¯
      if(fabs(2*v-sum)<eps){
            return mid;
        }
       else  if(2*v<sum)r=mid;
        else if(2*v>sum)l=mid;

    }
    return l;
}
int main()
{
    int T,i,j,k;

    scanf("%d",&T);
    while(T--)
    {
        sum=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%lf",&a[i]);
            for(i=1;i<=n;i++)
                scanf("%lf",&b[i]);
        for(i=1;i<=n;i++)
            {
                V=1.0/3*a[i]*b[i]*b[i];
                sum+=V;     //æ»ä½ç§¯
            }
          double x= erfen(0,100000);
          printf("%d\n",(int)x);    //åæ´
    }
    return 0;
}