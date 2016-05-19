#include <stdio.h>
#include <math.h>
int a[10000]={2},num[100000]={0,0};
int main()
{
    int n,i,j,g,temp;
    for(g=0,i=3;i<100000;i++)
    {
        temp=sqrt(i);
        for(j=2;j<=temp;j++)
            if(i%j==0)break;
        if(j>temp)
        {
            a[g]=i;
            num[i]=num[i-1]+(a[g-1]+2==a[g]?1:0);
            g++;
        }
        else
            num[i]=num[i-1];
    }
    while(scanf("%d",&n)&&n>=0)
    {
        printf("%d\n",num[n]);
    }
    return 0;
}