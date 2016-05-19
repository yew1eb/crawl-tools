#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	__int64  f[60];
	int a,b,c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d %d",&a,&b);
		f[a]=0;
		f[a+1]=1;
		f[a+2]=2;
		if(b-a==1)
			printf("1\n");
		else
		{
		   for(int i=a+3;i<=b;i++)
			   f[i]=f[i-1]+f[i-2];
		   printf("%I64d\n",f[b]);
		}
	}
	system("pause");
	return 0;
}