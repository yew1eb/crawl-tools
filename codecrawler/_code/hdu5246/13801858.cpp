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
ll m, k;
ll a[10005];

int main()
{
    int T;
    scanf("%d", &T);
    for(int cas=1; cas<=T; ++cas){
        printf("Case #%d:\n", cas);
        scanf("%d%I64d%I64d", &n, &m, &k);
        for(int i=0; i<n; ++i) scanf("%I64d", a+i);
        sort(a, a+n);
        if(m<a[0]) {
            puts("madan!");
            continue;
        }
        for(int i=0; i<n; ++i) {
            int j = i;
            for(; j<n && m >= a[j]; ++j);
            m = a[j-1] + k;
            if(k>0) k--;
            if(m < a[j]) break;
            if(i<j) i = j - 1;
        }
        if(m>=a[n-1]) {
            puts("why am I so diao?");
        }else {
            puts("madan!");
        }
    }
    return 0;
}
