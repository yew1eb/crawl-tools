#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <cstring>
#include <string>

using namespace std;
#define inf 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define eps 1e-9
#define N 2100

ll dis[N];
struct Node
{
 int l,r,d;
}node[N];

int main()
{
 int t,n,m,a;
 scanf("%d",&t);
 while(t--)
 {
 scanf("%d%d",&n,&m);
	 for(int i=1;i<=n;i++)
		 scanf("%d%d%d",&node[i].l,&node[i].r,&node[i].d);
	 memset(dis,-1,sizeof(dis));
	 
	 dis[1] = node[1].d;
	 for(int i=1;i<=n;i++)
	 {
	 if(dis[i]==-1) continue;
		 for(int j=i+1;j<=n;j++)
			 if(node[j].l<=node[i].r)
				 if(dis[j]==-1||dis[j]>dis[i]+node[j].d)
				 dis[j] = dis[i]+node[j].d;
	 }
	 
	 for(int i=0;i<m;i++)
	 {
		 scanf("%d",&a);
		 printf("%I64d\n",dis[a]);
	 }

 }
}