#include<stdio.h>
#include<string.h>
#include<math.h>
const double eps = 1e-9;
const double f=10e10;
#define M 108
typedef struct{
	double x,y;
}Point;
Point inner[M],outer[M];
int oi,oo;
double Dis(Point p,Point q)
{
	return (p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y);
}
double Multi(Point p,Point q,Point o)
{
	return (p.x-o.x)*(q.y-o.y)-(q.x-o.x)*(p.y-o.y);
}
double DotMulti(Point p,Point q,Point o)
{
	return (p.x-o.x)*(q.x-o.x)+(p.y-o.y)*(q.y-o.y);
}
double Fix(Point o,Point p,Point q)
{
	double ret,tmp,area;
	ret=Dis(o,p);
	tmp=Dis(o,q);
	if(tmp<ret) ret=tmp;
	
	if((DotMulti(o,q,p)<eps||DotMulti(o,p,q)<eps))
		return ret;
	
	area=fabs(Multi(o,p,q));
	
	tmp=(area/sqrt(Dis(p,q)));
	tmp*=tmp;
	if(tmp<ret) ret=tmp;
	return ret;
}
int main()
{
	int t,i,j;
	double tmp,ans;
	scanf("%d",&t);
	
	while(t--){
		scanf("%d",&oi);
		for(i=0;i<oi;i++)
			scanf("%lf%lf",&inner[i].x,&inner[i].y);
		scanf("%d",&oo);
		for(i=0;i<oo;i++)
			scanf("%lf%lf",&outer[i].x,&outer[i].y);
		inner[oi]=inner[0];
		outer[oo]=outer[0];
		ans=f;
		for(i=0;i<oi;i++){
			for(j=0;j<oo;j++){
				tmp=Fix(outer[j],inner[i],inner[i+1]);
				if(tmp<ans) ans=tmp;
				tmp=Fix(inner[i],outer[j],outer[j+1]);
				if(tmp<ans)	ans=tmp;
				
			}
		}
		printf("%f/n",sqrt(ans)*0.5000);
	}
	return 0;
}