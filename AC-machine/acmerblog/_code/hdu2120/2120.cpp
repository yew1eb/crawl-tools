#include"stdio.h"
int set[1001];
int find(int x)
{
	if(set[x]==x)return x;
	set[x]=find(set[x]);
	return set[x];
}
int main()
{
	int i;
	int ans;
	int a,b;
	int x,y;
	int n,m;
	while(scanf("%d%d",&n,&m)!=-1)
	{
		for(i=0;i<n;i++)
			set[i]=i;
		ans=0;
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&x,&y);
			a=find(x);
			b=find(y);
			if(a==b)
				ans++;
			else set[b]=a;
		}
		printf("%d\n",ans);
	}
	return 0;
}