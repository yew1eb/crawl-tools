#include <iostream>
#include <algorithm>
using namespace std;
const int N =500010;
#define  min(a,b) a<b?a:b
struct node
{
	__int64 c,l,u,no;
	bool operator<(const node t)const
	{
		if(u==t.u)
			return t.c<c;
		return u<t.u;
	}
}num[500010];

int cmp(const void *p,const void *q)			//按
{
	return (*(node*)p).no-(*(node*)q).no;
}
__int64 ans[N];
int main()
{
	int t,n,m,q,i,k,cnt=1;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%d",&n,&m,&q);
		for(i=0;i<m;i++)
			scanf("%d%d%d",&num[i].u,&num[i].c,&num[i].l);
		sort(num,num+m);
		
// 		printf("\nafter once sort:\n");
// 		for(i=0;i<m;i++)
// 			printf("%I64d %I64d %I64d\n",num[i].u,num[i].c,num[i].l);

		num[0].no=0;
		int Maxlen=-1;
		for(i=1;i<m;i++)
		{
			if(num[i].u == num[i-1].u)
				num[i].no=num[i-1].no+1;
			else
				num[i].no=0;
			if(Maxlen<num[i].no)
				Maxlen=num[i].no;
		}
		qsort(num,m,sizeof(num[0]),cmp);

// 		printf("\nafter twice sort:\n");
// 		for(i=0;i<m;i++)
// 			printf("%I64d %I64d %I64d\n",num[i].u,num[i].c,num[i].l);

		//计算出结果
		int hh=1;
		ans[1]=num[0].l;
		for(i=1;i<m;i++)
		{
			if(num[i].no!=num[i-1].no)
			{
				ans[hh]+=ans[hh-1];
				hh++;
				ans[hh]=num[i].l;
			}
			else
				ans[hh]+=num[i].l;
		}
		ans[hh]+=ans[hh-1];
		printf("Case #%d:\n",cnt++);
		while (q--)
		{
			scanf("%d",&k);
			k=min(hh,k);
			printf("%I64d\n",ans[k]);
		}
	}
	return 0;
}