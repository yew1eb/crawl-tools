#include<stdio.h>
int c[50];
int main()
{
    int m;
    __int64 sum,a,b;
    while(scanf("%d",&m)!=EOF && m)
    {
        scanf("%I64d%I64d",&a,&b);
        sum=a+b;
        if(sum==0)
        {
            printf("0\n");
            continue;
        }
        int i=0;
        while(sum)
        {
            c[i++]=sum%m;
            sum/=m;
        }
        for(int j=i-1;j>=0;j--) printf("%d",c[j]);
        printf("\n");
    }
    return 0;
}