#include<stdio.h>
int main()
{
    int n;
    long long a,ans;
    while(~scanf("%d",&n))
    {
        ans=0;
        while(n--)
        {
            scanf("%I64d",&a);
            ans^=a;
        }
        if(ans)printf("Win\n");
        else printf("Lose\n");
    }
    return 0;
} 