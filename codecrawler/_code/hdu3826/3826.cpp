#include<stdio.h>
#include<math.h>
#include<string.h>
#define M 1100000
#define MIN 0.00001
int a[M],b[500000],flag;
int init()
{
    int i,j;
    memset(a,0,sizeof(a));
    for(i=2;i*i<=M;i++)
    {
        if(!a[i])
        {
            for(j=i*2;j<=M;j=j+i)
            {
               a[j]=1;
            }
        }
    }
    j=1;
    for(i=2;i<=M;i++)
    {
        if(!a[i])

        {
        b[j]=i;
         j++;
        }
    }
    return j;

}
void pd(double nu)
{
    double a;
    a=sqrt(nu);
    if(a-floor(a)<=MIN)
     flag=0;
     else
     flag=1;

}
int main()
{
    int n;
    scanf("%d",&n);
    int cs=0;
    int len=init();
    //printf("%d\n",len);
    while(n--)
    {
        cs++;
         __int64 num;
         int i;
         scanf("%I64d",&num);
         flag=0;
         for(i=1;i<len;i++)
         {

             int sum=0;
             while(num%b[i]==0)
             {
                 num/=b[i];
                 sum++;
             }
             if(sum>=2)
              {
                  flag=1;
                  break;
              }
         }
         if(flag==1)
         {printf("Case %d: No\n",cs);continue;}
        if(num==1)
        {printf("Case %d: Yes\n",cs);continue;}
              pd((double)num);
              if(flag==0)
          printf("Case %d: No\n",cs);
        else
        printf("Case %d: Yes\n",cs);
    }
    return 0;
}
