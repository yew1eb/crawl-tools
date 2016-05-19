#include<stdio.h>
#include<string.h>
int main()
{
    int a[30],i,n,t;
    a[1]=3;a[2]=7;
    for(i=3;i<=20;i++)
        a[i]=2*a[i-1]+a[i-2];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&t);
        printf("%d\n",a[t]);
    }
return 0;
}