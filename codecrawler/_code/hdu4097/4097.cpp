#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
int dcmp(double x) {
	if(fabs(x) < eps)
		return 0;
	return x > eps ? 1 : -1;
}
struct point {
	double x, y;
	point(double x = 0, double y = 0) :
			x(x), y(y) {
	}
	point operator-(const point &t) const {
		return point(x - t.x, y - t.y);
	}
	point operator*(const double &t) const {
		return point(x * t, y * t);
	}
	void in() {
		scanf("%lf%lf", &x, &y);
	}
} p[4];
double dis(point a, point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double angle(double a, double b, double c) {
	return acos((b * b + c * c - a * a) / (2 * b * c));
}
struct tri {
	point p[3];
	double d[3], jiao[3];   //边，边所对的角
	//边从小到大排序
	void in() {
		int i;
		for(i = 0; i < 3; i++)
			p[i].in();
		for(i = 0; i < 3; i++)
			d[i] = dis(p[i], p[(i + 1) % 3]);
		sort(d, d + 3);
		for(i = 0; i < 3; i++)
			jiao[i] = angle(d[i], d[(i + 1) % 3], d[(i + 2) % 3]);
	}
} t1, t2;

double 