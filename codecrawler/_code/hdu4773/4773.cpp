#include <iostream>
#include <cstdio>	
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#define sqr(x) ((x)*(x))
using namespace std;
const double eps=1e-10;
struct Point{
	double x,y,z;
	Point operator +(const Point &b) const;
	Point operator *(const double &b) const;
	Point operator -() const; 
	double dist() const 
	{
		return sqrt(x*x+y*y);
	}
	void print() const 
	{
		printf("COR=(%.3lf,%.3lf)\n",x,y);
	}
}P;
struct Circle{
	Point o;
	double r;
	void print() const
	{
		o.print();
		printf("R=%.3lf\n\n",r);
	}
}C1,C2;
struct Line{
	Point p1,p2;
	void print() const
	{
		p1.print();
		p2.print();
		printf("\n");
	}
}st[4];
int tot;
void cross(Point &p,Point e,Point r)
{
	p.x=e.y*r.z-e.z*r.y;
	p.y=e.z*r.x-e.x*r.z;
	p.z=e.x*r.y-e.y*r.x;
}
double dot(Point l,Point P)
{
	return l.x*P.x+l.y*P.y+l.z*P.z;
}
Point Point::operator +(const Point &b) const
{
	Point c;
	c.x=x+b.x,c.y=y+b.y;
	return c;
}
Point Point::operator *(const double &b) const
{
	Point c;
	c.x=x*b,c.y=y*b;
	return c;
}
Point Point::operator -() const
{
	Point c;
	c.x=-x,c.y=-y;
	return c;
}
Point inverse_Point(Point P,Point A)
{
	Point PA=A+(-P);
	double len=1000000.0/PA.dist();
	Point A1=P+PA*(len/PA.dist());
	return A1;
}
Circle inverse_Circle(Point P,Circle C)
{
	Point O=C.o,A,B,A1,B1;
	Point PO=O+(-P);
	A=P+PO*((PO.dist()-C.r)/PO.dist());
	B=P+PO*((PO.dist()+C.r)/PO.dist());
	A1=inverse_Point(P,A);
	B1=inverse_Point(P,B);
	Circle C1;
	C1.o=(A1+B1)*0.5;
	C1.r=((A1+(-B1)).dist())*0.5;
	return C1;
}
int CircleCrossCircle( Point p1 , double r1 , Point p2 , double r2 , Point &cp1 , Point &cp2 ){
	double mx = p2.x - p1.x , sx = p2.x+p1.x , mx2 = mx*mx;
	double my = p2.y - p1.y , sy = p2.y+p1.y , my2 = my*my;
	double sq = mx2 + my2 , d = -( sq - sqr ( r1-r2 ) ) * ( sq - sqr ( r1+r2 ) ) ;
	if ( d+eps <0 ) return 0 ; if ( d<eps ) d=0 ;  else d = sqrt(d ) ;
	double x = mx* ( ( r1+r2 )*( r1-r2 ) + mx*sx ) + sx*my2 ;
	double y = my* ( ( r1+r2 )*( r1-r2 ) + my*sy ) + sy*mx2 ;
	double dx = mx*d , dy = my*d ; sq *= 2;
	cp1.x = ( x - dy ) / sq ; cp1.y = ( y + dx ) / sq ;
	cp2.x = ( x + dy ) / sq ; cp2.y = ( y - dx ) / sq ;
	if ( d>eps ) return 2 ; else return 1 ;
}
void Add_line(Point cp1,Circle C1,Circle C2,double e)
{
	Point pp;
	pp=(cp1+(-C2.o));
	++tot;
	st[tot].p1=C2.o+pp*(C2.r/pp.dist());
	st[tot].p2=C1.o+pp*(C1.r/pp.dist())*e;
}
void Cut(Circle C1,Circle C2)
{
	Circle CC,C3;
	CC.o=(C1.o+C2.o)*0.5;
	CC.r=((CC.o+(-C1.o)).dist());
	if (C1.r-C2.r>-eps) {
		Circle e;
		e=C1,C1=C2,C2=e;
	}
	C3=C2,C3.r=C2.r-C1.r;
	Point cp1,cp2;
	int tmp;
	if ((tmp=CircleCrossCircle(CC.o,CC.r,C3.o,C3.r,cp1,cp2)) || (fabs(C3.r)<eps)) {
		if (fabs(C3.r)<eps) {
			Point p=C1.o,q=C2.o;
			p.z=q.z=1;
			Point l;
			cross(l,p,q);
			cp1=q+l*(C2.r/l.dist());
			cp2=q+(-(l*(C2.r/l.dist())));
		}
		Add_line(cp1,C1,C2,1);
		Add_line(cp2,C1,C2,1);
	}
}
bool Deng(Point a,Point b)
{
	return fabs(a.x-b.x)<eps && fabs(a.y-b.y)<eps;
}
bool equ(Line a,Line b)
{
	if (Deng(a.p1,b.p1) && Deng(a.p2,b.p2)) return 1;
	if (Deng(a.p1,b.p2) && Deng(a.p2,b.p1)) return 1;
	return 0;
}
bool check(Point P,int id,Point p1,Point p2,Circle &C)
{
	for (int i=1;i<id;i++)
		if (equ(st[i],st[id])) return 0;
	P.z=1,p1.z=1,p2.z=1;
	Point l;
	cross(l,p1,p2);
	if (fabs(dot(l,P))<eps) return 0;
	Point Q=P+l;Q.z=1;
	Point r;
	cross(r,P,Q);
	Point U;
	cross(U,l,r);
	U.x/=U.z,U.y/=U.z,U.z=1;
	Point PU=U+(-P);
	double len=1000000.0/PU.dist();
	C.o=(P+PU*(len/PU.dist())+P)*0.5;
	C.r=len*0.5;
	if (fabs((C.o+(-C1.o)).dist()-(C.r+C1.r))<eps && fabs((C.o+(-C2.o)).dist()-(C.r+C2.r))<eps) return 1;
	return 0;
}
int t;
int main()
{
	freopen("hdu4773.in","r",stdin);
	freopen("hdu4773.out","w",stdout);
	scanf("%d",&t);
	for (;t;t--) {
		double c1,c2,c3,c4,c5,c6;
		scanf("%lf%lf%lf%lf%lf%lf",&c1,&c2,&c3,&c4,&c5,&c6);
		C1.o.x=c1,C1.o.y=c2,C1.r=c3,C2.o.x=c4,C2.o.y=c5,C2.r=c6;
		scanf("%lf%lf",&c1,&c2);
		P.x=c1,P.y=c2;
		Circle P1,P2,C3;
		P1=inverse_Circle(P,C1);
		P2=inverse_Circle(P,C2);
		tot=0;
		Cut(P1,P2);
		int ans=0;
		for (int i=1;i<=tot;i++) 
			if (check(P,i,st[i].p1,st[i].p2,C3)) ans++; 
		printf("%d\n",ans);
		for (int i=1;i<=tot;i++)
			if (check(P,i,st[i].p1,st[i].p2,C3)) {
				printf("%.8lf %.8lf %.8lf\n",C3.o.x,C3.o.y,C3.r);
			}
	}
	return 0;
}