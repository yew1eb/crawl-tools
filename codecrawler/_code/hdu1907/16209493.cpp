#include <stdio.h>
int main(int argc, char *argv[])
{
    int T,N,a[5000];
    int sum1;//åè£å çä¸ªæ°
    int sum2;//å­¤åå çä¸ªæ° 
    int ans;//å¼æ 
    scanf("%d",&T);
    while(T--)
    {//è¿ä¸ä¸ªæ°å­å¿è®°èµ0 ï¼éäºä¸æ¬¡ 
        sum1=0;
        sum2=0;
        ans=0; 
        scanf("%d",&N);
        for (int i=0;i<N;i++)
        {
           scanf("%d",&a[i]);
           if(a[i]>=2) sum1++;
           else sum2++;    
           ans^=a[i];
        }
        if((ans!=0 && sum1!=0) || (ans==0) && sum1==0)
           printf("John\n");
        if((ans==0 && sum1>=2) || (ans!=0 && sum2%2!=0 && sum1==0)) printf("Brother\n");   
    }                                                        //åè£å =0å¿è®°äº 
    return 0;                 
}