#include<stdio.h>
int main()
{
    int n,w,d,weight;
    int sum;
    while(scanf("%d%d%d%d",&n,&w,&d,&weight)!=EOF)
    {
        sum=n*(n-1)/2*w;//è¿ä¸ªå¬å¼ 
        if(sum==weight)//å«å¿äºè¿ä¸ªå¤å®æ¡ä»¶ 
        printf("%d\n",n);
        else
        printf("%d\n",(sum-weight)/d/*å ä¸è¿ä¸ªå¬å¼*/);
    }
    return 0;
}