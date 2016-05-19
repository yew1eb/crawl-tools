#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
int n;
int a[100005], b[100005];

bool check(int m)
{
    for(int i=0; i<n; ++i) {
        if(!i) {
            b[i] = a[i] - m;
        }else {
            int ll = a[i] - m;
            int rr = a[i] + m;
            if(ll >= b[i-1]+1) {
                b[i] = ll;
            }else if(ll< b[i-1]+1 && b[i-1]+1 <= rr) {
                b[i] = b[i-1] + 1;
            }else {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int cas=1; cas<=T; ++cas){

        scanf("%d", &n);
        for(int i=0; i<n; ++i)
        {
            scanf("%d", a+i);
        }
        int l = 0, r = 1100005, mid;
        while(l < r)
        {
            mid = (l + r) >> 1;
            if(check(mid)) {
                r = mid;
            }else {
                l = mid + 1;
            }
        }
        printf("Case #%d:\n", cas);
        printf("%d\n", r);
    }
    return 0;
}
