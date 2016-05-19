#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long ll;

int main(){
    int a,b;
    char s[10];
    while(scanf("%d%s",&a,s)!=EOF){
        int i,l = strlen(s),pp = 1,yl;
        ll x,ss,ans = -1,tt;
        if(s[0]=='0' && l==1){
            printf("0\n");
            continue;
        }
        for(i = 1; i <= l; i++)
            pp *= 10;
        sscanf(s,"%I64d",&ss);
        for(yl = 1; yl <= 10000; yl *= 10){
            for(x = (s[0]=='0'); x < a; x++){
                tt = (x*pp+ss)*yl;
                int mod = (a-tt%a)%a;
                if (mod < yl){
                    tt += mod;
                    if(ans < 0 || tt < ans)
                        ans=tt;
                }
            }
        }
        printf("%lld\n",ans/a);
    }
    return 0;
}
