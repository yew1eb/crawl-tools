#include <bits/stdc++.h>
#define uLL unsigned long long
#define LL long long
#define FOR(i,x,y)  for(int i = x;i < y;++ i)
#define IFOR(i,x,y) for(int i = x;i > y;-- i)

using namespace std;

const int maxn = 100010;
int prime[maxn];
bool check[maxn];

void Get_Prime(){
    memset(check,false,sizeof(check));
    prime[0] = 0;
    FOR(i,2,maxn){
        if(!check[i]){
            prime[++prime[0]] = i;
        }
        FOR(j,1,prime[0]+1){
            if(i*prime[j] > maxn)   break;
            check[i*prime[j]] = true;
            if(i%prime[j] == 0) break;
        }
    }
}

vector <uLL> fac;
int p[30],p_len,cnt[30];

void dfs(int wei,int u){
    if(wei >= p_len)    {fac.push_back(u);  return;}
    dfs(wei+1,u);
    int q = p[wei];
    FOR(i,0,cnt[wei]){
        dfs(wei+1,u*q);
        q = q*p[wei];
    }
}

int n;

void work(){
    uLL res = (uLL)n;
    p_len = 0;
    memset(cnt,0,sizeof(cnt));
    FOR(i,1,prime[0]+1){
        if(prime[i] > n/prime[i])   break;
        if(n%prime[i] == 0) p[p_len++] = prime[i];
        while(n%prime[i] == 0)  {cnt[p_len-1] ++;n /= prime[i];}
    }
    if(n > 1)   {p[p_len++] = n;cnt[p_len-1] = 1;}
    FOR(i,0,p_len){
        res *= ((uLL)cnt[i]+1);
    }
    fac.clear();
    dfs(0,1);
    uLL ans = 0;
    FOR(i,0,(int)fac.size()){
        uLL v = fac[i];
        ans += v*v;
    }
    ans = ans - res;
    cout<<ans<<endl;
}

int main(){
    //freopen("test.in","r",stdin);
    Get_Prime();
    int T;  scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        work();
    }
    return 0;
}