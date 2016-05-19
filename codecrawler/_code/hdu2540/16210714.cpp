#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct haha
{
     double s;
     double h;
     double e;
}a[111111];
//bool  vis[10000000+100];
int cmp(const void *a,const void *b)
{
    return (*(struct haha *)a).s>(*(struct haha *)b).s?1:-1;
}
int main()
{
    int n,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        if(!n) break;
        double tan,c,b;
        for(i=0;i<n;i++)
            scanf("%lf %lf",&a[i].s,&a[i].h);
         scanf("%lf/%lf",&c,&b);
         tan=c/b;
         //printf("%lf\n",tan);

         qsort(a,n,sizeof(a[0]),cmp);
         for(i=0;i<n;i++)
         {
              a[i].e=a[i].s+a[i].h/tan;
            //  printf("s=%lf e=%lf\n",a[i].s,a[i].e);
         }
         int cnt=n;
         double s,e;
         s=a[0].s;e=a[0].e;
         for(i=1;i<n;i++)
         {
              if(a[i].e<=e&&a[i].s>=s) cnt--;
              else
              {
                  if(a[i].e>e)  {e=a[i].e;s=a[i].s;}
              }
         }
         printf("%d\n",cnt);
    }
     return 0;
}