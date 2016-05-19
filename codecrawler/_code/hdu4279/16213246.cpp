#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
inline int Rint() { int x; scanf("%d", &x); return x; }
inline int max(int x, int y) { return (x>y)? x: y; }
inline int min(int x, int y) { return (x<y)? x: y; }
#define FOR(i, a, b) for(int i=(a); i<=(b); i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(x) for(int i=0; i<(x); i++)
typedef __int64 int64;
#define INF (1<<30)
const double eps = 1e-8;
#define bug(s) cout<<#s<<"="<<s<<" "

int64 f(int64 x)
{
    if(x<=2) return 0;
    //return x/2-1+( (int64)floor(sqrt((double)x)) %2? 0: -1);            //ç¨ double waã
    //return x/2-1+( (int64)floor(sqrt((long double)x)) %2? 0: -1);        //floor å¯ä¸ç¨ã
    return x/2-1+( (int64)sqrt((long double)x) %2? 0: -1);        //ç¨ long double æè *1.0
}

int main()
{
    int T = Rint();
    while(T--)
    {
        int64 a, b;
        scanf("%I64d%I64d", &a, &b);
        printf("%I64d\n", f(b)-f(a-1));
    }
}