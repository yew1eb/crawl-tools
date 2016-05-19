#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<cmath>
#define LL  long long
#define MOD 100
#define eps 1e-6
#define N 100010
#define zero(a)  fabs(a)<eps
using namespace std;
int PowMod(int a,LL b){
    int ret=1;
    while(b){
        if(b&1)
            ret=(ret*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ret;
}
int main(){
    int t;
    while(scanf("%d",&t)!=EOF&&t){
        int cas=0;
        LL n;
        while(t--){
            scanf("%I64d",&n);
            printf("Case %d: %d\n",++cas,(PowMod(4,n-1)+PowMod(2,n-1))%MOD);
        }
        printf("\n");
    }
    return 0;
}
