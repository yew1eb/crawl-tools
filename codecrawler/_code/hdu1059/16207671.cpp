#include"stdio.h"
#include"string.h"
int dp[60011];
int main()
{
    int num[7];
    int i,l,k;
    int sum;
    int total;
    int Case=1;
    while(scanf("%d",&num[1])!=-1)
    {
        sum=num[1];
        for(i=2;i<=6;i++)    {scanf("%d",&num[i]);sum+=num[i]*i;}
        
        if(sum==0)    break;
        if(sum%2!=0)
        {
            printf("Collection #%d:\n",Case++);
            printf("Can't be divided.\n\n");
            continue;
        }
        
        total=sum/2;
        for(l=1;l<=total;l++)    dp[l]=0;
        for(k=0;k<=num[1]&&k<=total;k++)    dp[k]=1;
        for(i=2;i<=6;i++)
        {
            for(l=total;l>=0;l--)
            {
                if(dp[l]==0)    continue;
                for(k=1;k<=num[i]&&k*i+l<=total;k++)    
                {
                    if(dp[k*i+l])    break;
                    dp[k*i+l]=1;
                }
            }
        }


        if(dp[total])
        {
            printf("Collection #%d:\n",Case++);
            printf("Can be divided.\n\n");
        }
        else
        {
            printf("Collection #%d:\n",Case++);
            printf("Can't be divided.\n\n");
        }
    }
    return 0;
}