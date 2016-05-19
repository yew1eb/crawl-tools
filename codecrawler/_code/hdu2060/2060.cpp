#include<stdio.h>
int f(int n){
    int i,sum;
    sum=0;
if(n<7){
    for(i=0;i<n;i++)
        sum=sum+7-i;
        return sum;
}
else {
    sum=(n-6)*8+27;
    return sum;
}
}
int main (void){
    int t,n,a,b;
while(scanf("%d",&t)!=EOF){
    while(t--){
            scanf("%d%d%d",&n,&a,&b);
        if(a+f(n)>=b)printf("Yes\n");
        else printf("No\n");
    }

}
return 0;
}