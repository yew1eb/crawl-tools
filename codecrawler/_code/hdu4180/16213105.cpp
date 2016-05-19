/**
[exgcd]hdu 4180 ç»åºåæ°(a/b)æ±å¦ä¸ä¸ªåæ°(c/d){d < b),ä¸æ»¡è¶³fabs(a/b - c/d)æå°ã
abäºè´¨æ¶
æå°æ¶æ»¡è¶³ bc+1 = ad || bc = ad+1ï¼æ­£ç¬¦åæ©å±æ¬§å éå¾ã
æ±åºä¸¤ä¸ªdåæ¯è¾ã

å ä¸ºä¸è½½äºæ°æ®ï¼ååè§è¯äºç²¾åº¦æå¤±çä¸¥éæ§ï¼æ¯è¾ä¸¤ä¸ªå®æ°çè·ç¦»æ¶ä¸ç´WA(ç¨è®¡ç®å¨åç°å°æ°ç¹å20ä½æä¸å)
æ¯è¾ä¸¤ä¸ªdçå¤§å°å³å¯
*/
#include <stdio.h>
#define EPS 1e-20
__int64 exgcd(__int64 a,__int64 b,__int64 &x,__int64 &y)
{
    if(b == 0LL)
    {
        x = 1LL;
        y = 0LL;
        return a;
    }
    __int64 d = exgcd(b,a%b,x,y);
    __int64 t = x;
    x = y;
    y = t - a / b * y;
    return d;
}
int main()
{
    __int64 t,a,b,x,y,c1,d1,c2,d2,d;
    scanf("%I64d",&t);
    while(t--)
    {
        scanf("%I64d/%I64d",&a,&b);
        x = y = 0;
        d = exgcd(a,b,x,y);
        if(d != 1)
        {
            printf("%I64d/%I64d\n",a/d,b/d);
            continue;
        }
        if(a == 1)
        {
            printf("1/%I64d\n",b-1);
            continue;
        }

        while(x < 0)
            x += b;
        d1 = x;
        c1 = (a * d1 - 1LL) / b;

        while(y < 0)
            y += a;
        c2 = y;
        d2 = (b * c2 - 1LL) / a;
        //è¿ä¸ªæä¹å¼ä¹è¿ä¸äºã
        //if(double(a) * 2.0 /(double) b + EPS < double(c1) / double (d1) + double (c2) / double(d2))
        if(d1 > d2)
            printf("%I64d/%I64d\n",c1,d1);
        else
            printf("%I64d/%I64d\n",c2,d2);
    }
    return 0;
}
