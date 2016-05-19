#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 200000 + 1000;
int a[maxn];
int ans[maxn][2];
int n;

int main() {
    while(~scanf("%d", &n)&&n) {
        int sum = 0;
        for(int i=0; i<n; ++i) {
            scanf("%d", &a[i]);
            sum ^= a[i];
        }
        int Cnt = 0;
        for(int i=0; i<n; ++i)
            if(a[i] > (sum^a[i]) ) {
                ans[Cnt][0] = a[i];
                ans[Cnt][1] = sum^a[i];
                Cnt++;
            }
        if(Cnt == 0) printf("No\n");
        else {
            printf("Yes\n");
            for(int i=0; i<Cnt; ++i)
                printf("%d %d\n", ans[i][0], ans[i][1]);
        }
    }
    return 0;
}
