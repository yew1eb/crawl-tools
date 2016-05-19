#include<stdio.h>
int main(){
    int n,t,i,m[1300],a;
    while(~scanf("%d",&n)){
        t=n*(n-1)/2;
        for(i=0;i<t;i++)
            scanf("%d",m+i);
        printf("%d\n",a=(m[0]+m[1]-m[n-1])/2);
        for(i=0;i<n-1;i++)
            printf("%d\n",m[i]-a);
    }
}
