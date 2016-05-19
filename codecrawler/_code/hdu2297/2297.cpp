#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<ctime>
#define maxn 200005
#define eps 1e-8
#define inf 2000000000
#define LL long long
#define zero(a) fabs(a)<eps
#define MOD 19901014
#define N 1000005
#define pi acos(-1.0)
using namespace std;
int t,n;
double X,Y;
double best[50];
struct Point{
	double x,y;
	bool check(){
		if(x>-eps&&x<eps+X&&y>-eps&&y<eps+Y)
			return true;
		return false;
	}
}p[1005],tp[50];
double dist(Point p1,Point p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
double slove(Point p0){
	double ans=inf;
	for(int i=0;i<n;i++)
		ans=min(ans,dist(p[i],p0));
	return ans;
}
int main(){
	scanf("%d",&t);
	srand(time(NULL));
	while(t--){
		scanf("%lf%lf%d",&X,&Y,&n);
		for(int i=0;i<n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		for(int i=0;i<15;i++){
			tp[i].x=(rand()%1000+1)/1000.0*X;
			tp[i].y=(rand()%1000+1)/1000.0*Y;
			best[i]=slove(tp[i]);
		}
		double step=max(X,Y)/sqrt(1.0*n);
		while(step>1e-3){
			for(int i=0;i<15;i++){
				Point cur,pre=tp[i];
				for(int j=0;j<35;j++){
					double angle=(rand()%1000+1)/1000.0*2*pi;
					cur.x=pre.x+cos(angle)*step;
					cur.y=pre.y+sin(angle)*step;
					if(!cur.check()) continue;
					double tmp=slove(cur);
					if(tmp>best[i]){
						tp[i]=cur;
						best[i]=tmp;
					}
				}
			}
			step*=0.85;
		}
		int idx=0;
		double ans=0;
		for(int i=0;i<15;i++){
			if(best[i]>ans){
				ans=best[i];
				idx=i;
			}
		}
		printf("The safest point is (%.1f, %.1f).\n",tp[idx].x,tp[idx].y);
	}
	return 0;
}