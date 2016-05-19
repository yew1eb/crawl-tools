#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include<map>
#include <iostream>
#include <algorithm>
using namespace std;
#define RD(x) scanf("%d",&x)
#define RD2(x,y) scanf("%d%d",&x,&y)
#define clr0(x) memset(x,0,sizeof(x))
typedef long long LL;
int n;
int s[100005];

int main() {
    int n,_;
    RD(_);
    for(int cas = 1;cas <= _;++cas){
        printf("Case #%d: ",cas);
        RD(n);
        for(int i = 0;i < n;i++){
            RD(s[i]);
        }
        LL ans = 0,cnt = 0;
        sort(s,s+n);
        for(int j = n-1;j>=0;--j){
            if (cnt >= s[j])
                cnt -= s[j];
            else{
                cnt = s[j] - cnt;
                ans += cnt;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}