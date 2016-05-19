#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define N 100010
#define MAX 1000010


int T, a, b, n;

int main() {

    while(~scanf("%d",&n)) {
        for(int i = 0; i < n; ++i){
            scanf("%d%d",&a,&b);
            if(a<b){
                printf("impossible\n");continue;
            }
            if((a%2==0&&b%2==0)||(a%2&&b%2)){
                printf("%d %d\n",b+(a-b)/2,a-b-(a-b)/2);
            }
            else {
                printf("impossible\n");
            }
        }
    }
    return 0;
}
