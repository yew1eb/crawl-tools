#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,c=0;
        scanf("%d",&a);
        while(a%2==0)
        {
            c++;
            a/=2;
        }
        printf("%d %d\n",a,c);
    }
    
    return 0;
}