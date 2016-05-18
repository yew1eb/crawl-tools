#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

const double eps=1e-8;
const int n_max=1005;
double X,Y,R;
int n;
struct point
{
	double x,y;
	point(){}
	point(double tx,double ty)
	{
		x=tx,y=ty;
	}
}p[n_max],central;

double dist(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

//求外接圆圆心 
point circumcenter(point a,point b,point c)
{
	double a1=b.x-a.x, b1=b.y-a.y, c1=(a1*a1+b1*b1)/2;
	double a2=c.x-a.x, b2=c.y-a.y, c2=(a2*a2+b2*b2)/2;
	double d=a1*b2-a2*b1;
	return point(a.x + (c1*b2-c2*b1)/d , a.y+(a1*c2-a2*c1)/d);
}

//求最小覆盖圆
void min_cover_circle()
{
	random_shuffle(p,p+n);
	central=p[0];
	R=0;
	int i,j,k;
	for(i=1;i<n;i++)
	{
		if(dist(central,p[i])+eps>R)
		{
			central=p[i];
			R=0;
			for(j=0;j<i;j++)
			{
				if(dist(central,p[j])+eps>R)
				{
					central.x=(p[i].x+p[j].x)/2;
					central.y=(p[i].y+p[j].y)/2;
					R=dist(central,p[j]);
					for(k=0;k<j;k++)
					{
						if(dist(central,p[k])+eps>R)
						{
							central=circumcenter(p[i],p[j],p[k]);
							R=dist(central,p[k]);
						}
					}
				}
			}
		}
	}
}

int main()
{
	while(~scanf("%lf%lf%d",&X,&Y,&n))
	{
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf",&p[i].x,&p[i].y);
		}
		min_cover_circle();
		printf("(%.1lf,%.1lf).\n%.1lf\n",central.x,central.y,R);
	}
	return 0;
}
