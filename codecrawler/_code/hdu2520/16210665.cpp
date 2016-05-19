#include<stdio.h>
int main()
{
    int n;
    int t;
    int sum;
    int i;
    int temp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n==1)
        {
            printf("%d\n",1);
        }
        else
        {
            sum=1;
            temp=1;
            for(i=2;i<=n;i++)
            {
                temp=temp+2;
              sum=(sum+temp)%10000;
            }
            printf("%d\n",sum);
        }
        
    }
    return 0;
}