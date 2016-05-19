#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#define N 10011
#define M 111

int n,len;
struct A{
	char str[M];
}E[N];

void get_min()
{
	int i,l;
	int p1,p2;
	int k,len;
	int flag;
	char temp[2*M];
	len=strlen(E[0].str);
	for(i=0;i<n;i++)
	{
		strcpy(temp,E[i].str);
		strcat(temp,E[i].str);
		flag=-1;
		p1=p2=0;
		while(1)
		{
			//
			if(p1==p2)
			{
				p1++;
				if(p1>=len)	break;
				continue;
			}
			//
			k=0;
			while(temp[p1+k]==temp[p2+k])
			{
				k++;
				if(k>=len)	flag=p1;
			}
			if(flag!=-1)	break;
			//
			if(temp[p1+k]>temp[p2+k])	p1+=k+1;
			else						p2+=k+1;
			if(p1>=len || p2>=len)	break;
		}
		if(p1>=len)		flag=p2;
		else if(p2>=len)flag=p1;
		for(l=0;E[i].str[l];l++)	E[i].str[l]=temp[l+flag];
	}
}
int cmp(const void *a,const void *b)
{
	A *c,*d;
	c=(A *)a;
	d=(A *)b;
	return strcmp(c->str,d->str);
}
int main()
{
	int i;
	int ans;
	while(scanf("%d",&n)!=-1)
	{
		for(i=0;i<n;i++)	scanf("%s",E[i].str);
		get_min();
		qsort(E,n,sizeof(E[0]),cmp);
		ans=1;
		for(i=1;i<n;i++)	if(strcmp(E[i].str,E[i-1].str))	ans++;
		printf("%d\n",ans);
	}
	return 0;
}