#include<stdio.h>
int main()
{
    int n,i,mul=1,num;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&num);
            if(num%2==1)
                mul*=num;
        }
        printf("%d/n",mul);
        mul=1;
    }
    return 1;
}