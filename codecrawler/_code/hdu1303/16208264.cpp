#include<stdio.h>
int a[20];
int main()
{
    while(~scanf("%d",&a[0]),a[0]!=-1)//å¤æ­ç¬¬ä¸ä¸ªæ¯å¦æ¯-1,å¤æ­æ¯å¦ç»æ 
    {
        int i,j;
        for(i=1;;i++) 
        {
            scanf("%d",&a[i]);
            if(a[i]==0)//ä¸ç»æ°æ®æ¯å¦ç»æ 
            break; 
        }
        int count=0;
        for(i=0;a[i]!=0;i++)
        {
            for(j=0;a[j]!=0;j++)
            if(a[i]==a[j]*2)//æ´åæ±è§£ 
            count++;
        }
        printf("%d\n",count);//æ¾çæ¯å¤å°å¯¹æ»¡è¶³é¢æçããã 
    }    
    return 0;
} 
