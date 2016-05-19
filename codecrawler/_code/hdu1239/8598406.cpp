#include <stdio.h>
#include <string.h>
#define N 10000
#define INF 0xfffffff
int prime[N],cnt;
bool mark[N];
void sieve() {
    int i,j;
    memset(mark,0,sizeof(mark));
    cnt = 0,prime[cnt++] = 2;
    for(i=3; i<N; i+=2) {
        if(!mark[i]) prime[cnt++] = i;
        for(j=1; j<cnt&&prime[j]*i<N; ++j) {
            mark[i*prime[j]] = 1;
            if(!(i%prime[j])) break;
        }
    }
}
int main() {
    int m ,a ,b, i, j;
    double s;
    int sub,tmp;
    sieve();
    while(scanf("%d%d%d",&m,&a,&b),a+b+m) {
        s  = (double)a/b;
        sub = -INF;
        for(i=cnt-1; i>=0; i--)
            for(j=i; j<cnt; j++) {
                if(prime[j]>m||prime[j]*prime[i]>m||(double)prime[i]/prime[j]<s)
                    continue;
                tmp = prime[i]*prime[j];
                if(tmp>sub) {
                    sub=tmp;
                    a= prime[i];
                    b=prime[j];
                }
            }
        printf("%d %d\n",a,b);

    }
    return 0;
}
