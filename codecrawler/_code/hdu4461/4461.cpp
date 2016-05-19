#include <cstdio> 
#include <cstring>
using namespace std;
bool A, B;
int fun(char a)
{
	if(a == 'A')return 16;
	if(a == 'B')return 7;
	if(a == 'C')return 8;
	if(a == 'D')return 1;
	if(a == 'E')return 1;
	if(a == 'F')return 2;
	if(a == 'G')return 3;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		char a[3];
		int n1, n2, sum1=0, sum2=0;
		scanf("%d", &n1);
		A=0; B=0;
		while(n1--)
		{
			scanf("%s", a);
			sum1+=fun(a[0]);
            if(a[0]=='B') A=1;
			if(a[0]=='C') B=1;
		}
		if(A==0||B==0)
		    sum1--;
		if(sum1==0) sum1=1;
		scanf("%d", &n2);
		A=0; B=0;
		while(n2--)
		{
			scanf("%s", a);
			sum2+=fun(a[0]);
			if(a[0]=='B') A=1;
			if(a[0]=='C') B=1;
		}
		if(A==0||B==0)
		    sum2--;
		if(sum2==0) sum2=1;
		if(sum1>sum2) printf("red\n");
		else if(sum1 == sum2) printf("tie\n");
		else if(sum1<sum2) printf("black\n");
	}
	return 0;
}