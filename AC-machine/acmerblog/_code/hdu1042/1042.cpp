#include <stdio.h>
#include <string.h>
#define base 10000 //1万代表每位存4位./*想想当N变大时，考虑中间数据是否会溢出int（即base*N） */
int num[10000];//此处位数根据N的阶乘位数/base的位数变化而变化
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(num,0,sizeof(num));
        num[0]=1;
        int k=0;
        for(int i=2;i<=n;i++)
        {
            for(int j=k;j>=0;j--)
                num[j]*=i;
            for(int j=0;j<=k;j++)
            {
                if(num[j]>=base)
                {
                    num[j+1]+=num[j]/base;
                    num[j]=num[j]%base;
                }
            }
            k = num[k+1]==0?k:k+1;
        }
        for(int i=k;i>=0;i--)
            printf(i==k?"%d":"%04d",num[i]);//除了第一位，把前面的0都要补上。而且修改时别忘了把04改了.
        printf("\n");
    }
	return 0;
}