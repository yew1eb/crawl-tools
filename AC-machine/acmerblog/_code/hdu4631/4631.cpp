#include<cstdio>
#include<cstring>
#include<iostream>
#include<set>
using namespace std;
const int maxn=501000;
const long long inf=1LL<<60;
struct Point
{
    long long x;
    long long y;
    bool operator < (const Point& a)const
    {
	if(x==a.x)
	    return y<a.y;
	return x<a.x;
    }
};
multiset<Point> s;
multiset<Point>::iterator it,k;
int n;
long long ax,ay,bx,by,cx,cy,x[maxn],y[maxn];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
	scanf("%d",&n);
	scanf("%I64d%I64d%I64d",&ax,&bx,&cx);
	scanf("%I64d%I64d%I64d",&ay,&by,&cy);
	x[0]=y[0]=0;
	for(int i=1;i<=n;i++)
	{
	    x[i]=(x[i-1]*ax+bx)%cx;
	    y[i]=(y[i-1]*ay+by)%cy;
	}
	Point p;
	p.x=x[1];
	p.y=y[1];
	s.clear();
	s.insert(p);
	long long ans=0,mini=inf;
	for(int i=2;i<=n;i++)
	{
	    p.x=x[i];
	    p.y=y[i];
	    it=s.lower_bound(p);
	    for(k=it;k!=s.end();k++)
	    {
		long long itx=p.x-k->x;
		itx*=itx;
		if(mini<=itx)
		    break;
		long long ity=p.y-k->y;
		ity*=ity;
		mini=min(mini,itx+ity);
	    }
	    for(k=it;k!=s.begin();)
	    {
		k--;
		long long itx=p.x-k->x;
		itx*=itx;
		if(mini<=itx)
		    break;
		long long ity=p.y-k->y;
		ity*=ity;
		mini=min(mini,itx+ity);
	    }
	    ans+=mini;
	    s.insert(p);
	}
	printf("%I64d\n",ans);
    }
    return 0;
}