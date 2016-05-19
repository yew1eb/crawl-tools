#include <cstdlib> 
#include <cctype> 
#include <cstring> 
#include <cstdio> 
#include <cmath> 
#include <algorithm> 
#include <vector> 
#include <string> 
#include <iostream> 
#include <sstream> 
#include <map> 
#include <set> 
#include <queue> 
#include <stack> 
#include <fstream> 
#include <numeric> 
#include <iomanip> 
#include <bitset> 
#include <list> 
#include <stdexcept> 
#include <functional> 
#include <utility> 
#include <ctime>
using namespace std;
ifstream fin("aa.txt");
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
#define BLANK(a) for(int i = 0; i < (a); i ++) printf(" ")
const int N = 1001;
int a[N];
int sg[N];
int tmp[N];
int n,m,k;
int mex(int x)
{
	if(sg[x] >= 0) return sg[x];
	
	MEM(tmp,0);
	for(int i = 0; i < n; i++)
	{
		for(int j = x-a[i]; j >= 0; j--)
		{
			tmp[mex(j)^mex(x-a[i]-j)] = 1;
		}
	}
	for(int i = 0; ; i ++)
	{
		if(!tmp[i])
		{
			return sg[x] = i;
		}
	}
}
int main()
{
	
	while(scanf("%d",&n) !=EOF)
	{
		for(int i = 0; i < n; i++)
			scanf("%d",&a[i]);
		int cnt = 1;
		sort(a,a+n);
		for(int i = 1; i < n; i++)
		{
			if(a[i] != a[i-1])
			{
				a[cnt++] = a[i];
			}
		}
		n = cnt;
		MEM(sg,-1);
		sg[0] = 0;
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d",&k);
			if(mex(k))
				puts("1");
			else
				puts("2");
		}
	}
	return 0;
}