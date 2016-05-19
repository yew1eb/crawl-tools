#include<stdio.h>
int main()
{
    int n,t,p;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        p=0;
        while(n%2==0) //å¥æ°é¤ä»¥2ä½æ°ä¸º1
        {
            p++; //è®°å½æ¬¡æ°
            n/=2;
        }
        printf("%d %d\n",n,p);
    }
    return 0;
}