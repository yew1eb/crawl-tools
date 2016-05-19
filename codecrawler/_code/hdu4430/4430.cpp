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
        sum=sum*k;//sum*k可能会溢出 
        ans+=sum;
        if(ans>n)return ans;//ans大于n直接返回 
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
        for(LL i=2;i<=60;++i){//枚举r然后对k进行二分查找,因为k>?=2,2^60>10^12,所以i只要枚举到60即可 
            LL k=search(i);
            if(k != -1 && i*k<a*b){a=i,b=k;}
        }
        printf("%I64d %I64d\n",a,b);
    }
    return 0;
}