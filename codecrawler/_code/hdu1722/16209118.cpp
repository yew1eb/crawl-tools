/*
å¬å¼q+p-gcd(p,q) 
gcd æ±ä¸¤ä¸ªæ°çæå¤§å¬çº¦æ° ä¹å°±æ¯ä¸¤ç§åæ³éå¤çé¨å 
åæèç³åæqä»½ï¼ç¶åæèç³æ¼å¨ä¸èµ·ï¼ç¶åååæpä»½ã
åæqä»½éè¦åqåï¼åæpä»½éè¦åpåï¼ä½æ¯ä¼æéå¤ï¼åå»éå¤çé¨åå°±æ¯gcd(p,q)
æä¹æ¯çäºhttp://blog.csdn.net/niushuai666/article/details/7011139ææç½ç 
*/
#include <stdio.h>
int gcd(int m,int n)
{
    int a=m;
    while(m!=0)
    {
        a=n%m;
        n=m;
        m=a;
    }
    return n;
}
int main()
{
    int p,q,x;
    while(scanf("%d%d",&p,&q)!=-1)
    {
        printf("%d\n",p+q-gcd(p,q));
    }
    return 0;
}
