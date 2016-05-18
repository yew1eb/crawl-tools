#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1001;
long long n,a[maxn],match[maxn];
bool map[maxn][maxn],vis[maxn];
bool find(int u)
{
    for(int i=0;i<n;i++)
    {
	if(!map[u][i]||vis[i])
	    continue;
	vis[i]=1;
	if(match[i]==-1||find(i))
	{
	    match[i]=u;
	    return 1;
	}
    }
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
	memset(map,0,sizeof(map));
	memset(match,-1,sizeof(match));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	    scanf("%I64d",&a[i]);
	    for(int j=0;j<i;j++)
		if(a[i]%a[j]==0||a[j]%a[i]==0)
		    map[j][i]=1;
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
	    memset(vis,0,sizeof(vis));
	    if(find(i))
		ans++;
	}
	printf("%d\n",n-ans);
    }
    return 0;
}