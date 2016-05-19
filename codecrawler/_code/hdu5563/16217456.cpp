// #pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
// #define DEBUG
#ifdef DEBUG
#define debug(...) printf( __VA_ARGS__ )
#else
#define debug(...)
#endif
#define MEM(x,y) memset(x, y,sizeof x)
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<double,double> ii;
const int inf = 1 << 30;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
ii p[6];
const double eps = 1e-6;
double mul(double x){
    return x*x;
}
double GetDis(const ii& A,const ii& B){
    return sqrt(mul(A.first - B.first) + mul(A.second - B.second));
}
double dis[12];
int main()
{    
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int cnt = 1;
        for (int i = 1;i <= 5;++i)
            scanf("%lf%lf",&p[i].first,&p[i].second);
        for (int i = 1;i <= 5;++i){
            for (int j = i + 1;j <= 5;++j)
                dis[cnt++] = GetDis(p[i], p[j]);
        }
        sort(dis + 1,dis + cnt);
        int ans = 1;
        for (int i = 2;i < cnt;++i){
            if (fabs(dis[i] - dis[i-1]) > eps) ans++;
        }
        if (ans <= 2) puts("Yes");
        else puts("No");
    }
    return 0;
}