#include<stdio.h>
#include<string.h>
__int64 f[100005],i,n;  //iä¹è¦64ä½
int main()
{
    memset(f,0,sizeof(f));
    f[1]=1;
    for(i=2; i<=100002; i++)
        if(i%3==0) f[i]=f[i-1]+i*i*i;
        else f[i]=f[i-1]+i;
    while(~scanf("%I64d",&n) && n>=0) {
        printf("%I64d\n",f[n]);
    }
    return 0;
}