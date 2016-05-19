#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<iostream> 
using namespace std;
int a[505],b[505],c[505];
int sum[505*505];
int l,n,m,k;
int flag;
void binary(int x)
{
	int left,right,mid;
	left=0,right=k-1;
	while(left<=right)
	{
		mid=(left+right)>>1;
		if(sum[mid]>x)
			right=mid-1;
		else if(sum[mid]<x)
			left=mid+1;
		else
			{flag=1;return ;}
	}
	return ;
}

int main()
{
	int i,j,q,x,cnt=1;
	while(cin>>l>>n>>m)
	{
		for(i=0;i<l;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			scanf("%d",&b[i]);
		for(i=0;i<m;i++)
			scanf("%d",&c[i]);
		k=0;
		for(i=0;i<l;i++)
			for(j=0;j<n;j++)
			{
				sum[k++]=a[i]+b[j];
			}
		sort(sum,sum+k);
		scanf("%d",&q);
		printf("Case %d:\n",cnt++);
		while(q--)
		{
			scanf("%d",&x);
		    flag=0;
			for(i=0;i<m;i++)
			{
				binary(x-c[i]);
				if(flag){
					printf("YES\n");
					break;
				}		
			}
			if(!flag)
				printf("NO\n");
		}
	}
	return 0;
}