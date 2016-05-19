#include<stdio.h>
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    int n,a,b,c,i;
    while(~scanf("%d",&n))
    {
        scanf("%d",&a);
        for(i=1;i<=n-1;i++)
        {
            scanf("%d",&b);
            c=gcd(a,b);
            a=a/c*b;
        }
        printf("%d\n",a);
    }
    return 0;
}