#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<math.h>
#include<set>
#include<vector>
#define MAXN 15
#define INF 1000
using namespace std;
int no[2000000],maxok[2000000];//no储存的是lose的数。  maxok【i】存的是在i之前能组成的最大的数； 
int main()
{
	int i,j,n,m,k,t,c,ca=0;
	for(scanf("%d",&t);t--;)
	{
		ca++;
		scanf("%d%d",&n,&k);
		if(n<=k+1)//n<=k+1时一定是输； 
		{
			printf("Case %d: lose\n",ca);
			continue;
		}
		int x=0,y=0;
		no[0]=maxok[0]=1;
		while(no[x]<n)
		{
			x++;
			no[x]=maxok[x-1]+1;//在x之前，最大的能符合的数是maxok【x-1】、加1后就不符合。 
			while(no[y+1]*k<no[x])//找小于no[x]的最大数:例子k=3时有15得到4 
				y++;
			if(no[y]*k<no[x])//前面得到的数可能不符合条件 
				maxok[x]=no[x]+maxok[y];//如果符合直接得no[x]+maxok[y]；例子中推得15+maxok[3] 
			else
				maxok[x]=no[x];//否则能组成最大的数为本身。 
		}
		if(no[x]==n)//刚好组成n  说明这个数属于no数组。即不能由符合条件的数组成，lose！ 
		{
			printf("Case %d: lose\n",ca);
			continue;
		}
		int ans;
		while(n)
		{
			if(n>=no[x])//不断的减去最大的数，剩下的最小的数就是了。 
			{
				ans=no[x];
				n-=no[x];
			}
			x--;
		}
		printf("Case %d: %d\n",ca,ans);
	} 
	return 0;
}
/*
k=3时：
  no={1,2,3,4,6,8,11,15,21,29
maxok=1,2,3,5,7,10,14,20
*/