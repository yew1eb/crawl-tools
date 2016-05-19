#include <stdio.h>
#include <stdlib.h>

#define m 9973

void Extend_gcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1,y=0;
        return ;
    }
    Extend_gcd(b,a%b,x,y);
    int r=x;
    x=y;
    y=r-(a/b)*y;
}

int main()
{
    int n,b,t,x,y;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&n,&b);
        Extend_gcd(b,m,x,y);
        x=(x%m+m)%m;
        printf("%d\n",(x*n)%m);
    }
    return 0;
}
