#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
#define mod 10007
__int64 prime[100005],num[100005];
int main(){
    __int64 a,b,i,j,k,cur=1,ans,sumsum;
    __int64 x,y;
    k=0;
    memset(prime,0,sizeof(prime));
    for(i=2;i<=100000;i++){
        if(!prime[i])
        num[k++]=i;
        for(j=0;j<k&&num[j]*i<=100000;j++){
            prime[num[j]*i]=1;
            if(i%num[j]==0)
            break;
        }
    }
    while(scanf("%I64d%I64d",&a,&b)!=EOF){
        ans=1;
        j=0;
        for(i=0;num[i]*num[i]<=a;i++){
            if(a%num[i]==0){                            //åè§£ç´ å å­
                j=0;
                while(a%num[i]==0){
                a/=num[i];
                j++;
                }
                sumsum=(b*j+1)*(b*j+2)/2%10007;         //ç«æ¹åå¬å¼ä¸º(n*n)*(n+1)*(n+1)/4
                sumsum*=sumsum;
                ans=ans*sumsum%10007;
            }
        }
        if(a>1){
        sumsum=(b+1)*(b+2)/2%10007;
        sumsum*=sumsum;
        ans=ans*sumsum%10007;
        }
        printf("Case %I64d: %I64d\n",cur++,ans);
    }
    return 0;
}
