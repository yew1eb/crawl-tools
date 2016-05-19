#include <cstdio>
#include <algorithm>
#include <functional>//less<int>(), greater<int>();
using namespace std;
int a[1005], b[1005];
int n;
int main() {
    int ans, i, f1, f2, r1, r2;
    while(scanf("%d",&n),n) {
        for(i=0; i<n; i++)  scanf("%d",&a[i]);
        sort(a,a+n,greater<int>());
        for(i=0; i<n; i++)  scanf("%d",&b[i]);
        sort(b,b+n,greater<int>());
        f1=f2 = 0;
        r1 = r2 = n-1;
        ans = 0;
        while(f1<=r1) {
            if(a[f1]>b[f2]) {
                f1++;
                f2++;
                ans +=200;
            } else if(a[f1]<b[f2]) {
                f2++;
                r1--;
                ans -=200;
            } else {
                if(a[r1]>b[r2]) {
                    r1--;
                    r2--;
                    ans +=200;
                } else {
                    if(a[r1]<b[f2]) {
                        ans -=200;
                    }
                    r1--;
                    f2++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
