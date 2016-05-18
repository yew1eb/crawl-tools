#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int B,N;
	double temp;
	int a1,a2;
	while(scanf("%d %d",&B,&N) != EOF)
	{
		if(B==0 && N==0) break;
		temp = pow(B+0.0,1.0/N);
		a1 = floor(temp);
		a2 = ceil(temp);
		if((B-pow(a1,N)) > (pow(a2,N) - B))
		{
			printf("%d\n",a2);
		}
		else
		{
			printf("%d\n",a1);
		}
	}
	return 0;
}