#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;
vector <int> vec[20];
void _addedge(int i, int j) { vec[i].push_back(j); }
int num[20][5]={{}, { 4, 1,17,19,23}, { 4, 2, 4, 8,16}, { 3, 3, 9,27}, { 2, 5,25}, { 4, 6,12,18,24}, { 1, 7}, { 2,10,20}, { 1,11}, { 1,13}, { 2,14,28}, { 1,15}, { 1,21}, { 1,22}, { 1,26}};
int sta[20], cnt[20], n, mod, ST;
int F[15][1800005];
int GCD(int a, int b) { for (int t; a%b; t=a%b, a=b, b=t) ; return b ; }
int dfs(int m, int st)
{
	if (F[m][st]!=-1) return F[m][st];
	if (st==ST) return F[m][st]=1, 1;
	int i, j, res=0, siz=vec[m].size();
	cnt[m]--;
	for (i=0; i<siz; i++)
		if (j=vec[m][i], cnt[j])
			res=(res+dfs(j, st+sta[j]))%mod;
	cnt[m]++;
	return F[m][st]=res, F[m][st];
}
int main()
{
	//freopen("1.txt", "r", stdin);
	int cas, T, i, j;
	int A[5]={1,1,2,6,24};
	
	for (i=1; i<=14; i++)
		for (j=1; j<=14; j++)
			if (i==1 || GCD(num[i][1], num[j][1])==1) _addedge(i, j);
	for (i=sta[1]=1; i<=14; i++) _addedge(0, i), sta[i+1]=sta[i]*(num[i][0]+1);
	
	for (cas=scanf("%d", &T); cas<=T; cas++)
	{
		scanf("%d %d", &n, &mod);
		memset(cnt, 0, sizeof(cnt));
		memset(F, 0xff, sizeof(F));
		for (i=1; i<=14; i++)
			for (j=1; j<=num[i][0] && num[i][j]<=n; j++)
				cnt[i]++;
				
		for (ST=0, i=1; i<=14; i++) ST+=sta[i]*cnt[i];
			 
		int ans=dfs(0, 0);
		for (i=1; i<=14; i++)
			ans=(ans*A[cnt[i]])%mod;
		printf("%d\n", ans);
	}
	
	return 0;
}