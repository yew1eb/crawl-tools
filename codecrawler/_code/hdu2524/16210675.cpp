#include<stdio.h>
int main()
{
    int n,m;
    int sum;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m); 
        sum=0;
        for(int i=n;i>=1;i--)
        {
            sum=sum+(1+m)*m/2*i;
        }
        printf("%d\n",sum);
    }
    return 0;
}