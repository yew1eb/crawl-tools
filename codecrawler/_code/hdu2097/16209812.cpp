 
#include <stdio.h>
int main()
{
    int b[3],a[3]={10,16,12};//æ°ç»bè´®å­è¿å¶è½¬æ¢åçæ°ï¼æ°ç»aè´®å­éè¦è½¬æ¢çè¿å¶
    int i,sum,p,n;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        for(i=0;i<3;i++)
        {
            p=n,sum=0;
            while(p)
                sum=sum+p%a[i],p=p/a[i];
            b[i]=sum;
        }
        if(b[1]==b[0]&&b[1]==b[2])//å¦æè½¬æ¢åçä¸ä¸ªè¿å¶æ°ç¸ç­
            printf("%d is a Sky Number.\n",n);
        else
            printf("%d is not a Sky Number.\n",n);
    }
    return 0;
}        