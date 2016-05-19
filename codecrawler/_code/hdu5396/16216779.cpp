#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef long long LL;

const int MAXN=110;
const int INF=0x3f3f3f3f;
const LL MOD=1e9+7;

int T,N;
int a[MAXN];
LL dp[MAXN][MAXN],t[MAXN][MAXN],C[MAXN][MAXN];
char str[MAXN];

void getC(){
    for(int i=0;i<MAXN;i++){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
    }
}

LL dfs(int l,int r){
    LL& ret=dp[l][r];
    if(ret!=-1) return ret;
    if(l==r){
        t[l][r]=1;
        return ret=a[l];
    }
    ret=0;
    t[l][r]=0;
    for(int i=l;i<r;i++){
        LL n1=dfs(l,i),n2=dfs(i+1,r),t1=t[l][i],t2=t[i+1][r];
        LL n=0;
        if(str[i]=='+') n=(n1*t2%MOD+n2*t1%MOD)%MOD;
        else if(str[i]=='-') n=(n1*t2%MOD-n2*t1%MOD+MOD)%MOD;
        else if(str[i]=='*') n=(n1*n2%MOD)%MOD;
        int f1=i-l,f2=r-i-1;
        n=n*C[f1+f2][f1]%MOD;
        ret=(ret+n)%MOD;
        t[l][r]=(t[l][r]+(t1*t2%MOD*C[f1+f2][f1]))%MOD;
    }
    return ret;
}

int main(){
    getC();
    while(scanf("%d",&N)!=EOF){
        for(int i=1;i<=N;i++) scanf("%d",&a[i]);
        scanf("%s",str+1);
        memset(dp,-1,sizeof(dp));
        printf("%I64d\n",dfs(1,N));
    }
    return 0;
}