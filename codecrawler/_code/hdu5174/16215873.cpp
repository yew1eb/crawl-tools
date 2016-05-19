#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef __int64 ll;
int const MAXX=2147483647;
ll has[100],n[110],n1[110];
int main(){
    int t;
    int ss = 0;
    while(~scanf("%d",&t)){
        memset(has,0,sizeof(has));
        memset(n,0,sizeof(n));
        memset(n1,0,sizeof(n1));
        ll s = 0;
        for(int i = 0;i < t;i++){
            scanf("%I64d",&has[i]);
        }
        for(int i = 0;i < 101;i++){
            n1[i] = 1;
        }
        sort(has,has + t);
        int cnt = 0;
        n[0] = has[0];
        for(int i = 1;i < t;i++){
            if(has[i - 1] != has[i]){
                n[++cnt] = has[i];
            }
            else n1[cnt]++;
        }
        if(cnt == 0) s = -1;
        else{
            for(int i = 0;i <= cnt;i++){
                ll l,r;
                if(i == 0){
                    l = n[cnt];
                    r = n[i + 1];
                }
                else if(i == cnt){
                    r = n[0];
                    l = n[cnt - 1];
                }
                else{
                    l = n[i - 1];
                    r = n[i + 1];
                }
                if((l + n[i]) % MAXX == r) s += n1[i];
            }
        }
        printf("Case #%d: %I64d\n",++ss,s);
    }
    return 0;
}
