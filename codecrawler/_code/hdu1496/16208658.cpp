#include<stdio.h>
#include<string.h>
int hash[2000000];
int main()
{
     int a,b,c,d,i,j,ans;
     while(scanf("%d %d %d %d",&a,&b,&c,&d)!=EOF)
     {
         if((a>0&&b>0&&c>0&&d>0)||(a<0&&b<0&&c<0&&d<0))
         {
             printf("0\n");continue;
         }
         ans=0;
         memset(hash,0,sizeof(hash));
         for(i=1;i<=100;i++)
             for(j=1;j<=100;j++)
                 hash[1000000+a*i*i+b*j*j]++;//è¥a b ä¸ºæ­£ å c då¶ä¸­æè´æ° é£ä¹ç¨100000ä¸åç»æåè¿éçå°æ ä¸æ ·
         for(i=1;i<=100;i++)
             for(j=1;j<=100;j++)
                 ans+=hash[1000000-c*i*i-d*j*j];
         printf("%d\n",ans*16);//ç±äºæ¯ä¸ªxié½å¯è½ä¸ºæ­£æä¸ºè´ å ä¸ºæ¯å¹³æ¹ æä»¥å¶å®æ16åæä»¬æ¾å°çç­æ¡
     }
     return 0;
}