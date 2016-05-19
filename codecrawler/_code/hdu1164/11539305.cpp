#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int facs[1000], cnt;
int n;

void factor(int n) {
    cnt = 0;
    int m = (int)sqrt(n + 0.5);
    for(int i=2; i<=m; i += 2) {
        while(!(n%i)) {
            n /= i;
            facs[cnt++] = i;
        }
        if(i==2) i--;
    }
    if(n>1) facs[cnt++] = n;
}
int main() {
    while(~scanf("%d", &n)) {
        factor(n);
        for(int i=0; i<cnt; ++i) {
            printf("%d", facs[i]);
            if(i<cnt-1) printf("*");
            else printf("\n");
        }
    }
    return 0;
}
