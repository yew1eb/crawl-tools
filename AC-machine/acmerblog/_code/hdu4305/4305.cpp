#include<iostream>
#include<algorithm>
#include<cassert>
#include<cstdio>
#include<complex>
#include<cmath>
using namespace std;
// geometry
const double eps = 1e-9;
const int N = 300 + 10;
#define X real
#define Y imag
typedef complex <double> pnt;
pnt num[N];
static double cross (const pnt &a, const pnt &b) { return Y(conj(a) * b);}
pair <double,int> hash[N];
int tp;
bool cmp(const pair<double,int> &a , const pair<double,int> &b){
    #define  ff first
    #define  ss second
    return (a.ff - b.ff) < eps ? abs(num[a.ss] - num[tp]) < abs(num[b.ss] - num[tp]): a.ff < b.ff;
}
// lcm
const int mod = 10007;
int G[N][N],vis[N];
int gcd(int a,int b) { return b ? gcd(b , a%b) : a;}
int lcm(int a,int b){
    return a * b / gcd(a,b);
}
// exgcd
int res[mod];
void exgcd(int a,int b,int &x,int &y){
    if( b== 0) {
        x = 1; y = 0; return ;
    }
    exgcd(b, a%b, x, y);
    int t = y; y = x - a/b*y; x = t;
}
int cal_res(int v) {
    int x, y;
    exgcd(v, mod, x, y);
    return (x + mod) % mod;
}
// main
int main(){
    int test;
    cin >> test ;
    for(int i=1;i<mod;i++) res[i] = cal_res(i);
    while(test -- ){
        int n,r;
        scanf("%d%d",&n,&r);
        for(int i=0;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            num[i] = pnt(x,y);
        }
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) G[i][j] = 0;
        for(tp=0;tp<n;tp++) {
            int len = 0;
            for(int j=0; j< n;j ++) if(tp != j) 
                hash[len ++] = make_pair(arg(num[j] - num[tp]),j);
            sort(hash, hash + len);
            for(int j=0; j<len; j++) if(!j || abs(hash[j].first - hash[j-1].first) > eps) {
                int v = hash[j].second;
                if(abs(num[tp] - num[v]) < r + eps){
                    G[tp][v] = mod - 1;
                    G[tp][tp] ++;
                }
            }
        }
        // gauss
        n --;
        int ans = 1;
        for(int i=0;i<n;i++) vis[i] = 0;
        for(int i=0;i<n;i++) {
            int s = -1;
            for(int j=0;j<n;j++) if(!vis[j] && G[j][i]){
                s = j; break;
            }
            if(s == -1) {
                ans = 0;
                break;
            }
            ans = (ans * G[s][i]) % mod;
            vis[s] = 1;
            for(int j=0;j<n;j++) if(!vis[j] && G[j][i]) {
                int c = lcm(G[j][i], G[s][i]);
                int t = c / G[j][i];
                int p = c / G[s][i];
                assert(t < mod);
                ans = (ans * res[t]) % mod;
                for(int k = i; k< n; k++) {
                    G[j][k] = (G[j][k] * t - G[s][k] * p) % mod;
                    G[j][k] = (G[j][k] + mod) % mod;
                }
            }
        }
        cout << (ans == 0 ? -1 : ans) << endl;
    }
}