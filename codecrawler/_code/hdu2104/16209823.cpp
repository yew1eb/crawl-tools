#include <stdio.h>

int gcd(int m,int n){
    int r;
    while(r=m%n){
        m=n;
        n=r;
    }
    return n;
}

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m),m!=-1||n!=-1){
        if(gcd(m,n)==1)
            puts("YES");
        else
            puts("POOR Haha");
    }
    return 0;
}