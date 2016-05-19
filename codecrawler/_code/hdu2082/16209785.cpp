#include <stdio.h>
#include <string.h>
const int MAX=50;
int c1[MAX+5],c2[MAX+5],num[27];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(int i=1;i<=26;i++)
            scanf("%d",&num[i]);
        c1[0]=1;                        //ç¸å½äºç¨X^0å»ä¹ä»¥åé¢çå¤é¡¹å¼
        for(int i=1;i<=26;i++)          //è¦ä¹ä»¥26ä¸ªå¤é¡¹å¼
        {
            for(int j=0;j<=MAX;j++)     //c1çåé¡¹çææ°
            {
                for(int k=0;k<=num[i] && j+k*i<=MAX;k++)    //k*iè¡¨ç¤ºè¢«ä¹å¤é¡¹å¼åé¡¹çææ°,(X^0*i + X^1*i + X^2*i + â¦â¦)
                    c2[j+k*i] += c1[j];                     //ææ°ç¸å å¾j+k*i,å å¤å°åªåå³äºc1[j]çç³»æ°ï¼å ä¸ºè¢«ä¹å¤é¡¹å¼çåé¡¹ç³»æ°åä¸º1
            }
            memcpy(c1,c2,sizeof(c2));
            memset(c2,0,sizeof(c2));
        }
        int ans=0;
        for(int i=1;i<=MAX;i++)
            ans += c1[i];
        printf("%d\n",ans);
    }
    return 0;
}
