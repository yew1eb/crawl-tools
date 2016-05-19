#include<stdio.h>
#include<string.h>
#define MAX 110
int a[MAX],b[MAX],sum[MAX];
int prime[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};;
int main()
{
    int i,len,j,aCount,bCount,flag;
    char c;
    while(1)
    {
        memset(sum,0,sizeof(sum));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        i=0;
        while(~scanf("%d%c",&a[i],&c))
        {
            if(c==' ')
                break;
            else
                i++;
        }
        aCount=i;
        i=0;
        while(~scanf("%d%c",&b[i],&c))
        {
            if(c=='\n')
                break;
            else
                i++;
        }
        bCount=i;
        if(aCount==0&&bCount==0&&a[0]==0&&b[0]==0)
            break;
        len=aCount>bCount?aCount:bCount;
        for(i=aCount,j=0;i>=0;i--)
        {
            sum[j++] += a[i];
        }
        for(i=bCount,j=0;i>=0;i--)
        {
            sum[j++] += b[i];
        }
        for(i=0;i<=len;i++)
        {
            if(sum[i]>=prime[i])
            {
                sum[i]-=prime[i];
                sum[i+1]++;
            }
        }
        if(sum[len+1])
            len++;
        for(i=len;i>=0;i--)
        {
            printf("%d",sum[i]);
            if(i>0)
                putchar(',');
        }
        printf("\n");
    }
    return 0;
}