#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,m,ansa[11],ansb[11];
void GetNum(int num,int *ans)
{
    for(int i=1;i<=9;i++)
    {
	int x=num,index=10,now=10;
	int sum=x/10;
	if(i<=x%10)
	    sum++;
	while(x)
	{
	    if(index*10>x)
	    {
		if(i==x/index%10)
		    sum+=x%index+1;
		else if(i<x/index%10)
		    sum+=now;
		break;
	    }
	    if(i<x/index%10)
		sum+=(x/index/10+1)*now;
	    else
		sum+=(x/index/10)*now;
	    if(i==x/index%10)
		sum+=x%index+1;
	    now*=10;
	    index*=10;
	}	
	ans[i]=sum;
    }
    int i=1,k=0,r;
    int x=num;
    while(x>=10)
    {
	r=x%10;
	x/=10;
	if(r)
	    ans[0]+=i*x;
	else
	    ans[0]+=(x-1)*i+k+1;
	k+=r*i;
	i*=10;
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)&&(n+m))
    {
	memset(ansa,0,sizeof(ansa));
	memset(ansb,0,sizeof(ansb));
	if(n>m)
	    swap(n,m);
	n--;
	GetNum(m,ansb);
	GetNum(n,ansa);
	printf("%d",ansb[0]-ansa[0]);
	for(int i=1;i<10;i++)
	    printf(" %d",ansb[i]-ansa[i]);
	printf("\n");
    }
    return 0;
}