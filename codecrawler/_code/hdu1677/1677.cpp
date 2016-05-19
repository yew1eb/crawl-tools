#include<stdio.h>
#include<string.h>
#include<algorithm>
#include <iostream>
using namespace std;
const int N=20000+5;
struct doll
{
	int w;
	int h;
}d[N];
int dp[N];//储存排序结果
bool cmp(doll d1,doll d2)
{
	return d1.w>d2.w||(d1.w==d2.w&&d1.h<d2.h);//注意这里排序是避免相同的宽度被包含
}
int main()
{
	int T,i,mxlen,j,n,r,l,mid;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d%d",&d[i].w,&d[i].h);
		sort(d,d+n,cmp);
		memset(dp,0,sizeof(dp));
		mxlen=0;
		for(i=0;i<n;i++)
	     {   l=0;
	     	r=mxlen;
	     	while(l<r)//利用二分法进行排序找到适合d[i].h的插入的位置
	     	{
	     		mid=(l+r)/2;
	     		if(dp[mid]<=d[i].h)
	     		 l=mid+1;
	     		 else
	     		 r=mid;
	     	}
	     	dp[l]=d[i].h;//在l位置上插入d[i].h
	     	if(l==mxlen)//如果找到的位置刚好在当前序列的尾端则插入
	     	mxlen++;
	     }
		printf("%d\n",mxlen);
   }
	return 0;
}