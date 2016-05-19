#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<vector>
#define C    240
#define TIME 10
#define inf 1<<25
#define LL long long
using namespace std;
//保存2的幂
int fac[15]={2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
void slove(int n,int m,int p){
    //金币够贿赂的情况
    if(n<=2*m){
        //不是决策者，而且奇偶性相同，都能被贿赂
        if(n!=p&&(n%2==p%2))
            printf("1\n");
        //剩下的都是决策者拥有
        else if(n==p)
            printf("%d\n",m-(n-1)/2);
        else
        //其余人分不到金币，他们的决策不影响全局
            printf("0\n");
        return ;
    }
    //这时候的不同在于决策者不能拿金币
    else if(n==2*m+1){
        if(p<2*m&&p&1)
            printf("1\n");
        else
            printf("0\n");
        return ;
    }
    int t=n-2*m,i;
    //这是刚好保命的情况，对于决策者来说，肯定没有金币
    //对于其它人来说，要么肯定没有金币，要么可能没有金币，不确定性
    for( i=0;i<14;i++){
        if(t==fac[i]){
            printf("0\n");
            return;
        }
    }
    for( i=1;i<14;i++)
        if(t<fac[i]){
            //决策者必死
            if(p>2*m+fac[i-1]&&p<2*m+fac[i])
                 printf("Thrown\n");
            else
                 printf("0\n");
            return ;
        }
}
int main(){
    int t,n,m,p;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&p);
        slove(n,m,p);
    }
    return 0;
}