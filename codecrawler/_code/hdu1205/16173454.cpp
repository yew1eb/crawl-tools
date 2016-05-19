#include<stdio.h>
int main()
{
    __int64 sum;
    int max_num,candy,t,n,i;
    scanf("%d",&t);
    while(t--)
    {
        max_num=-1;
        sum=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        { 
            scanf("%d",&candy);
            sum+=candy;
            if(candy>max_num)
                max_num=candy;
        }
        if(sum-max_num+1>=max_num)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
