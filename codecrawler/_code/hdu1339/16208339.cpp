#include<stdio.h>
int main()
{
    int n,o,p,t;
    scanf("%d",&t);
    while(t--)
    {
        p=0;
        scanf("%d",&n);
        while(n%2==0)
        {
            p++;
            n/=2;
        }
        printf("%d %d\n",n,p);
    }
    return 0;
}
