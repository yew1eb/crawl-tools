#include<stdio.h>
int main()
{
    int i,n;
    double a[100000];//doubleåï¼æåç²¾ç¡®å°å°æ°ç¹ä¹åçä¸ä½ 
    a[1]=0.5;//ç¬¬ä¸å¼ çº¸çæå¤è¶è¿ç¾åä¹äºå 
    for(i=1;i<100000;i++)//éæ¨å¬å¼ 
    a[i]=a[i-1]+1.0/2/i;
    printf("# Cards  Overhang\n");
    while(~scanf("%d",&n))
    {
        printf("%5d%10.3lf\n",n,a[n]);//è¦ç²¾ç¡®å°å°æ°ç¹åä¸ä½ããã 
    } 
    return 0;
}