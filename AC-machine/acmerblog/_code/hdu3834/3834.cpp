#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define eps 1e-8
struct point
{
 point(){}
 point(double x, double y) : x(x), y(y){}
 double x,y;
}A, B;
double xmult(point p1,point p2,point p0){
return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
double dist(point p1,point p2){
return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
double dist2(point p1,point p2){
return ((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
point intersection(point u1,point u2,point v1,point v2){
point ret=u1;
double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))
/((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
ret.x+=(u2.x-u1.x)*t;
ret.y+=(u2.y-u1.y)*t;
return ret;
}
//����ֱ����Բ�Ľ���,��ֱ֤����Բ�н���
//�����߶���Բ�Ľ����������������е��Ƿ����߶���
void intersection_line_circle(point c,double r,point l1,point l2,point& p1,point& p2){
point p=c;
double t;
p.x+=l1.y-l2.y;
p.y+=l2.x-l1.x;
p=intersection(p,c,l1,l2);
t=sqrt(r*r- dist (p,c)* dist (p,c))/ dist (l1,l2);
p1.x=p.x+(l2.x-l1.x)*t;
p1.y=p.y+(l2.y-l1.y)*t;
p2.x=p.x-(l2.x-l1.x)*t;
p2.y=p.y-(l2.y-l1.y)*t;
}
int t;
double r1, r2, T, pos[2];
point rotate(point v,point p,double angle,double scale){
point ret=p;
v.x-=p.x,v.y-=p.y;
p.x=scale*cos(angle);
p.y=scale*sin(angle);
ret.x+=v.x*p.x-v.y*p.y;
ret.y+=v.x*p.y+v.y*p.x;
return ret;
}
point GetTarget(double TT)
{
 point a, b, ans;
 intersection_line_circle(A, r1 - r2, B, point(B.x + pos[0], B.y + pos[1]), a, b);
 if ((a.x - B.x) * pos[0] >= 0 && (a.y - B.y) * pos[1] >= 0)
 ans = a;
 else ans = b;
 //cout<<ans.x<<' '<<ans.y<<endl;
 double dis = dist(ans, B);
 //cout<<dis<<endl;
 if (dis - TT >= -eps)
 return point(B.x + TT * (ans.x - b.x) / dis, B.y + TT * (ans.y - b.y) / dis);
 TT -= dis;//ʣ���·��
 double cosx = (dist2(A, ans) + dist2(B, ans) - dist2(A, B)) * 0.5 / (dist(A, ans) * dist(B, ans));


 double len = cosx * (r1 - r2) * 2;
 cosx = acos(cosx);
 cosx = acos(-1.0) - cosx * 2;

 double tmp = xmult(B, A, ans);
 //cout<<"TMP:"<<tmp<<endl;
 if (tmp > 0) cosx = -cosx;
 long long num = (long long)(TT / len);
 TT -= num * len;
 //cout<<cosx<<endl;
 point ans1 = rotate(ans, A, cosx * num, 1.0);
 //cout<<ans.x<<' '<<ans.y<<endl<<ans1.x<<' '<<ans1.y<<endl;
 point ans2 = rotate(ans, A, cosx * (num + 1), 1.0);
 return point(ans1.x + TT * (ans2.x - ans1.x) / len, ans1.y + TT * (ans2.y - ans1.y) / len);
}
int main()
{
 scanf("%d", &t);
 while(t--)
 {
 scanf("%lf%lf%lf", &A.x, &A.y, &r1);
 scanf("%lf%lf%lf", &B.x, &B.y, &r2);
 scanf("%lf%lf%lf", &pos[0], &pos[1], &T);
 T = T * sqrt(pos[0] * pos[0] + pos[1] * pos[1]);
 point ans = GetTarget(T);
 printf("%.1f %.1f\n", ans.x, ans.y);
 }
 return 0;
}