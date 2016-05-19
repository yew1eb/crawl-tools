/*
hdu 4509
一天工24*60分钟
接下来有一些时间段，你要去做些事
问你有多少空余时间。

线段树题目
*/
#include<stdio.h>
#include<string.h>
struct node
{
	int l,r,mid,k;
}yong[1000000];
int n;
void build(int l,int r,int i)
{
	yong[i].l=l;
	yong[i].r=r;
	yong[i].k=r-l+1;
	yong[i].mid=(l+r)/2;
	if(l==r)
	{
		return;
	}
	
	build(l,yong[i].mid,i*2);
	build(yong[i].mid+1,r,i*2+1);
}
int insert(int z,int y,int wei)
{
	int zuof=0,youf=0;
	if(yong[wei].k==0)//之前少了这两个if  老是超时
		return 0;
	if(z<=yong[wei].l&&y>=yong[wei].r)
	{
		int temp=yong[wei].k;
		yong[wei].k=0;
		return temp;
	}
	if(yong[wei].l==yong[wei].r)
	{
		if(yong[wei].k==1)
		{
			yong[wei].k=0;
			return 1;
		}else return 0;
	}
	if(z<=yong[wei].mid)
	{
		zuof=insert(z,y,wei*2);
	}
	if(y>yong[wei].mid)
	{
		youf=insert(z,y,wei*2+1);
	}
	yong[wei].k=yong[wei].k-zuof-youf;
	return zuof+youf;
}
int main()
{
	int i,a,b,c,d,e,f;
	while(scanf("%d",&n)!=EOF)
	{
		build(0,24*60-1,1);
		for(i=1;i<=n;i++)
		{
			scanf("%d:%d %d:%d",&a,&b,&c,&d);
			e=a*60+b;
			f=c*60+d;
			if(f<=e)
				continue;
			insert(e,f-1,1);
		}
		printf("%d\n",yong[1].k);
	}
	return 0;
}