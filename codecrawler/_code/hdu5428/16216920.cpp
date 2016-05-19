//author: CHC
//First Edit Time:    2015-09-05 21:23
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <limits>
using namespace std;
typedef long long LL;
const int MAXN=50000+100;
const int INF = numeric_limits<int>::max();
const LL LL_INF= numeric_limits<LL>::max();
int prime[MAXN];
void getprime(){
    memset(prime,0,sizeof(prime));
    for(int i=2;i<MAXN;i++){
        if(!prime[i])prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=MAXN/i;j++){
            prime[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
int res[MAXN*10];
void getfact(int x){
    int tx=x;
    int flag=0;
    for(int i=1;i<=prime[0]&&prime[i]<=x;i++){
        while(x%prime[i]==0){
            flag=1;
            x/=prime[i];
            res[++res[0]]=prime[i];
        }
    }
    if(!flag&&tx!=1)res[++res[0]]=tx;
}
int main()
{
    getprime();
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        res[0]=0;
        for(int i=0,x;i<n;i++){
            scanf("%d",&x);
            getfact(x);
        }
        sort(res+1,res+1+res[0]);
        //for(int i=1;i<=res[0];i++)printf("%d ",res[i]);
        //puts("");
        if(res[0]<=1)puts("-1");
        else printf("%I64d\n",(LL)res[1]*res[2]);
    }
    return 0;
}