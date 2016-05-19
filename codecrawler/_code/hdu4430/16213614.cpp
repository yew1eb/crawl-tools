#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef __int64 LL;
using namespace std;

const int MAX=1000+10;
LL n;

LL cal(LL k,LL r){
    LL sum=1,ans=0;
    for(int i=1;i<=r;++i){
        if(n/sum<k)return n+1; 
        sum=sum*k;//sum*kå¯è½ä¼æº¢åº 
        ans+=sum;
        if(ans>n)return ans;//anså¤§äºnç´æ¥è¿å 
    } 
    return ans;
}

LL search(LL i){
    LL l=2,r=n;
    while(l<=r){
        LL mid=(l+r)>>1;
        LL sum=cal(mid,i);
        if(sum == n-1 || sum == n)return mid;
        if(sum<n-1)l=mid+1;
        else r=mid-1;
    }
    return -1;
}

int main(){
    while(~scanf("%I64d",&n)){
        LL a=1,b=n-1;
        for(LL i=2;i<=60;++i){//æä¸¾rç¶åå¯¹kè¿è¡äºåæ¥æ¾,å ä¸ºk>?=2,2^60>10^12,æä»¥iåªè¦æä¸¾å°60å³å¯ 
            LL k=search(i);
            if(k != -1 && i*k<a*b){a=i,b=k;}
        }
        printf("%I64d %I64d\n",a,b);
    }
    return 0;
}