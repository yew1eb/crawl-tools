#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int NM=10005;
const int SEC=3600;
const double D=4.5;
struct Ride{
	int vi,ti;
}r[NM];

bool comp(struct Ride A,struct Ride B)
{
	if(A.ti<B.ti) return 1;
	else
	{
		if(A.ti==B.ti)
		{
			if(A.vi<B.vi) return 0;
			else return 0;
		}
		else return 0;
	}
}

int main()
{
	int n,i,j;
	double time1,time;
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++)
			scanf("%d%d",&r[i].vi,&r[i].ti);
		sort(r,r+n,comp);
		for(j=0;j<n;j++)  //<0 忽略
		{
			if(r[j].ti>=0)
			{
				time=(double)(D*SEC/r[j].vi)+r[j].ti;
				break;
			}
		}
	
		for(i=j+1;i<n;i++)
		{
			time1=(double)(D*SEC/r[i].vi)+r[i].ti;
			if(time1<time)
				time=time1;
		}
		
		printf("%.lf\n",ceil(time));  //返回不小于这个数的最小整数
	}
	return 0;
}