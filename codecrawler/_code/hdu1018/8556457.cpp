#include <cstdio>
#include <cmath>
#define PI acos(-1)
using namespace std;
int main() {
    int T, n, len;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        if(n==1) len = 1;
        else {
            len = (int)ceil((n*log(n)-n+log(2*n*PI)/2)/log(10));
        }
            printf("%d\n",len);
        }
    return 0;
}
