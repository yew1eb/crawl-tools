#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define maxn 100007
ll num[maxn];
ll pos[maxn][36];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i = 0;i < n; i++){
            scanf("%I64d",&num[i]);
        }

        num[n] = 0;
        for(ll i = 0;i < 36; i++){
            ll di = 1LL<<(i+1);
            ll su = num[0];
            int p = 0;
            for(int j = 0;j < n; j++){
                if(j) su -= num[j-1];
                while(su < di && p < n){
                    su += num[++p];
                }
                pos[j][i] = p;
            }
        }

        ll ans = 0,res;
        for(int i = 0;i < n; i++){
            ll p = i,q;
            for(int j = 0;j < 36 ;j ++){
                q = pos[i][j];
                res = (j+1)*((i+1)*(q-p)+(p+q+1)*(q-p)/2);
                ans += res;
                p = q;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
