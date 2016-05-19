#include <stdio.h>
#include <math.h>

const double g = 9.80665;
const double eps = 1e-6;

int main()
{
	int test, t = 1;
	double a, b, h, tmp;
	double d, l, ans, v;
	scanf("%d", &test);
	while(test--)
	{
		scanf("%lf%lf%lf", &a, &b, &h);
		if(fabs(a - b) < eps) 
		{
			printf("Case %d: The iron chain will not reach the floor at all!\n", t++);
			continue;
		}
		if(a > b)
		{
			d = a;
			a = b;
			b = d;
		}
		d = 0.0005;
		ans = 0.0;
		//v = sqrt(2 * g * l * (b - a + l) / (a + b));
		tmp = 2 * g / (a + b);
		double v1 = 0, v2 = 0;
		for(l = d;l <= a;l += d)
		{
			v2 = sqrt(tmp * l * (b - a + l));
			v = (v1 + v2) / 2;
			ans += d / v;	
			v1 = v2;
		}
		//v = sqrt(tmp * a * b);
		double aa = g / 2, bb = v, cc = -(h - b - a);
		ans += (-bb + sqrt(bb * bb - 4 * aa * cc)) / 2 / aa;
		printf("Case %d: The iron chain will reach the floor after %.3lf seconds.\n", t++, ans);		
	}
	return 0;
}