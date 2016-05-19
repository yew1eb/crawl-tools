/*

Ìâ½â£º

*/
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {
    int n, m;
    while(~scanf("%d%d", &n, &m)) {
        int sum = 0;
        for(int i=0; i<n; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            sum ^= (abs(x-y)-1);
        }

        if(sum==0) puts("BAD LUCK!");
        else puts("I WIN!");
    }
    return 0;
}
