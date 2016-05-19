#include<stdio.h>
#define min(a,b) (a<b?a:b)
#define min4(a,b,c,d) min(min(a,b),min(c,d))
int a[5850];//å­æ¾ä¸æ°

int main()
{
    int n=1;
    int p2,p3,p5,p7;
    p2=p3=p5=p7=1;//2,3,5,7çè®¡æ°å¨
    a[1]=1;
    while(a[n]<2000000000)//ä»2å¼å§éæ¨è®¡ç®ï¼ä¸å±5842ä¸ªä¸æ°
    {
        a[++n] = min4(2*a[p2],3*a[p3],5*a[p5],7*a[p7]);//åæå°å¼ï¼ç¸åºçè®¡æ°å¨å 1
        if(a[n]==2*a[p2]) p2++;
        if(a[n]==3*a[p3]) p3++;
        if(a[n]==5*a[p5]) p5++;
        if(a[n]==7*a[p7]) p7++;
    }
    while(scanf("%d",&n) && n)
    {
        if(n%10 == 1&&n%100!=11)
        printf("The %dst humble number is ",n);
        else if(n%10 == 2&&n%100!=12)
        printf("The %dnd humble number is ",n);
        else if(n%10 == 3&&n%100!=13)
        printf("The %drd humble number is ",n);
        else
        printf("The %dth humble number is ",n);
        printf("%d.\n",a[n]);
    }
    return 0;

}
