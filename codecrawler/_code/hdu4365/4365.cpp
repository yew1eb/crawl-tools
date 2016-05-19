#include<stdio.h>
#include<string.h>
#define ll __int64
#define f(x) (x*(x+1))/2
#define MOD 100000007
ll quickpow(ll m,ll n)
{
	ll b = 1;
	while (n)
	{
		if (n&(ll)1)
			b = (b*m)%MOD;
		n >>=(ll)1;
		m = (m*m)%MOD;
	}
	return b;
} 
ll k;
int n,m;
bool map[5050][5050];

void PUT(int x){
	for(int i=1;i<=x;i++){

		for(int j=1;j<=x;j++)
			printf("%d ",map[i][j]);
		printf("\n");
	}
	printf("\n");
}

int Is(int x,int y){
	int mid;
	if(n&1)
	{
		mid=(1+n)>>1;
		if(x>mid)x-=2*(mid-x);
		if(y>mid)y-=2*(mid-y);
	}
	else 
	{
		mid=n>>1;
		if(x>mid)x=2*mid+1-x;
		if(y>mid)y=2*mid+1-y;
	}
	if(map[x][y])return 0;
	return map[x][y]=map[y][x]=1;
}
int main(){
	int u,v;
	while(~scanf("%d %d %I64d",&n,&m,&k)){
		int num=0,z=n>>1;
		for(int i=1;i<=z;i++)
			for(int j=1;j<=z;j++)
				map[i][j]=0;
		while(m--)
		{
			scanf("%d%d",&u,&v);
			num+=Is(1+u,1+v);
		}

		//		PUT(n);
		n=(n+1)/2;
		n=f(n)-num;
		ll ans=quickpow(k,n);
		printf("%I64d\n",ans);
	}
	return 0;
}
/*
3 0 2
4 2 3
1 1
3 1

5 3 999
0 0
0 1
0 2

*/