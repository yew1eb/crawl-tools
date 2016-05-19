#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Bignb{
    long long high,low;
    void print(int& cas)
    {
        if(high<=0)
        {
            printf("Case #%d: %I64d\n",++cas,low);
        }
        else {
            printf("Case #%d: %I64d%012I64d\n",++cas,high,low);
        }
    }
};
const long long mod1=1e6;
const long long mod2=1e12;
int main()
{
    int T,cas=0;
    //  freopen("data.in","r",stdin);
    scanf("%d",&T);
    while (T--)
    {
        long long tp;
        scanf("%I64d",&tp);
        if(tp<1e9){
            printf("Case #%d: %I64d\n",++cas,tp*(8*tp-7)+1);
        }
        else {
            long long tp1=tp%(mod1),tp2=tp/(mod1),temp=16*tp1*tp2-7*tp2;
            Bignb ans;
            ans.high=8*tp2*tp2;
            ans.low=8*tp1*tp1-7*tp1+1;
            ans.low+=(mod1)*(temp%mod1);
            ans.high+=(temp/mod1);
            if(ans.low<0){
                ans.low+=mod2;
                ans.high--;
            }
            else {
                ans.high+=ans.low/mod2;
                ans.low=ans.low%mod2;
            }
            ans.print(cas);
        }
    }
    return 0;
}