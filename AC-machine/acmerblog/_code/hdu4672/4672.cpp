#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#define INF 10005
#define inf 0x0f0f0f0f

using namespace std;
int F[INF], N[INF*10], M[105];
int Pre_dp(int m)
{
	memset(F, 0xef, sizeof(F));
	sort(M+1, M+m+1);
	F[0]=0;
	for (int i=1; i<=m; i++)
		for (int j=M[i]; j<INF; j++)
				F[j]=max(F[j], F[j-M[i]]+1);
	return M[1];
}
int SG(int n, int m)
{
	if (F[n]<-inf) return -1;
	return F[n]+m;
}
int _SG(int n, int mi)
{
	if (n<INF) return SG(n, 0);
	int m=(n-INF)/mi;
	if (n-=m*mi, n>=INF) n-=mi, m++;
	return SG(n, m);
}
char str[2][50];
int main()
{
	//freopen("1.txt", "r", stdin);
	int n, m;

	while (~scanf ("%d %d", &n, &m))
	{
		scanf("%s %s" , str[0], str[1]);
		for (int i=1; i<=n; i++) scanf("%d", &N[i]);
		for (int i=1; i<=m; i++) scanf("%d", &M[i]);
		int sg=0, mi=Pre_dp(m), now, flag=0;
		for (int i=1; i<=n; i++)
			if (now=_SG(N[i], mi), now==-1) flag=1;
			else sg^=now;
		if (flag) puts(str[1]);
		else printf("%s\n", sg?str[0]:str[1]);
	}
}