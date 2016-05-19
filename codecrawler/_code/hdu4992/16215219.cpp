#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 1000000;
bool f[N];
int phi(int x){
    if(f[x])    return x-1;
    int ans = x;
    for(int i=2; i<=x; i++){
        if(x%i==0){
            while(x%i==0)   x/=i;
            ans = ans - ans/i;
        }
    }
    if(x>1) ans = ans - ans/x;
    return ans;
}
int gcd(int a, int b){
    swap(a,b);
    int c = a%b;
    while(c){
        a=b; b=c; c=a%b;
    }
    return b;
}
int quick_mod(int x, int p, int mod){
    long long s = 1;
    long long a = x;
    while(p){
        if(p&1) s = (s*a)%mod;
        a = a*a%mod;
        p>>=1;
    }
    return (int)s;
}
vector<int> V;
vector<int> G;
void cal(int x){
    G.clear();
    if(f[x])    return;
    else{
        for(int i=2; i*i<=x; i++){
            if(x%i==0){
                G.push_back(i);
                if(i*i!=x)  G.push_back(x/i);
            }
        }
    }
}
bool exist(int n){
    if(n%2==0)  n/=2;
    if(f[n])    return 1;
    for(int i=3; i*i<=n; i+=2){
        if(n%i==0){
            while(n%i==0)   n/=i;
            return n==1;
        }
    }
    return 0;
}
void solve(int n){
    if(n==2){
        puts("1");
        return;
    }
    if(n==4){
        puts("3");
        return;
    }
    if(!exist(n)){
        puts("-1");
        return;
    }
    int p = phi(n);
    cal(p);
    int x = -1;
    for(int i=2; i<n; i++){
        bool flag = 1;
        if(quick_mod(i, p, n)!=1)   continue;
        for(int j=0; j<G.size(); j++){
            if(quick_mod(i, G[j], n)==1){
                flag = 0;
                break;
            }
        }
        if(flag){
            V.resize(1);
            V[0] = x = i;
            break;
        }
    }
    if(x==-1){
        puts("-1");
        return;
    }
    for(int i=2; i<p; i++){
        if(gcd(i, p)==1)    V.push_back(quick_mod(x, i, n));
    }
    sort(V.begin(), V.end());
    vector<int>::iterator it=unique(V.begin(), V.end());
    V.erase(it, V.end());
    for(int i=0; i<V.size(); i++){
        if(i)   putchar(' ');
        printf("%d", V[i]);
    }
    puts("");
}
int main(){
    memset(f, 1, sizeof(f));
    f[0] = f[1] = 0;
    for(int i=2; i<N; i++){
        if(f[i]){
            for(int j=i<<1; j<N; j+=i)  f[j]=0;
        }
    }
    int n;
    while(~scanf("%d", &n)) solve(n);
    return 0;
}
