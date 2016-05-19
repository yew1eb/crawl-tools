#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL mod = 1e9 + 7;
const LL Inv = (mod + 1) / 2;
const int N = 100005;
struct Node{
    LL x,y;
    Node(){}
    Node(LL x,LL y):x(x),y(y){}
    Node operator - (const Node &a)const{
        return Node((x - a.x + mod) % mod,(y - a.y + mod) % mod);
    }
    Node operator + (const Node &a)const{
        return Node((x + a.x) % mod,(y + a.y) % mod);
    }
    Node operator * (const LL &b){
        return Node(x * b % mod,y * b % mod);
    }
    LL operator ^ (const Node &a)const{
        return (x * a.y - y * a.x) % mod;
    }
    void add(){
        scanf("%lld%lld",&x,&y);
    }
};
Node nd[N];
LL Pow[N];
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i ++) nd[i].add();
    Node tmp(0,0),sum(0,0);
    LL res = 0;
    for(int i = 1 ; i < n ; i ++){
        tmp = tmp + nd[i] * (Pow[n - i - 1] - 1);
        if(i != 1) sum = sum + nd[i];
    }
    for(int i = 0 ; i < n ; i ++){
        res += nd[i] ^ tmp;
        res %= mod;
        tmp = tmp - nd[i + 1] * (Pow[n - 2] - 1);
        tmp = tmp * 2;
        tmp = tmp + sum;
        sum = sum - nd[(i + 2) % n] + nd[i];
    }
    res = (res + mod) % mod;
    printf("%lld\n",abs(res));
}
int main(){
    Pow[0] = 1;
    for(int i = 1 ; i < N ; i ++)
        Pow[i] = Pow[i - 1] * 2 % mod;
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}