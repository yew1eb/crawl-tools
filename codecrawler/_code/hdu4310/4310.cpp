#include"stdio.h"
#include"string.h"
#include"stdlib.h"
struct A
{
	int t,v;
}E[30];
int cmp(const void *a,const void *b)
{
	A *c,*d;
	c=(A *)a;
	d=(A *)b;
	return (c->t*d->v)-(d->t*c->v);
}

int main()
{
	int n;
	int i,l;
	int base,ans;
	while(scanf("%d",&n)!=-1)
	{
		base=0;
		for(i=0;i<n;i++)	{scanf("%d%d",&E[i].v,&E[i].t);base+=E[i].v;}
		qsort(E,n,sizeof(E[0]),cmp);

		ans=0;
		for(i=0;i<n;i++)
		{
			ans+=base*E[i].t;
			base-=E[i].v;
		}
		printf("%d\n",ans);
	}
	return 0;
}