#include<stdio.h>
#include<math.h>
int main()
{
    int c,n,k;
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d %d",&n,&k);
        printf("%I64d\n",(__int64)pow(2,n-k));
    }
    return 0;
}