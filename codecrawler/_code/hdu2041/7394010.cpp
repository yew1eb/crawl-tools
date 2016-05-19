//hdu 2041
#include<stdio.h>
int main(){
    int n,x;
    __int64 f[41]={0};
    scanf("%d",&n);
    f[0]=0;f[1]=1;
    for(x=2;x<=40;x++)f[x]=f[x-1]+f[x-2];
    f[1]=0;
    while(n--){
         scanf("%d",&x);
         printf("%I64d\n",f[x]);
    }
    return 0;
}
    
