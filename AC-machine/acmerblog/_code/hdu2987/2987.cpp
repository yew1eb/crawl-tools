#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1e6+10;
int a[maxn];
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
	a[1]=3;
	a[2]=1;
	for(int i=3;i<=n-2;i+=2)
	    a[i]=i+2;
	if(n&1)
	{
	    a[n]=n-1;
	    for(int i=n-1;i>2;i-=2)
		a[i]=i-2;
	}
	else
	{
	    a[n-1]=n;
	    a[n]=n-2;
	    for(int i=n-2;i>2;i-=2)
		a[i]=i-2;
	}
	printf("%d",a[1]);
	for(int i=2;i<=n;i++)
	    printf(" %d",a[i]);
	printf("\n");
    }
    return 0;
}