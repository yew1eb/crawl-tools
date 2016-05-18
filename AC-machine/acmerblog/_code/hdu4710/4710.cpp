/*分析：对于i%a - i%b,每次加上从i开始和这个值(i%a - i%b)相等的一段,
这样i就不是每次+1,而是每次加上一段,如果碰到n大于a,b的最小公倍数，
则只需要计算a,b最小公倍数长度的总和，然后sum*=n/per + p;//p表示前i个数,p=n%per;

本题反思:刚开始自己就是这样想，但是想到a,b的最小公倍数可能很大,而且n也很大，
如果刚好碰到n<per但是n很大;//per表示a,b最小公倍数，或者碰到n>per但是per很大 
即使一段段的算也可能超时，所以一直不敢下手，一直在找寻更简单的推论。。结果一直没找到
下次碰到这种情况应该先试试，不能找不出别的更简单的方法就连自己想到的方法都不试试

现在认真分析发现时间复杂度好像是:O((a/b * min(per,n)/a));//假设a>=b 
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#include<math.h>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=10;
__int64 p;

__int64 Gcd(__int64 a,__int64 b){
    if(b == 0)return a;
    return Gcd(b,a%b);
}

__int64 calculate(__int64 n,__int64 a,__int64 b,__int64 num){
    p=0;
    __int64 la=a,lb=b,sum=0,l;
    for(__int64 i=0;i<n;){
        l=min(la,min(lb,n-i));
        if(i+l>num && i<num)p=sum+abs((int)(i%a - i%b))*(num-i);
        sum+=abs((int)(i%a - i%b))*l;
        i+=l;
        la=(la-l+a-1)%a+1;
        lb=(lb-l+b-1)%b+1;
    }
    return sum;
}

int main(){
    __int64 n,a,b,t;
    scanf("%I64d",&t);
    while(t--){
        scanf("%I64d%I64d%I64d",&n,&a,&b);
        __int64 gcd=Gcd(a,b),per=a*b/gcd,k=min(per,n);//求出最小公倍数 
        __int64 sum=calculate(k,a,b,n%k);
        if(n>per)sum=(n/per)*sum+p;//p表示前n%k个i%a-i%b的和 
        printf("%I64d\n",sum);
    }
    return 0;
}