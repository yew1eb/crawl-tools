#include"stdio.h"
#include"string.h"
#include"stdlib.h"
struct seg
{
	__int64 l,r,mid;
	__int64 sum;
}T[30333];
__int64 set[10011];

void build(__int64 l,__int64 r,__int64 k)
{
	T[k].l=l;
	T[k].r=r;
	T[k].mid=(l+r)>>1;


	if(l==r)	{T[k].sum=set[l];return ;}


	build(l,T[k].mid,2*k);
	build(T[k].mid+1,r,2*k+1);
	T[k].sum=T[2*k].sum+T[2*k+1].sum;
}

__int64 find(__int64 l,__int64 r,__int64 k)
{
	__int64 ans_t=0;

	if(T[k].l==l && T[k].r==r)	return T[k].sum;
	
	if(r<=T[k].mid)		ans_t+=find(l,r,2*k);
	else if(l>T[k].mid)	ans_t+=find(l,r,2*k+1);
	else
	{
		ans_t+=find(l,T[k].mid,2*k);
		ans_t+=find(T[k].mid+1,r,2*k+1);
	}
	return ans_t;
}

__int64 main()
{
	__int64 T,Case;
	__int64 n;
	__int64 i;
	__int64 left,up,mid,low;
	__int64 count;
	__int64 sum,base;
	__int64 ans,ans_t;
	scanf("%I64d",&T);
	for(Case=1;Case<=T;Case++)
	{
		scanf("%I64d%I64d",&n,&n);
		sum=0;
		for(i=1;i<=n;i++)	{scanf("%I64d",&set[i]);sum+=set[i];}
		build(1,n,1);

		ans=0;
		for(i=sum;i>1;i--)
		{
			if(ans)	break;
			if(sum%i==0)
			{
				base=sum/i;
				count=0;
				left=1;
				while(count<i)
				{
					up=left;
					low=n;
					mid=(up+low)>>1;
					while(up<=low)
					{
						ans_t=find(left,mid,1);
						if(ans_t==base)	break;
						if(ans_t>base)	low=mid-1;
						else			up=mid+1;
						mid=(low+up)>>1;
					}
					if(ans_t==base)
					{
						count++;
						left=mid+1;
					}
					else	break;
				}
				if(count==i)	ans=base;
			}
		}
		if(ans==0)	ans=sum;

		printf("%I64d %I64d\n",Case,ans);
	}
	return 0;
}