#pragma comment(linker, "/STACK:36777216")
#pragma GCC optimize ("O2")
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
#define RD(x) scanf("%d",&x)
#define RD2(x,y) scanf("%d%d",&x,&y)
#define RD3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define clr0(x) memset(x,0,sizeof(x))
#define eps 1e-9
const double pi = acos(-1.0);
typedef long long LL;
const int modo = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 1005,maxm = 1e4 + 5;
int t[maxn<<1],ans[maxn<<1][maxn<<1],n,m;

int main(){
    int x,y,_n;
    while(~RD(n)){
        _n = n;
        n = -2 + (n<<1);
        clr0(ans);
        for(int i = 0;i <= n;++i)
            RD(t[i]);
        for(int i = 0;i <= n;++i)
            for(int j = 0;j <= n;++j)
            ans[i][j] = t[i]*t[j];

        for(int i = 1;i <= n;++i)
            for(int j = 0;j < n;++j){
                ans[i][j] += ans[i-1][j+1];
            }
        RD(m);
        LL sum = 0;int res = 0;
        while(m--){
            RD2(x,y);
            x = (x+res)%_n,y = (y+res)%_n;
            int sx = _n - 1 + y,sy = _n - 1 - x;
            res = ans[sx][sy];
            if(sx - _n >= 0 && sy + _n <= n)
                res -= ans[sx-_n][sy+_n];
            sum += res;
//            cout<<x<<','<<y<<endl;
//            cout<<res<<endl;
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
