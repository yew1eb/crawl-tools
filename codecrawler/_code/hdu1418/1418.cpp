#include<stdio.h>

long long n,m;

int main(){
    while(scanf("%I64d%I64d",&n,&m)){
        if(n==0 && m==0)
            break;
        printf("%I64d\n",n+m-2);
    }
    return 0;
}