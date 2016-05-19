#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
#define RD(x) scanf("%d",&x)
#define RD2(x,y) scanf("%d%d",&x,&y)
#define RD3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define clr0(x) memset(x,0,sizeof(x))
typedef long long LL;
const int maxn = 1020;
int n;
struct node{
    int t;
    double x,y;
}p[maxn];
bool cmp(node a,node b)
{
    return a.t < b.t;
}
double dif(node a,node b)
{
    return sqrt( (a.x - b.x)*(a.x - b.x) + (a.y-b.y)*(a.y-b.y) )/(double)(b.t-a.t);
}
int main() {
    int _;RD(_);while(_--){
        RD(n);
        for(int i = 0;i < n;++i){
            RD(p[i].t);scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        sort(p,p+n,cmp);
        double ans = 0;
        for(int i = 1;i < n;++i){
            ans = max(ans,dif(p[i-1],p[i]));
        }
        printf("%.10f\n",ans);
    }

    return 0;
}
