#include"stdio.h"
#include"string.h"
#include"math.h"
int prime[331],cnt;
void fun()
{
    int a[1001];
    memset(a,0,sizeof(a));
    int i,j;
    for(i=2;i<=1000;i++)
    {
        if(a[i]==0)
        {
            for(j=i+i;j<=1000;j+=i)
                a[j]=1;
        }
    }
    cnt=0;
    for(i=1;i<=1000;i++)
    {
        if(a[i]==0)prime[cnt++]=i;
    }
    //printf("%d",cnt);
}
int main()
{
    int n,c;
    int a,b;
    int i,j,t;
    fun();
    while(scanf("%d%d",&n,&c)!=-1)
    {
        int t;
        t=0;
		printf("%d %d: ",n,c);
        for(i=0;i<cnt;i++)
        {
            if(prime[i]>n)break;
        }
        if(c>=i)
        {
            for(j=0;j<i-1;j++)
                printf("%d ",prime[j]);
            printf("%d\n",prime[j]);
        }
        else
        {
            t=i;
            if(t%2==1)
            {
                a=t/2-c+1;
                b=t/2+c-1;
            }
            else
            {
                a=t/2-c;
                b=t/2+c-1;
            }
            for(i=a;i<b;i++)
                printf("%d ",prime[i]);
            printf("%d\n",prime[i]);
        }
		printf("\n");
    }
    return 0;
}