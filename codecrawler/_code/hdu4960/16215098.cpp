#include<cstdio>
#include<algorithm>
using namespace std;
#define INF 0x3fffffff
const int N = 5005;
int n, v[N], a[N];
int dp[N];
int L[N], R[N], num;  //L[]åR[]è®°å½å³é®ç¹
void Init()
{
    num = 0;
    int l = 1, r = n, l_num = 1, r_num = 1;
    int l_val = v[1], r_val = v[n];
    while(l < r) {
        if(l_val < r_val) {
            l_val += v[++l];
            l_num++;
        }
        else if(l_val > r_val) {
            r_val += v[--r];
            r_num++;
        }
        else {
            L[++num] = l_num;
            R[num] = r_num;
            l_num = r_num = 1;
            l_val = v[++l];
            r_val = v[--r];
        }
    }
}
int main()
{
    while(~scanf("%d",&n) && n) {
        for(int i = 1; i <= n; ++i) scanf("%d",&v[i]);
        for(int i = 1; i <= n; ++i) scanf("%d",&a[i]);
        Init();
        for(int i = 1; i <= num; i++) {
            int num1 = 0, num2 = 0;
            dp[i] = INF;
            for(int j = i; j >= 1; --j) {
                num1 += L[j];
                num2 += R[j];
                dp[i] = min(dp[i], dp[j-1] + a[num1] + a[num2]);
            }
        }
        int ans = a[n], cnt = n;
        for(int i = 1; i <= num; ++i) {
            cnt -= L[i] + R[i];
            ans = min(ans, dp[i] + a[cnt]);
        }
        printf("%d\n", ans);
    }
    return 0;
}