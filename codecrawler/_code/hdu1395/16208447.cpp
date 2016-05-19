#include<stdio.h>

int main(){
    int x,n,t;
    while(scanf("%d",&n)!=EOF){
        if(n==1 || n%2==0){
            //ä¸å­å¨è¿æ ·çx
            printf("2^? mod %d = 1\n",n);
        }else{
            x=1;
            t=2;
            //æ´åæ¾å°æå°çxä½¿å¾2^x mod n=1
            while(t%n!=1){
                x++;
                t=t*2%n;
            }
            printf("2^%d mod %d = 1\n",x,n);
        }
    }    
    return 0;
}