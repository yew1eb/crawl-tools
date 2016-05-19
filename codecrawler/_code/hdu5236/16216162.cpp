#include <iostream>
#include <cstdio>
#include <string.h>
#include <cstring>
using namespace std;
const int N=100005;
double dp[N];
double p;
int n,x;
void solve(){
    for(int i=1;i<=n;i++){
        dp[i]=(dp[i-1]+1)/(1-p);
    }
    double mi=(1<<30);
    for(int i=1;i<=n;i++){
        int a=n/i,b=n%i;
        mi=min(mi,dp[a+1]*b+dp[a]*(i-b)+x*i);
    }
    printf("%.6lf\n",mi);
}
int main(){
    dp[0]=0;
    int t,ks=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d%lf%d",&n,&p,&x);
        printf("Case #%d: ",ks++);
        solve();
    }
    return 0;
}
