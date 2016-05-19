#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <numeric>
#include <sstream>
#include <string>
using namespace std;
#define out(X) cerr << #X << ": " << (X) << endl
#define SZ(X) ((int)(X.size()))
#define REP(I,N) for (int I = 0; I < (N); ++I)
#define FOR(I,L,H) for (int I = (L); I < (H); ++I)
#define MP(X,Y) make_pair((X),(Y))
#define PB push_back
#define ALL(X) X.begin(), X.end()
template <typename T> inline bool checkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template <typename T> inline bool checkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
typedef long long lint;

const int MAXN = 150;
const int MAXLEN = 10000;
const int MAXLEVEL = 10;
const lint mod = 1000000000LL;

int cmp(lint a , lint b , lint x , lint y){
    lint s[4],e[4];
    memset(s , 0 , sizeof(s));
    memset(e , 0 , sizeof(e));
    s[0] = (y%mod)*(a%mod);s[1] = (y%mod)*(a/mod)+(y/mod)*(a%mod);s[2] = (y/mod)*(a/mod);
    s[1] += s[0]/mod;
    s[0] %= mod;
    s[2] += s[1]/mod;
    s[1] %= mod;
    s[3] += s[2]/mod;
    s[2] %= mod;
    e[0] = (x%mod)*(b%mod);e[1] = (x%mod)*(b/mod)+(x/mod)*(b%mod);e[2] = (x/mod)*(b/mod);
    e[1] += e[0]/mod;
    e[0] %= mod;
    e[2] += e[1]/mod;
    e[1] %= mod;
    e[3] += e[2]/mod;
    e[2] %= mod;
    for(int i = 3 ; i >= 0 ; i--){
        if(s[i] < e[i]) return -1;
        if(s[i] > e[i]) return 1;
    }
    return 0;
}



struct Diva {
    lint up,down;
    Diva() {};
    Diva(const lint &_up,const lint &_down) :
        up(_up),down(_down) {};
    Diva operator * (const Diva &A) const {
        lint u = up * A.up;
        lint d = down * A.down;
        lint gcd = __gcd(u,d);
        u /= gcd;
        d /= gcd;
        return Diva(u,d);
    }
    bool operator < (const Diva &A) const {
        return cmp(up,down,A.up,A.down) == -1;
    }
    bool operator > (const Diva &A) const {
        return cmp(up,down,A.up,A.down) == 1;
    }
    bool operator == (const Diva &A) const {
        return cmp(up,down,A.up,A.down) == 0;
    }
};

const Diva limis = Diva(-1u>>1,1);

lint cnt[MAXLEVEL][MAXN];
char buff[2][MAXLEN];
map<string,int> hash;
Diva f[MAXLEVEL][MAXN];
vector< pair<int,Diva> > adj[MAXN];
string str[2];

void PrintNumber(lint n, lint d){
  double x,y;
  int p, left, moder;

  x = (double (n))/d;

  if(x>=1){
    left=0;
    while(x>=1){ x /= 10; left++; }
    // move x left 5 digits
    x *= 100000;
    p=int (x);
    y = x-p;   
    if(y >= 0.5 - 0.000001) p++;

    //p has the 5 sig digits, so print
    if(left>=5){
      cout<<p;
      for(int i=5; i<left;i++) cout<<0;
    }
    else { // need a decimal
      moder=10000;
      for(int i=0;i<left;i++){
        cout<< p/moder;
        p %= moder;
        moder /=10;
      }
      cout<<'.';
      for(int i=left;i<5;i++){
        cout<<p/moder;
        p %= moder;
        moder /= 10;
      }
    } //else 
  }
  else { // x<1
    cout<<"0.";
    // find how many 0's after decimal
    left=-1;
    while(x<1) {x *= 10; left++; }
    x *= 10000;
    p = int (x); 
    y = x-p;
    if(y>=0.5) p++;  //p now holds 5 sig digits
    // print 0's
    for(int i=0;i<left;i++) cout<<0;
    cout<<p;
  }
}

