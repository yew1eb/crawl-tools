#include<stdio.h>
int main()
{
    int n,a,b;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&a,&b);
        if(a%2==0&&b%2!=0||a%2!=0&&b%2==0||(a<b))
            printf("impossible\n");
        else
            printf("%d %d\n",(a+b)/2,(a-b)/2);
    }
    
    return 0;
}
