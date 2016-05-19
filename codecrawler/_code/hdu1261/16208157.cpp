#include <stdio.h>
#include <string.h>
#define num 1000
int main()
{
    char str[num];
    long long  n,x,count,j,i,q,sum,a[30],t,k;
    while(scanf("%lld",&n)!=EOF&&n)
    {
        memset(str,0,sizeof(str));
        str[0]=1;
        count=0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&x);
            sum=1;
            for(j=2;j<=x;j++)//è®¡ç®åä¸ªå­ç¬¦çä¸ªæ°é¶ä¹
            sum=sum*j;
            a[i]=sum;
            count+=x;//æ±å­ç¬¦æ»ä¸ªæ°ã
        }
        for(i=2;i<=count;i++)//å¤§æ°é¶ä¹ãcount
        {
            for(q=0,t=0;q<num;q++)
            {
                k=str[q]*i+t;
                str[q]=k%10;
                t=k/10;
            }
        }
        for(i=num-1;i>=0;i--)
        if(str[i]!=0)
        break;
        for(q=0;q<n;q++)
        {
            sum=0;
            for(j=i;j>=0;j--)//å¤§æ°é¤ä»¥å°æ°ï¼å­ç¬¦ä¸²æ¨¡æé¤æ³è¿ç¨ãå¤§èçé¤å§  è¯å®è½æ´é¤ã
            {
                t=(sum*10+str[j])/a[q];
                sum=(sum*10+str[j])%a[q];
                str[j]=t;
            }
        }
        for(i=num-1;i>=0;i--)
        if(str[i]!=0)
        break;
        for(q=i;q>=0;q--)
        printf("%d",str[q]);
        printf("\n");
    }
    return 0;
}