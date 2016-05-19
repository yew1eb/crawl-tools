#include<iostream>
using namespace std;
int a[100];
int main()
{
    long long A,B;
    int m;
    while(scanf("%d",&m),m)
    {
        int sum,i=0,j;
        scanf("%I64d%I64d",&A,&B);
        sum=A+B;
        if(sum==0)   {printf("0\n");continue;}
        while(sum)
        {
            a[i++]=sum%m;
            sum=sum/m;
        }
        for(j=i-1;j>=0;j--)
        printf("%d",a[j]);
        printf("\n");
    }
    return 0;
}
