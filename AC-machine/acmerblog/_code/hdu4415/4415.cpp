#include"iostream"
#include"cstdio"
#include"queue"
#include"cstring"
#include"algorithm"
using namespace std;
const int N=100005;

int n,m,cnt1,cnt2;
int ans1,ans2,ret1,ret2,zz[N];
struct node{
	int cost,val;
}E[N];
int cmp(node n1,node n2){
	return n1.cost<n2.cost;
}

void solve1()
{
	int i;
	ans1=0;
	ret1=m;
	for(i=0;i<n;i++)
	{
		if(E[i].val)	continue;
		if(ret1>=E[i].cost)	{ans1++;ret1-=E[i].cost;}
		else	break;
	}
}
void solve2()
{
	int i;
	ans2=0;
	ret2=m;
	for(i=0;i<n;i++)	if(E[i].val)	break;
	if(i>=n)			return ;
	if(ret2<E[i].cost)	return ;

	int flag=i;
	int sum=0;
	for(i=0;i<n;i++)	sum+=E[i].val;
	if(sum+1>=n)	{ans2=n;ret2=m-E[flag].cost;return ;}

	ans2=sum+1;
	ret2-=E[flag].cost;
	memset(zz,0,sizeof(zz));
	zz[flag]=1;
	i=n-1;
	while(sum>0)
	{
		if(!zz[i])	{zz[i]=1;sum--;}
		i--;
	}
	for(i=0;i<n;i++)
	{
		if(zz[i])	continue;
		if(ret2<E[i].cost)	break;
		ans2++;
		ret2-=E[i].cost;
	}
}
int main()
{
	int T,Case;
	int i;
	cin>>T;
	for(Case=1;Case<=T;Case++)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)	scanf("%d%d",&E[i].cost,&E[i].val);

		sort(E,E+n,cmp);
		solve1();
		solve2();
		if(ans1>ans2 || (ans1==ans2 && ret1>ret2))
			printf("Case %d: %d %d\n",Case,ans1,m-ret1);
		else	printf("Case %d: %d %d\n",Case,ans2,m-ret2);
	}
	return 0;
}