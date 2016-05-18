#include"stdio.h"
#include"string.h"
#include"math.h"
#define g 9.8
int main()
{
	double h,v_x,v_y,t,v1,v2,v3;
	double t1,t2;
	double ans,ans1,ans2,ans3;
	double temp;
	char str[11];
	while(scanf("%lf",&h)!=-1)
	{
		scanf("%s%lf%lf",&str,&v_x,&v_y);
		t1=v_y/g;
		t2=sqrt(2*h/g+v_y*v_y/g/g);
		if(strcmp(str,"Red")==0)
		{
			printf("%.3lf\n",(t1+t2)*v_x);
			continue;
		}
		else if(strcmp(str,"Yellow")==0)
		{
			scanf("%lf",&t);
			if(t>=t1+t2)	{printf("%.3lf\n",(t1+t2)*v_x);continue;}
			else if(t<=t1)
			{
				temp=(v_y+v_y-t*g)*t/2;
				h+=temp;
				ans=v_x*t;
				v_y-=t*g;
				v_y*=2;
				v_x*=2;
				t1=v_y/g;
				t2=sqrt(2*h/g+v_y*v_y/g/g);
				ans+=v_x*(t1+t2);
				printf("%.3lf\n",ans);
			}
			else
			{
				ans=v_x*t;
				h+=0.5*v_y*v_y/g;
				h-=0.5*g*(t-t1)*(t-t1);
				v_y=2*g*fabs(t-t1);
				v_x*=2;
				t2=(-v_y+sqrt(v_y*v_y+2*g*h))/g;
				ans+=v_x*t2;
				printf("%.3lf\n",ans);
			}
		}
		else if(strcmp(str,"Blue")==0)
		{
			scanf("%lf%lf%lf%lf",&t,&v1,&v2,&v3);
			if(t>=t1+t2)	{printf("%.3lf\n",(t1+t2)*v_x);continue;}
			if(t<=t1)
			{
				temp=(v_y+v_y-t*g)*t/2;
				h+=temp;
				ans=v_x*t;
				v_y-=t*g;
				t2=sqrt(2*h/g+v_y*v_y/g/g);
				ans1=ans+v1*(t2+t1-t);
				ans2=ans+v2*(t2+t1-t);
				ans3=ans+v3*(t2+t1-t);
				printf("%.3lf %.3lf %.3lf\n",ans1,ans2,ans3);
			}
			else
			{
				ans=v_x*t;
				h+=0.5*v_y*v_y/g;
				h-=0.5*g*(t-t1)*(t-t1);
				v_y=g*fabs(t-t1);
				t2=(-v_y+sqrt(v_y*v_y+2*g*h))/g;
				ans1=ans+v1*t2;
				ans2=ans+v2*t2;
				ans3=ans+v3*t2;
				printf("%.3lf %.3lf %.3lf\n",ans1,ans2,ans3);
			}
		}
	}
	return 0;
}