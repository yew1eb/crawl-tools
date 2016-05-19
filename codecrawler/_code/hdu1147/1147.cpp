#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<list>
using namespace std;
#define precision 1e-8
#define MAX 1000000
struct point 
{
	double x;
	double y;
};

struct seg
{
	point a;
	point b;
	int cnt;
};

//p1a与p2a的叉积
double cross(point p1,point p2,point a)
{
	return (p1.x-a.x)*(p2.y-a.y)-(p1.y-a.y)*(p2.x-a.x);
}
//判断m是否等于0
int dblcmp(double m)
{
	if(fabs(m)<precision)
		return 0;
	else if(m<0)
		return -1;
	return 1;
}

int betweencmp(point p1,point p2,point a)
{
	
	double s=(p1.x-a.x)*(p2.x-a.x)+(p1.y-a.y)*(p2.y-a.y);  //ap1与ap2的点积
	return dblcmp(s);
}



int segcross(point a,point b,point c,point d)
{
	double s1,s2,s3,s4;
	int d1,d2,d3,d4;
	d1=dblcmp(s1=cross(b,c,a));
	d2=dblcmp(s2=cross(b,d,a));
	d3=dblcmp(s3=cross(d,a,c));
	d4=dblcmp(s4=cross(d,b,c));
	//判断规范相交，并计算出交点
	if(d1*d2<0 &&d3*d4<0)
	{
		return 1;
	}
	//判断非规范相交
	if( ( d1==0 && betweencmp(a,b,c)<=0 ) ||
		( d2==0 && betweencmp(a,b,d)<=0 ) ||
		( d3==0 && betweencmp(c,d,a)<=0 ) ||
		( d4==0 && betweencmp(c,d,b)<=0 ))
		return true;
		
	return false;
}


int main()
{
	freopen("test.txt","r",stdin);
	list<seg>stick;
	int n;
	int i,k;
	int len;
	list<seg>::iterator p;
	seg v;

	while(scanf("%d",&n)!=EOF &&n!=0)
	{
		
		
		scanf("%lf %lf %lf %lf", &v.a.x , &v.a.y , &v.b.x , &v.b.y);
		v.cnt=1;
		stick.push_back(v);
		for(i=2;i<=n;i++)
		{
			scanf("%lf %lf %lf %lf", &v.a.x , &v.a.y , &v.b.x , &v.b.y);
			v.cnt=i;
			stick.push_back(v);
			len=stick.size();
			p=stick.begin();
			for(k=1;k<len;k++)
			{
				
				if( segcross((*p).a,(*p).b,v.a,v.b) )
				{
					p=stick.erase(p);
				}
				else
					p++;
			}

		}
		printf("Top sticks: ");
		p=stick.begin();
		len=stick.size();
		for(i=1;i<len;i++)
		{
			printf("%d, ",(*p).cnt);
			p++;
		}
		printf("%d.\n",(*p).cnt);
		stick.clear();
	}
	return 0;
}