int main() {
    int T;
    int N = 0,M;
    scanf("%d",&T);
    int t = 1;
    while(scanf("%s%s%d",buff[0],buff[1],&M) == 3) {
        //printf("%s %s\n",buff[0],buff[1]);
        for(int i = 0 ; i < N ; i++) {
            adj[i].clear();
        }
        memset(cnt,0,sizeof(cnt));
        N = 0;
        hash.clear();
        hash[string(buff[0])] = N;
        N++;
        int st = 0,en;
        if (hash.find(string(buff[1])) == hash.end()) {
            en = N;
            hash[string(buff[1])] = N;
            N++;
        }
        else en = 0;
        for(int i = 0 ; i < M ; i++) {
            int d,u;
            int u0,u1;
            scanf("%d%s%d%s",&d,buff[0],&u,buff[1]);
            str[0] = string(buff[0]);
            str[1] = string(buff[1]);
            if (hash.find(str[0]) == hash.end()) {
                hash[str[0]] = N;
                u0 = N;
                N++;
            }
            else u0 = hash[str[0]];
            if (hash.find(str[1]) == hash.end()) {
                hash[str[1]] = N;
                u1 = N;
                N++;
            }
            else u1 = hash[str[1]];
            adj[u0].PB(MP(u1,Diva(u,d)));
            //printf("%d - %d %lld/%lld\n",u0,u1,adj[u0][SZ(adj[u0]) - 1].second.up,adj[u0][SZ(adj[u0]) - 1].second.down);
        }
        for(int i = 0 ; i < N ; i++) {
            for(int l = 0 ; l < MAXLEVEL ; l++) {
                f[l][i] = Diva(1,0);
            }
            //adj[i].PB(MP(i,Diva(1,1)));
        }
        f[0][st] = Diva(1,1);
        for(int l = 0 ; l < MAXLEVEL - 1; l++) {
            for(int i = 0 ; i < N ; i++) {
                if (f[l][i].down == 0) continue;
                for(int j = 0 ; j < SZ(adj[i]) ; j++) {
                    if (f[l + 1][adj[i][j].first] > f[l][i] * adj[i][j].second) {
                        Diva tmp = f[l][i] * adj[i][j].second;
                        if (tmp > limis) continue;
                        swap(tmp.up,tmp.down);
                        if (tmp > limis) continue;
                        //printf("AAAA %d\n",adj[i][j].first);
                        f[l + 1][adj[i][j].first] = f[l][i] * adj[i][j].second;
                    }
                }
            }
        }
        cnt[0][st] = 1;
        for(int l = 0 ; l < MAXLEVEL - 1; l++) {
            for(int i = 0 ; i < N ; i++) {
                if (f[l][i].down == 0) continue;
                for(int j = 0 ; j < SZ(adj[i]) ; j++) {
                    if (f[l + 1][adj[i][j].first] == f[l][i] * adj[i][j].second) {
                        //printf("AAAA %d\n",adj[i][j].first);
                        //f[l + 1][adj[i][j].first] = f[l][i] * adj[i][j].second;
                        cnt[l + 1][adj[i][j].first] += cnt[l][i];
                    }
                }
            }
        }
        //for(int l = 0 ; l < MAXLEVEL ; l++) {
            //for(int i = 0 ; i < N ; i++) {
                //printf("%lld/%lld ",f[l][i].up,f[l][i].down);
            //}
            //printf("\n");
        //}
        Diva minm = Diva(1,0);
        for(int l = 0 ; l < MAXLEVEL ; l++) {
            if (f[l][en] < minm) {
                minm = f[l][en];
            }
        }

        lint res = 0;

        for(int l = 0 ; l < MAXLEVEL ; l++) {
            if (f[l][en] == minm) {
                res += cnt[l][en];
            }
        }

        if (minm.down == 0) while(1);
        printf("Case %d: ",t);
        PrintNumber(minm.up, minm.down);
        //printf("Case %d%"lld\n",t,double(minm.up) / minm.down,res);       
        printf(" %lld\n",res); 
        t++;
        //printf("%lld/%lld %lld\n",f[MAXLEVEL - 1][en].up,f[MAXLEVEL - 1][en].down,cnt[MAXLEVEL - 1][en]);
        //printf("%lld/%lld %lld\n",minm.up,minm.down,res);
        //for(int i = 0 ; i < N ; i++) {
            //adj[i].clear();
        //}
    }
    return 0;
}