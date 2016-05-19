#include<stdio.h>
#include<string.h>
#include<math.h>
#define PI acos(-1.0)
#define eps 0.0000000001
double min(double a,double b)
{
    if(a<b)return a;
    else return b;
}
double max(double a,double b)
{
    if(a>b)return a;
    else return b;
}
struct node{
  double x,y;
}p[10004];
double bian[10004],r[10004];
int n,flag;
double cal(double x)
{
    double sum=x*x;
    r[1]=x;
    for(int i=1;i<n;i++)
    {
        sum+=(bian[i]-r[i])*(bian[i]-r[i]);
        r[i+1]=bian[i]-r[i];
    }
    return sum*PI;
}
double solve(double l,double r)
{
    double mid,midmid,mid_value,midmid_value;
    while(fabs(l-r)>eps)
    {
        mid=(l+r)/2.0;
        midmid=(mid+r)/2.0;
        mid_value=cal(mid);
        midmid_value=cal(midmid);
      //  printf("%.2f %.2f\n",mid_value,midmid_value);
        if(mid_value<=midmid_value)r=midmid;
        else  l=mid;
    }
    mid=(l+r)/2.0;
    return cal(mid);
}
int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        memset(r,0,sizeof(r));
        memset(bian,0,sizeof(bian));
        flag=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
            k=0;
            for(i=1;i<n;i++)
            {
                k++;
                bian[k]=sqrt((p[i].x-p[i+1].x)*(p[i].x-p[i+1].x)+(p[i].y-p[i+1].y)*(p[i].y-p[i+1].y));
            }
            bian[++k]=sqrt((p[1].x-p[n].x)*(p[1].x-p[n].x)+(p[1].y-p[n].y)*(p[1].y-p[n].y));
               //è®¡ç®å¤è¾¹å½¢çè¾¹é¿ã
          if(n%2)
          {
              double x;
              double sum=0;
              r[1]=x;
              for(i=1;i<n;i++)
                {
             if(i%2)sum=sum-bian[i];
             else sum=sum+bian[i];
          }
             x=(bian[n]-sum)/2.0;
             r[1]=x;
             for(i=1;i<n;i++)
                r[i+1]=bian[i]-r[i];
              for(i=1;i<=n;i++)
              {
                  if(r[i]<0){
                    flag=1;
                    break;
                  }
              }
              if(flag)printf("IMPOSSIBLE\n");
              else {
               sum=0;
                for(i=1;i<=n;i++)
                    sum+=r[i]*r[i];
                printf("%.2f\n",sum*PI);
                for(i=1;i<=n;i++)
                    printf("%.2f\n",r[i]);
              }
          }
          else
          {
              double left,right;
              int id=1;
              double len=bian[1];
              left=0;right=bian[1];
              for(i=2;i<n;i++)
              {
                    id++;
                  if(i%2){
                    len=bian[id]-len;
                    right=min(right,len);
                  }
                  else {
                    len=bian[id]-len;
                    left=max(left,-len);
                  }
              }
              //å¯¹äºèå´çè®¡ç®ï¼æ¯æè§å¾çï¼å¯ä»¥å¨çº¸ä¸æ¨¡æåºæ¥ã
             r[1]=bian[1]/2.0;
          for(i=2;i<=n;i++)
          {
              r[i]=bian[i-1]-r[i-1];
          }
              double ans=solve(left,right);
          if(fabs((r[1]+r[n])-bian[n])>eps||left>right)printf("IMPOSSIBLE\n");
          else {
            printf("%.2f\n",ans);
          for(i=1;i<=n;i++)
            printf("%.2f\n",r[i]);
    }
          }
    }
    return 0;
}
