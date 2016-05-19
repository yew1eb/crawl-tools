#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#include<algorithm>
#include<list>
#include<cstdio>
#include<stack>
#include<cstring>
#include<cmath>
#include<string>
#include <functional>
#include<sstream>
#include<map>
using namespace std;
#define     For(i,a,b)        for (int i=a; i<b; i++)
#define     Rep(i,a)          for (int i=0; i<a; i++)
#define     FIT(it,v)         for (typeof((v).begin())it=(v).begin(); it!=(v).end(); ++it)
#define     ALL(v)            (v).begin(),(v).end()
#define     Set(a,x)          memset((a),(x),sizeof(a))
#define     EXIST(a,b)        find(ALL(a),(b))!=(a).end()
#define     Sort(x)           sort(ALL(x))
#define     GSORT(x)          sort(ALL(x), greater<typeof(*((x).begin()))>())
#define     UNIQUE(v)         SORT(v); (v).resize(unique(ALL(v)) - (v).begin())
#define     MP                make_pair
#define     SF                scanf
#define     PF                printf
#define     MAXN               1001
#define     MAXM               1001
#define     MOD               1000000007
#define     Dbug             cout<<"";
#define     eps             1e-15

typedef long long ll;
typedef pair<int,int> pii;
int n;
double l, k, t1, t2, h;
bool u;
bool check(double r)
{
	double t0=l/r;
	t0=t1-t0;
	double r2=r-k;
	double w=l+(r2*t0);
	double le=t2*k;
	w-=le;
	if(w==h)
		u=1;
	if(w>=h) return 1;
	return 0;
}
int main(){
	//ios_base::sync_with_stdio(false);
	//freopen("a.in","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		u=0;
		cin>>l>>k>>t1>>t2>>h;
		double ans, m, M, le=0, r=1<<30;
		if(h<l) 
		{
			PF("%.6lf %.6lf\n", h, h);
			continue;
		}
		while (fabs(le-r)>eps)
		{
			double mid=(le+r)/2.;
			if(check(mid)) 
				ans=mid, r=mid;
			else le=mid;
			if(u) break;
		}
		if(le<ans) if(check(le)) ans=le;
		r=ans;
		double t0=l/r;
		t0=t1-t0;
		//double r2=r-k;
		double w=l+(r*t0);
		if(h==l)
		{
			PF("%.6lf %.6lf\n", l, w);
		}
		else 
			PF("%.6lf %.6lf\n", w, w);
	}
	return 0;
}