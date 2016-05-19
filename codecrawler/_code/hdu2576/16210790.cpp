#include <cstdio>
int main(){
    int t;
    __int64 n,s;
    for(scanf("%d",&t);t--;){
        scanf("%I64d",&n);
        s=n*(n+1)/2%(20090524*3);
        s=s*(n+2)/3%20090524;
        printf("%I64d\n",s);
    }
    return 0;
}