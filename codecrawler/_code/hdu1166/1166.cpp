/********************* Template ************************/
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
#define BUG         cout<<" BUG! "<<endl;
#define LINE        cout<<" ------------------ "<<endl;
#define FIN         freopen("in.txt","r",stdin);
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#pragma comment     (linker,"/STACK:102400000,102400000")
template<class T> inline T L(T a)       {return (a << 1);}
template<class T> inline T R(T a)       {return (a << 1 | 1);}
template<class T> inline T lowbit(T a)  {return (a & -a);}
template<class T> inline T Mid(T a,T b) {return ((a + b) >> 1);}
template<class T> inline T gcd(T a,T b) {return b ? gcd(b,a%b) : a;}
template<class T> inline T lcm(T a,T b) {return a / gcd(a,b) * b;}
template<class T> inline T Min(T a,T b) {return a < b ? a : b;}
template<class T> inline T Max(T a,T b) {return a > b ? a : b;}
template<class T> inline T Min(T a,T b,T c)     {return min(min(a,b),c);}
template<class T> inline T Max(T a,T b,T c)     {return max(max(a,b),c);}
template<class T> inline T Min(T a,T b,T c,T d) {return min(min(a,b),min(c,d));}
template<class T> inline T Max(T a,T b,T c,T d) {return max(max(a,b),max(c,d));}
template<class T> inline void mem(T &a,int b)   {memset(a,b,sizeof(a));}
template<class T> inline T exGCD(T a, T b, T &x, T &y){ //
    if(!b) return x = 1,y = 0,a;
    T res = exGCD(b,a%b,x,y),tmp = x;
    x = y,y = tmp - (a / b) * y;
    return res;
}
typedef long long LL;    typedef unsigned long long ULL;
//typedef __int64 LL;      typedef unsigned __int64 ULL;
const LL LINF   = 1LL << 60;
const int MOD   = 1000000007;
const int INF   = 0x7fffffff;
const int MAXN  = (int)1e5+50;
const double EPS    = 1e-8;
const double DINF   = 1e15;
const double PI     = acos(-1.0);

/*********************   By  F   *********************/
int sum[MAXN<<2];
int ret;
void pushup(int rt){
    sum[rt] = sum[L(rt)] + sum[R(rt)];
}
void build(int l,int r,int rt){
    if(l == r) {
        scanf("%d",&sum[rt]);
        return;
    }
    int m = Mid(l,r);
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int a,int val,int l,int r,int rt){
    if(l == r){
        sum[rt] += val;
        return ;
    }
    int m = Mid(l,r);
    if(a <= m) update(a,val,lson);
    else update(a,val,rson);
    pushup(rt);
}
int query(int L,int R,int l,int r,int rt){
    if(L <= l && r <= R) return sum[rt];
    int m = Mid(l,r);
    int ret = 0;
    if(L <= m) ret+=query(L,R,lson);
    if(R > m) ret+=query(L,R,rson);
    return ret;
}
int main(){
    //FIN;
    int T,n,i,j;
    char a[20];
    scanf("%d",&T);
    for(int ca = 1 ; ca <= T; ca++){
        scanf("%d",&n);
        printf("Case %d:\n",ca);
        build(1,n,1);
        while(~scanf("%s",a) && a[0] != 'E'){
            scanf("%d%d",&i,&j);
            if(a[0] == 'Q') printf("%d\n",query(i,j,1,n,1));
            if(a[0] == 'A') update(i,j,1,n,1);
            if(a[0] == 'S') update(i,-j,1,n,1);
        }
    }
    return 0;
}