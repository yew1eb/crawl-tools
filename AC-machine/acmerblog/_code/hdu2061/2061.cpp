#include<iostream>
using namespace std;
char ch[35];

int main()
{
	int n, m, k = 0;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &m);
		int i;
		double s = 0, count = 0;
		bool p = true;
		for(i = 0; i < m; i++)
		{
			double a, b;
			scanf("%s%lf%lf", ch, &a, &b);
			if(b < 60)
				p = false;
			s += a*b;
			count += a;
		}
		if(k)
			printf("\n");
		k = 1;
		if(p == false)
			printf("Sorry!\n");
		else
			printf("%.2lf\n", s / count);
	}
	return 0;
}