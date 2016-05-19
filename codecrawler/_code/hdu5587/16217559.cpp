#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <sstream>
#define f(i,a,b) for(int i = a;i<=b;i++)
#define fi(i,a,b) for(int i = a;i<=b;i--)

using namespace std;

#define LEN 20
#define MOD 10000

long long G[60],a2[60];

long long dfs(long long k){
    if(k == 0) return 0;
    long long i,j;
    for(i = 1;;i++)if(a2[i]>=k) break;
    if(a2[i] == k) return G[i];
    long long cnt = i-1;
    long long sum = G[cnt] + k - a2[cnt];
    return sum + dfs(k - a2[cnt] - 1);
}

int main()
{
//    freopen("data.in","r",stdin);
//    freopen("data.out","w",stdout);
    int N;
    long long kk = 2;
    G[1] = 1;
    a2[1] = 1;
    f(i,1,58){
        G[i+1] = 2*G[i] + kk;
        kk*=2;
        a2[i+1] = kk - 1;
    }
    scanf("%d",&N);
    while(N--){
        long long n;
        scanf("%lld",&n);
        printf("%lld\n",dfs(n));
    }
    return 0;
}
