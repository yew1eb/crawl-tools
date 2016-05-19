#include<stdio.h>
#define N 1005
int a[N],b[N];
int main(){
    int n,i,x;
    while(~scanf("%d",&n)){
        for(i=1;i<=(n-1)*n/2;i++)
            scanf("%d",&a[i]);
        x=(a[1]+a[2]-a[n])/2;//å ä¸ºæ°åæ¯ä»å°å°å¤§çï¼æä»¥x1+x2=a[1],x1+x3=a[2],x2+x3=a[n];
                //å°±å¯ä»¥æ±åºx1, 
        printf("%d\n",x);
        for(i=1;i<n;i++)
            printf("%d\n",a[i]-x);
    }
    return 0;
}