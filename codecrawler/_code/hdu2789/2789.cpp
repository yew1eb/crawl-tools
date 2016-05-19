#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int N=250;
const int MOD=1000000007;

struct data
{
	int type;
	int width, length;
} a[N];

int f[3050][250], n, cnt, m;

int main()
{
	memset(f, 0, sizeof(f));
	scanf("%d%d", &n, &m);
	cnt=n;
	for(int i=1, L, W; i<=cnt; i++)
	{
		scanf("%d%d", &L, &W);
		a[i].length=L, a[i].width=W, a[i].type=i;
		f[L][i]=(f[L][i]+1)%MOD;
		if(L!=W)
		{
			n++;
			a[n].length=W, a[n].width=L, a[n].type=i;
			f[W][n]=(f[W][n]+1)%MOD;
		}
	}
	for(int L=0; L<=m; L++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if(a[i].type!=a[j].type && a[j].width==a[i].length && L>=a[i].length)
				{
					f[L][i]=(f[L][i]+f[L-a[i].length][j])%MOD;
				}
	int ans=0;
	for(int i=1; i<=n; i++)
		ans=(ans+f[m][i])%MOD;
	printf("%d\n", ans);
	return 0;
}