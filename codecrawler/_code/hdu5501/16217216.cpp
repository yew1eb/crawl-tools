#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<set>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<iostream>
#include<ctime>
#include<bitset>
using namespace std;
#define N 10005
#define NMAX 2000000000 
typedef long long ll;

struct type{
    int a;
    int b;
    int c;
    double f;
}p[N];
int dp[N*3];
bool cmp(const type& x, const type& y){
    return x.f > y.f;
}
int main(){
    int T, n, m, t;
    while ( scanf("%d", &T) != EOF){
        while ( T > 0 ){
            T--;
            scanf("%d %d", &n, &t);
            for ( int i = 0; i < n; i++ ){
                scanf("%d %d %d", &p[i].a, &p[i].b, &p[i].c);
                p[i].f = (double)p[i].b / p[i].c;
            }
            sort(p, p+n, cmp);
            memset(dp, -1, sizeof(dp));
            dp[0] = 0;
            for ( int i = 0; i < n; i++ ){
                for ( int j = t; j >= p[i].c; j-- ){
                    if ( dp[j-p[i].c] == -1)continue;
                    if ( dp[j-p[i].c]+p[i].a-(j*p[i].b) > dp[j] )
                        dp[j] = dp[j-p[i].c]+p[i].a-(j*p[i].b);
                }
            }
            m = 0;
            for ( int i = 0; i <= t; i++ ){
                if ( dp[i] > m ) m = dp[i];
            }
            cout << m << endl;
        }
    } 
    return 0;
} 
 