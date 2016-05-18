#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<math.h>
#include<stdlib.h>
using namespace std;
#define eps 1e-8
struct pot
{
	double x,y;
}point[30];
struct triange
{
	double a,b,c;
	int num;
}tri[20000];
int mark[300][300];
int judge(double x,double y)
{
	if(fabs(x-y)<=eps)
	return 1;
	return 0;
}
double xmulti(pot p1,pot p2,pot p0)
{
	return ((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y));
}
double getdis(pot a,pot b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int jsimlar(triange e,triange f)
{
	return judge(e.a*f.b,e.b*f.a)&&judge(e.b*f.c,e.c*f.b);
}
int main()
{
	int i,j,k,n,m,x,y,l;
	while(scanf("%d",&n),n)
	{
		memset(mark,0,sizeof(mark));
		k=0;l=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			if(mark[x+100][y+100]==0)
			{
				mark[x+100][y+100]=1;
				point[k].x=x;
				point[k].y=y;
				k++;
			}			
		}		
		n=k;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				for(k=j+1;k<n;k++)
				{
					m=xmulti(point[i],point[j],point[k]);
					if(judge(m,0)==0)
					{
						tri[l].a=getdis(point[i],point[j]);
						tri[l].b=getdis(point[i],point[k]);
						tri[l].c=getdis(point[j],point[k]);
						if(tri[l].a>tri[l].b)
						swap(tri[l].a,tri[l].b);
						if(tri[l].a>tri[l].c)
						swap(tri[l].a,tri[l].c);
						if(tri[l].b>tri[l].c)
						swap(tri[l].b,tri[l].c);
						tri[l].num=1;
						l++;
					}
				}
			}
		}
		
	//	printf("n=%d\n",n);
	//	printf("l=%d\n",l);
		for(i=0;i<l;i++)
			for(j=i+1;j<l;j++)
			{
				if(tri[i].num!=-1)
				{
					if(jsimlar(tri[i],tri[j]))
					{
						tri[i].num++;
						tri[j].num=-1;
					}
				}
			}
		int ans=0;
		for(i=0;i<l;i++)
		{
			if(ans<tri[i].num)
			ans=tri[i].num;
		}
		printf("%d\n",ans);
	}
	return 0;
}