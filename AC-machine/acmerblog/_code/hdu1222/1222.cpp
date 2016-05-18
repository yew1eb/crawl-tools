#include <stdio.h>
int gcd(int a,int b)
{
    return a%b==0?b:gcd(b,a%b);
}
int main()
{
    int p,m,n;
    scanf("%d",&p);
    while(p--)
    {
        scanf("%d%d",&m,&n);
        if(gcd(m,n)==1)puts("NO");
        else puts("YES");
    }
    return 0;
}