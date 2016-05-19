#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdlib>
#include <map>
using namespace std;
#define I64_MAX 9223372036854775807 
typedef long long ll;
const double pi=acos (-1.0);
const double eps=1e-8 ;
//const ll INF=(I64_MAX)/2;
//#pragma comment(linker, "/STACK:102400000,102400000")
const int inf=0x3f3f3f3f ;
#define maxx(a) memset(a, 0x3f, sizeof(a))
#define zero(a) memset(a, 0, sizeof(a))
#define FILL(a,b) memset(a, b, sizeof(a))
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define srep(i,n) for(i = 1;i <= n;i ++)
#define snuke(c,itr) for( __typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define MP make_pair
#define fi first
#define se second
typedef pair <int, int> PII;
typedef pair <ll, ll> PX;
typedef pair<int,ll> PIL;
#define MAX

int n,m;


int main ()
{
    // freopen("E:\\input.txt" ,"r", stdin);
     // freopen ("E:\\out.txt","w",stdout);
    int i,j;
    while(scanf("%d%d",&n,&m) == 2)
    {
        int a,b;
        int ans = inf;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            if(n%a == 0)
            {
                ans = min(n/a*b,ans);
            }
            else
            {
                ans = min((n/a+1)*b,ans);
            }
        }
        cout<<ans<<endl;
    }




    return 0;
}