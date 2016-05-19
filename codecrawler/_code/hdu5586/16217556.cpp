#include <cstdio>
#include <algorithm>

using namespace std;

int n,num,i,dp[2][3];//dp[i&1][0]è¡¨ç¤ºå½åè¿æªè¿å¥ç½®æ¢åºé´ï¼dp[i&1][0]è¡¨ç¤ºå½åå¤äºç½®æ¢åºé´ï¼dp[i&1][2]è¡¨ç¤ºå½åå·²åºç½®æ¢åºé´

inline int f() {
    return (1890*num+143)%10007;
}

int main() {
    while(1==scanf("%d",&n)) {
        dp[0][0]=dp[0][1]=dp[0][2]=0;
        for(i=1;i<=n;++i) {
            scanf("%d",&num);
            dp[i&1][0]=dp[(i-1)&1][0]+num;
            dp[i&1][1]=max(dp[(i-1)&1][0],dp[(i-1)&1][1])+f();
            dp[i&1][2]=max(dp[(i-1)&1][1],dp[(i-1)&1][2])+num;
        }
        printf("%d\n",max(dp[n&1][0],max(dp[n&1][1],dp[n&1][2])));
    }
    return 0;
}
