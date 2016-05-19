#include"stdio.h"
#include"string.h"
#include"math.h"
int main()
{
    int prime[2000],k;
    int num[10001];
    int i,l;
    int temp;
    int m;
    double a,b;
    double limit;
    int w,h;
    double max;


    memset(num,0,sizeof(num));
    num[0]=num[1]=1;
    k=0;
    for(i=2;i<=10000;i++)
    {
        if(num[i]==0)
        {
            for(temp=2*i;temp<=10000;temp+=i)
                num[temp]=1;
            prime[k]=i;
            k++;
        }
    }


    while(scanf("%d%lf%lf",&m,&a,&b),m!=0||a!=0||b!=0)
    {
        limit=a/b;
        max=0;


        for(i=k-1;i>=0;i--)
        {
            for(l=i;l>=0;l--)
            {
                if(prime[i]>m||prime[l]>m||prime[i]*prime[l]>m)
                    continue;
                if((double)prime[l]/prime[i]<limit)
                    continue;
                if(prime[i]*prime[l]>max)
                {
                    max=prime[i]*prime[l];
                    w=prime[i];
                    h=prime[l];
                }
            }
        }


        printf("%d %d\n",w>h?h:w,w>h?w:h);
    }
    return 0;
}