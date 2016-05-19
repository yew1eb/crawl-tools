#include<stdio.h>
#include<string.h>

int a[20],b[20],dp[500010];

int Max(int x,int y)
{
    return x>y?x:y;
} 

int main()
{
    int T,n,m,year;
    int i,j,k,sum,temp;
    
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&m,&year);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            a[i]=a[i]/1000;
        }
        temp=m/1000;
        for(i=1;i<=year;i++)
        {
            memset(dp,0,sizeof(dp));  //ä¸å¹´ç®ä¸æ¬¡ï¼ååçæ¯åå§çæ¬étemp
            for(j=0;j<n;j++)
            {
                for(k=a[j];k<=temp;k++)
                {
                    dp[k]=Max(dp[k],dp[k-a[j]]+b[j]);
                }
            }
            m+=dp[temp];
            temp=m/1000;
        }
        printf("%d\n",m);
    }
    return 0;
}