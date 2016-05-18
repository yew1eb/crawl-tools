#include <stdio.h>
 int main()
{
    int i, a, b, c, d;
    while (scanf("%d %d %d %d",&i,&a,&b,&c)!=EOF)
    {
        if (i+a+b+c==0)
        break;

        d = 720+360 + (a>i?(40-a)+i:(i-a))*9 + (b<a?(40-a)+b:(b-a))*9 + (c>b?(40-c)+b:(b-c))*9;

        printf("%d\n",d);
    }
    return 0;
}