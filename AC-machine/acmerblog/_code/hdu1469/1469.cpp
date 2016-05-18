#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

const int N = 101;
const double eps = 1e-8;
const double pi = acos(-1.0);

struct cpoint {//C++构造函数,默认缺省值为(0,0)
    double x, y;
    cpoint(double xx = 0, double yy = 0): x(xx), y(yy) {};
};

int dcmp(double x) {//判断参数的符号,负数返回-1,0返回0,正数返回1
    if (x < -eps) return -1; 
	else return x > eps;
}

double xmult(cpoint p0, cpoint p1, cpoint p2) { // p0p1 与 p0p2 叉积
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

bool EqualPoint(cpoint a, cpoint b) {//两点相等
    return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}

struct cvector {//向量
    cpoint s, e;
    double ang, d;
};

//atan (double x)弧度表示的反正切
//atan2(double x,double y)弧度表示的反正切,相当于atan(x/y)

void setline(double x1, double y1, double x2, double y2, cvector &v) {
    v.s.x = x1; v.s.y = y1;
    v.e.x = x2; v.e.y = y2;
    v.ang = atan2(y2 - y1, x2 - x1);
	//这里的 d 代表向量(直线)和坐标轴的截距,正数表示 原点 在该向量的左边
	//(这道题要求左半平面交),负号则表示 原点 在右边
    if (dcmp(x1 - x2))          // x1 > x2
		v.d = (x1 * y2 - x2 * y1) / fabs(x1 - x2);
    else v.d = (x1 * y2 - x2 * y1) / fabs(y1 - y2);
}

//判向量平行
bool parallel(const cvector &a, const cvector &b) {
    double u = (a.e.x - a.s.x) * (b.e.y - b.s.y) - (a.e.y - a.s.y) * (b.e.x - b.s.x);
    return dcmp(u) == 0;
}

//求两向量(直线)交点 (两向量不能平行或重合)
cpoint CrossPoint(const cvector &a, const cvector &b) {
    cpoint res;
    double u = xmult(a.s, a.e, b.s), v = xmult(a.e, a.s, b.e);
    res.x = (b.s.x * v + b.e.x * u) / (u + v);
    res.y = (b.s.y * v + b.e.y * u) / (u + v);
    return res;
}

//半平面交排序函数[优先顺序: 1.极角 2.前面的直线在后面的左边]
static bool VecCmp(const cvector &l, const cvector &r) {
    if (dcmp(l.ang - r.ang)) return l.ang < r.ang;
    return l.d < r.d;
}

cvector deq[N]; //用于计算的双端队列

void HalfPanelCross(cvector vec[],int n,cpoint cp[],int &m)
{
	int i,tn;
	sort(vec,vec+n,VecCmp);
	for(tn=i=1;i<n;i++)
	{
		if(dcmp(vec[i].ang-vec[i-1].ang) != 0)
			vec[tn++]=vec[i];
	}n=tn;
	int bot=0, top=1;
	deq[0]=vec[0], deq[1]=vec[1];
	for(i=2;i<tn;i++)
	{
		if(parallel(deq[top],deq[top-1]) || parallel(deq[bot],deq[bot+1]))return ;
		while(bot<top && dcmp(xmult(vec[i].s,vec[i].e,CrossPoint(deq[top],deq[top-1])))<0)
			top--;
		while(bot<top && dcmp(xmult(vec[i].s,vec[i].e,CrossPoint(deq[bot],deq[bot+1])))<0)
			bot++;
		deq[++top]=vec[i];
	}
	while(bot<top && dcmp(xmult(deq[bot].s,deq[bot].e,CrossPoint(deq[top],deq[top-1])))<0)
		top--;
	while(bot<top && dcmp(xmult(deq[top].s,deq[top].e,CrossPoint(deq[bot],deq[bot+1])))<0)
		bot++;

	if(top <= bot+1)return ;

	m=0;
	for(i=bot;i<top;i++)
		cp[m++]=CrossPoint(deq[i],deq[i+1]);
	if(bot<top+1)
		cp[m++]=CrossPoint(deq[bot],deq[top]);
	m=unique(cp,cp+m,EqualPoint)-cp;
}

double PolygonArea(cpoint p[], int n) {
    if (n < 3) return 0;
    double s = p[0].y * (p[n - 1].x - p[1].x);
    for (int i = 1; i < n; ++i)
        s += p[i].y * (p[i - 1].x - p[(i + 1) % n].x);
    return fabs(s / 2); // 顺时针方向s为负
}

int n,m;
cvector v[N];
cpoint cp[N];

int main()
{
	int i,j,time=1;
	cpoint p[N];
	while(scanf("%d",&n),n)
	{
		memset(cp,0,sizeof(cp));
		memset(v,0,sizeof(v));

		m=0;     //m是全局变量,注意,单纯在外部函数中初始化,有时候不靠谱

		for(i=0;i<n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		p[n]=p[0];

		for(j=0,i=n;i>0;i--)
			setline(p[i].x,p[i].y,p[i-1].x,p[i-1].y,v[j++]);
		n=j;

		HalfPanelCross(v,n,cp,m);//向量(直线)集合,长度;点集,长度

		printf("Floor #%d\n",time++);

		if(!m)printf("Surveillance is impossible.\n");
		else printf("Surveillance is possible.\n");
		puts("");
	}
	return 0;
}