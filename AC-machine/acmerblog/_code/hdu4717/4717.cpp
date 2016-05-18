/*【题意】：
给N个点，给出N个点的方向和移动速度，求每个时刻N个点中任意两点的最大值中的最小值，以及取最小值的时刻
解析:
两个点为例，任意两个点，按照自己的方向移动，一般情况下是，先两点慢慢接近，直到最近距离，然后慢慢远离，后面越来越远，图像画出来有点像抛物线，
这题就是抛物线求最小值，三分：先二分时间，按照斜率确定移动方向，直到移动到抛物线的最低端
 注意题目精度，每次最好分1e-5以上，才能保证正确性
*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn=310;
#define exp  1e-6
int n;
struct point
{
	double x,y;
	double vx,vy;
}p[maxn];
double dis(int a,int b,double k)
{
	return sqrt( 1.0*(p[a].x+p[a].vx*k-p[b].x-p[b].vx*k)*(p[a].x+p[a].vx*k-p[b].x-p[b].vx*k)+
		         1.0*(p[a].y+p[a].vy*k-p[b].y-p[b].vy*k)*(p[a].y+p[a].vy*k-p[b].y-p[b].vy*k) );
}
double okboy(double k)
{
      int i,j;
	  double max=-1;
      for(i=0;i<n;i++)
	  {
		  for(j=i+1;j<n;j++)
		  {
			  double sb=dis(i,j,k);
			  if(sb>max) max=sb;
		  }
	  }
	  return max;
}
void sanfen()
{
	double l=0,r=1e8,min=(double)0x3f3f3f3f,t,mid;
	while(l<r)
	{
		 mid=(l+r)/2;
		double ok1=okboy(mid);
		double ok2=okboy(mid-exp);//三分时间
		if(ok1<ok2) l=mid+exp;
		else r=mid-exp;
		if(min>ok1)
		{
			min=ok1;
			t=mid;
		}
	}
	printf("%.2lf %.2lf\n",t,min);
}
int main()
{
	int i;
	int t,cas=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lf%lf%lf%lf",&p[i].x,&p[i].y,&p[i].vx,&p[i].vy);
		printf("Case #%d: ",++cas);
		sanfen();
	}
	return 0;
}
