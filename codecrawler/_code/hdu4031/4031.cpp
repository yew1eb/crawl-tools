#include"stdio.h"
#include"string.h"
#include"stdlib.h"
int n,q,t;
struct SegTree
{
	int l,r,mid;
	int ts;
}T[80011];
int attack_l[20011],attack_r[20011],tot;
int next[20011],pro[20011];
void build(int l,int r,int k)
{
	T[k].l=l;
	T[k].r=r;
	T[k].mid=(l+r)>>1;
	T[k].ts=0;
	if(l==r)	return ;
	build(l,T[k].mid,2*k);
	build(T[k].mid+1,r,2*k+1);
}
void update(int l,int r,int k)
{
	if(T[k].l==l && T[k].r==r)	{T[k].ts++;return ;}
	if(r<=T[k].mid)		update(l,r,2*k);
	else if(l>T[k].mid)	update(l,r,2*k+1);
	else
	{
		update(l,T[k].mid,2*k);
		update(T[k].mid+1,r,2*k+1);
	}
}
int find(int d,int k)
{
	int sum=0;
	if(T[k].l==T[k].r && T[k].l==d)	return T[k].ts;
	if(T[k].l<=d && d<=T[k].r)
	{
		sum+=T[k].ts;
		if(d<=T[k].mid)	sum+=find(d,2*k);
		else			sum+=find(d,2*k+1);
		return sum;
	}
	else return 0;
}
int main()
{
	int T,Case;
	int j;
	char str[11];
	int a,b;
	int temp;
	scanf("%d",&T);
	for(Case=1;Case<=T;Case++)
	{
		scanf("%d%d%d",&n,&q,&t);
		build(1,n,1);
		printf("Case %d:\n",Case);
		memset(pro,0,sizeof(pro));
		memset(next,0,sizeof(next));
		tot=0;
		while(q--)
		{
			scanf("%s",str);
			if(str[0]=='A')
			{
				scanf("%d%d",&a,&b);
				update(a,b,1);
				attack_l[tot]=a;
				attack_r[tot++]=b;
			}
			else
			{
				scanf("%d",&a);
				j=next[a];
				while(j<tot)
				{
					if(attack_l[j]<=a && a<=attack_r[j])
					{
						pro[a]++;
						j+=t;
					}
					else j++;
				}
				next[a]=j;
				temp=find(a,1);
				printf("%d\n",temp-pro[a]);
			}
		}
	}
	return 0;
}