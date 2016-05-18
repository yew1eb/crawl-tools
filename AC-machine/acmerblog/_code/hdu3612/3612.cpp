#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 10011
#define MAXM 111
int pn,n;
int p[MAXN];
int two[MAXM];
int add[MAXM];

void solve()
{
	int flag;
	
	memset(add,0,sizeof(add));
	n++;
	for(int i=1;i<=pn;i++)
	{
		int t=p[i];
		int j=0;
		while(t>0)
		{
			add[j]+=t%2;
			if(add[j]>=n) add[j]-=n;
			t/=2;
			j++;
		}
	}
	
	flag=0;
	for(int i=0;i<MAXM;i++)
		if(add[i]>0) {flag=1;break;}
	
	//printf("flag=%d\n",flag);
	if(flag) printf("Fernandes wins\n");
	else printf("Li wins\n");
}

int main()
{
	int casen;
	scanf("%d",&casen);
	while(casen--)
	{
		scanf("%d %d",&pn,&n);
		for(int i=1;i<=pn;i++)
			scanf("%d",&p[i]);
		solve();
	}

	return 0;
}