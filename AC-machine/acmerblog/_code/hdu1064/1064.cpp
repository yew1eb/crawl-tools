#include<iostream>
using namespace std;
int main()
{
	double sum=0,m,i;
	for(i=0;i<12;i++)
	{
		scanf("%lf",&m);
		sum+=m;
	}
	printf("$%.2lf\n",sum/12);
	return 0;
}