//#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ls(rt) rt*2
#define rs(rt) rt*2+1
#define ll long long
#define ull unsigned long long
#define rep(i,s,e) for(int i=s;i<e;i++)
#define repe(i,s,e) for(int i=s;i<=e;i++)
#define CL(a,b) memset(a,b,sizeof(a))
#define IN(s) freopen(s,"r",stdin)
#define OUT(s) freopen(s,"w",stdout)
const ll ll_INF = ((ull)(-1))>>1;
const double EPS = 1e-8;
const double pi = acos(-1.0);
const int INF = 100000000;

const int MAXN = 1000+20;

double t[MAXN],x[MAXN],y[MAXN];
struct Node {
    double t,x,y;
}a[MAXN];

bool cmp(Node a, Node b){
    return a.t<b.t;
}

int main()
{
    int ncase,n;
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%d",&n);
        double ans=0.0;
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf%lf",&a[i].t,&a[i].x,&a[i].y);
        }
        
        for(int i=0;i<n-1;i++)
            ans=max(ans,sqrt( (a[i].x-a[i+1].x)*(a[i].x-a[i+1].x)+(a[i].y-a[i+1].y)*(a[i].y-a[i+1].y) )/(a[i+1].t-a[i].t));
        printf("%.10lf\n",ans);
    }
    return 0;
}
