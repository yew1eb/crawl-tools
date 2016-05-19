#include <stdio.h>
#include <string.h>
#include <math.h>
//#include <algorithm>
//using namespace std;

int prime[65535];

void hash() {
    int i,j;
    memset(prime, 1, sizeof(prime));
    for(i=2; i<65535; i++)
        for(j=2; j*i<65535; j++) {
            if(prime[i])
                prime[i*j] = 0;
        }
    prime[0] = prime[1] = 0;
}

int main() {
    hash();
    int ans[60000];
    int n,i,tmp;
    while(scanf("%d",&n)!=EOF) {
        if(!n) break;
        //memset(ans, 0, sizeof(ans));
        tmp = 0;
        for(i=65535; i>0; i--) {
            if(prime[i] && n%i==0) {
                ans[tmp++] = i;
                n/= i++;
            }
        }
        //sort(ans[0], ans[0+tmp]);
        printf("%d",ans[tmp-1]);
        for(i=tmp-2; i>=0; i--) {
            printf("*%d",ans[i]);
        }
        puts("");
    }
    return 0;
}