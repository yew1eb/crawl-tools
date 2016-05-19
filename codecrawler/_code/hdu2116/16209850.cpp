#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
__int64 a[70];
int main()
{

    __int64 c,d;
    int num,k,i,j,flag;
    while(scanf("%d",&k)!=EOF)
    {
        flag=0;
        scanf("%I64d%I64d",&c,&d);
        num=0;
        memset(a,0,sizeof(a));
        if((c<0&&d>0)||(c>0&&d<0))
        {
            printf("WaHaHa\n");
            continue;
        }
        //ç¬¦å·ä¸ä¸æ ·ä¸å®æ¯ä¸è¡ç
         if(c<0&&d<0)
        {
            c=-c;
            d=-d;
            flag=1;
        }
        
        while(c)
        {
           a[num++]=c%2;
           c=c/2;
        }
        //æcæ¢ææ¯äºè¿å¶å½¢å¼
        num=0;
        while(d)
        {
            a[num]=a[num]+d%2;//ä¸æç½ä¸ºä»ä¹æ¹æäºa[num++]=a[num++]+d%2;å°±éäº
            num++;
            d=d/2;
        }
        /*å¨æ°ç»ééåºå­å¨äºè¿å¶,
        åå¦å½c=7,d=5.é£ä¹ç¸å å¾
        åº12,ä¹å°±æ¯1100,å­å°æ°ç»
        éçå½¢å¼ä¹å°±æ¯0011000**äº        
        ç¶åå¯¹å¶è¿è¡å¤æ­å°±å¯ä»¥äº
        
        
        */
        for(i=0;i<68;i++)
        {
            a[i+1]=a[i+1]+a[i]/2;
            a[i]=a[i]%2;
        }
        for(i=68; i>=0; i--)
        if(a[i]!=0)
        break;
        if(i==k-1&&flag)
        {
            for(j=i-1;j>=0;j--)
            {
                if(a[j])
                break;
            }
        }
        if(i<k-1)
        printf("WaHaHa\n");
        else
        /*
        è¿ä¸ªå°æ¹æ¯æ±åºå¦ææä»¬æ±
        çæ¯è´æ°ï¼åå¦c=-4,d=-4ï¼
        ç¸å å¾åº-8ï¼ä¸º2çä¸æ¬¡æ¹ï¼
        k=4,åç¹å«æ¿åºæ¥è¿è¡å¤æ­
        å°±å¯ä»¥äº
        */
        if(i==k-1&&flag&&j<0)
        {
             printf("WaHaHa\n");
        }
        else
        printf("Yes\n");





    }
    return 0;
}
