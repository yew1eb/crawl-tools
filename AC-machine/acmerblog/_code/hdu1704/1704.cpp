#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct team
{
	int no,time,sol,cuo[25];
}t[1010];
struct ti
{
	int ttno,tpno,tti,tju;
}jiao[1010];
int cmp(const void *a,const void *b)
{
	struct team *c=(struct team *)a,*d=(struct team *)b;
	if(c->sol!=d->sol)
		return d->sol-c->sol;
	else if(c->time!=d->time)
		return c->time-d->time;
	else return c->no-d->no;
}
int cmpp(const void *a,const void *b)
{
	struct ti *c=(struct ti *)a,*d=(struct ti *)b;
	return c->tti-d->tti;
}
int main()
{
	int c,n,i,tno,pno,ti,ju;
	while(scanf("%d%d",&c,&n)!=EOF)
	{	
		memset(t,0,sizeof(t));
		for(i=0;i<c;i++)
			t[i].no=i;
		for(i=0;i<n;i++)
			scanf("%d%d%d%d",&jiao[i].ttno,&jiao[i].tpno,&jiao[i].tti,&jiao[i].tju);
		qsort(jiao,n,sizeof(jiao[0]),cmpp);
		for(i=0;i<n;i++)
		{
			tno=jiao[i].ttno;
			pno=jiao[i].tpno;
			ti=jiao[i].tti;
			ju=jiao[i].tju;
			if(ju)
			{
				if(t[tno-1].cuo[pno]>=0)
				{
					t[tno-1].sol++;
					t[tno-1].time+=ti+t[tno-1].cuo[pno]*20*60;
					t[tno-1].cuo[pno]=-1;
				}
	
			}
			else
			{
				t[tno-1].cuo[pno]++;
			}
		}
		qsort(t,c,sizeof(t[0]),cmp);
		printf("%d",t[0].no+1);
		for(i=1;i<c;i++)
				printf(" %d",t[i].no+1);
		printf("\n");
	}
	return 0;
}