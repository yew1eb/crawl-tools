#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#define PA system("pause");
#define X 110
#define eps 1e-8
#define pi 3.14159265358979323
using namespace std;
struct point{
	double x,y;
}p[X],q[X],stk[X];
point yd,x100,A,B;
int top,n;
double minjiao;
double max(double x,double y){return x>y+eps?x:y;}
double min(double x,double y){return x<y-eps?x:y;}
double dis(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int cp(point a,point b,point c){
	double t=(c.x-a.x)*(b.y-a.y)-(c.y-a.y)*(b.x-a.x);
	if(t<-eps)return -1;
	if(t>eps)return 1;
	return 0;
}
int cmp(point a,point b){
	if(cp(stk[0],a,b)==0)
	    return dis(stk[0],a)<dis(stk[0],b);
	return cp(stk[0],a,b)<0;
}
void graham(){
	int i;
	top=1;
	sort(stk+1,stk+n,cmp);
	p[0]=stk[0];p[1]=stk[1];
	for(i=2;i<n;i++){
		while(cp(p[top],p[top-1],stk[i])<=0&&top)top--;
		p[++top]=stk[i];
	}
	p[++top]=stk[0];
}
point rorate(point b,double ang){
	point c;
	c.x=b.x*cos(ang)-b.y*sin(ang);
	c.y=b.x*sin(ang)+b.y*cos(ang);
	return c;
}
double qiujiao(point e){
	if(fabs(e.y)<eps&&e.x>eps)return 0;
	if(fabs(e.y)<eps&&e.x<-eps)return pi;
	double a=dis(e,yd),b=dis(e,x100);
	return acos((a*a+1e4-b*b)/(200*a));
}
int pointin(point a,point s[],int n){
	int i;s[n]=s[0];s[n+1]=s[1];
	for(i=0;i<n-1;i++)
	    if(cp(s[i],s[i+1],a)*cp(s[i+1],s[i+2],a)<0)
	        return 0;
	return 1;
}
int bi(point a,point b,point A,double ang){
	if(cp(a,b,A)<0)swap(a,b);
	double l=0,r=ang,md;
	point c;
	while(l<r-eps){
		md=(l+r)/2;
		c=rorate(A,md);
		if(cp(a,b,c)<0)
		    r=md;
		else
		    l=md;
	}
	printf("%lf,%lf\n",c.x,c.y);
	if(c.x>min(a.x,b.x)&&c.x<max(a.x,b.x)&&
	c.y>min(a.y,b.y)&&c.y<max(a.y,b.y)){
	    md=qiujiao(c)-qiujiao(A);
	    minjiao=minjiao<md?minjiao:md;
	    return 1;
	}
	return 0;
}
int main(){
	yd.x=yd.y=x100.y=0;x100.x=100;
	int i,j,flag,cs=1;
	double as,sum,jiaoA,jiaoP,lenA;
	freopen("in2.txt","r", stdin);
	freopen("out.txt","w",stdout);
	while(~scanf("%d",&n)){
		for(i=0;i<n;i++){
		    scanf("%lf%lf",&stk[i].x,&stk[i].y);
		    q[i]=stk[i];
		}
		scanf("%lf%lf",&A.x,&A.y);
		if(cp(q[0],q[1],q[2])>0)
		    for(i=1;i<n/2;i++)
		        swap(q[i],q[n-i]);
		graham();
		q[n]=q[0];
		as=0;sum=0;minjiao=5;
		for(i=0;i<top;i++)sum+=dis(p[i],p[i+1]);
		if(A.x>sum){
			A.x=fmod(A.x,sum);
			as=(int)(A.x/sum);
			as*=2*pi;
			if(pointin(A,p,top)){
				as-=2*pi;A.x+=sum;
			}
		}
		for(j=0,flag=0;j<=2*top&&!flag;j++){
        for(i=0;i<=n;i++)
		    printf("%.2lf,",q[i].x);puts("");puts("");
        for(i=0;i<=n;i++)
		    printf("%.2lf,",q[i].y);puts("");puts("");
			jiaoA=qiujiao(A);
			jiaoP=qiujiao(p[1]);
			B=rorate(A,jiaoP);
			lenA=sqrt(A.x*A.x+A.y*A.y);
			for(i=0;i<n;i++){
                printf("x=%lf y=%lf x=%lf y=%lf\n\n",q[i].x,q[i].y,q[i+1].x,q[i+1].y);
                printf("len1=%lf len2=%lf\n",dis(q[i],yd),dis(q[i+1],yd));
                printf("cp1=%d,cp2=%d\n",cp(q[i],q[i+1],A),cp(q[i],q[i+1],B));
                printf("Ax=%lf Ay=%lf Bx=%lf By=%lf\n",A.x,A.y,B.x,B.y);
			    if((dis(q[i],yd)>=lenA||dis(q[i+1],yd)>=lenA)&&
		            cp(q[i],q[i+1],A)*cp(q[i],q[i+1],B)<=0)
						if(bi(q[i],q[i+1],A,jiaoP))
						flag=1;
					}
			if(!flag){
				for(i=0;i<=top;i++)
				    p[i]=rorate(p[i],-jiaoP);
				for(i=0;i<=n;i++)
				    q[i]=rorate(q[i],-jiaoP);
				for(i=0;i<=top;i++)
				    if(i!=1)p[i].x-=p[1].x;
				for(i=0;i<=n;i++)
				    q[i].x-=p[1].x;
				A.x-=p[1].x;
				p[1].x=p[1].y=0;
				for(i=1;i<=top;i++)
				    p[i-1]=p[i];
				for(i=1;i<=n;i++)
				    q[i-1]=q[i];
				p[top]=p[0];q[n]=q[0];
				as+=jiaoP;
			}
			else
			    as+=minjiao;
		}
		printf("Case %d: ",cs++);
		if(flag)printf("%.2lf\n",as*180/pi);
		else printf("Impossible\n");
	}
	return 0;
}
