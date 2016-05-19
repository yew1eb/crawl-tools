#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 123333;
int MAX[MAXN][20], MIN[MAXN][20];
int mm[MAXN];

void initRMQ(int n, int b[])
{
    mm[0] = -1;
    for(int i=1; i<=n; ++i) {
        mm[i] = ((i&(i-1)) == 0) ? mm[i-1]+1:mm[i-1];
        MAX[i][0] = MIN[i][0] = b[i];
    }
    for(int j=1; j<= mm[n]; ++j) 
        for(int i=1; i+(1<<j)-1 <= n; ++i){
            MAX[i][j] = max(MAX[i][j-1], MAX[i+(1<<(j-1))][j-1]);
            MIN[i][j] = min(MIN[i][j-1], MIN[i+(1<<(j-1))][j-1]);
        }
}

int rmq(int x, int y) {
    int k = mm[y - x + 1];
    int Max = max(MAX[x][k], MAX[y-(1<<k)+1][k]);
    int Min = min(MIN[x][k], MIN[y-(1<<k)+1][k]);
    return Max - Min;
    //printf("(%d,%d);%d %d\n",x, y, Max, Min);
}

int main()
{
    int n, k, T;
    int a[MAXN];
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &k);
        for(int i=1; i<=n; ++i) {
            scanf("%d", &a[i]);
        }
        initRMQ(n, a);
        long long ans = 0;
        int l, r, mid;
        for(int i=1; i<=n; ++i) {
            l = i, r = n;
            while(l+1 < r) {
                mid = (l+r)>>1;
                if( rmq(i, mid) < k) {
                    l = mid;
                }else {
                    r = mid;
                }   
            }
            if( rmq(i, r) < k)
                ans += (r - i + 1);
            else 
                ans += (l - i + 1);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

