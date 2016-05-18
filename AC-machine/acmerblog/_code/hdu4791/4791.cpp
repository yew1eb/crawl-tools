#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <cmath>
#include <cstdlib>
#include <set>
#include <algorithm>
#include <string>
#include <iomanip>
#define LL long long
using namespace std;
struct cost
{
	int num;
	long long minn;
}store[100010];
bool cmp(cost a,cost b)
{
	return a.minn<b.minn;
}
LL mini[100010];
int main()
{
	int storep[100010],stores[100010];
	int t,n,m,p,tmp;
	bool flag;
	LL val;
    scanf("%d",&t);
	while(t--)
	{
      scanf("%d%d",&n,&m);
	  for(int i=0;i<n;i++)
	  {
		  scanf("%d%d",&stores[i],&storep[i]);
		  store[i].num=i;
		  store[i].minn=1LL*storep[i]*stores[i];
	  }
	  sort(store,store+n,cmp);
	  for(int i=0;i<n;i++)
	  {
		  mini[i]=store[i].minn;
	  }
	  for(int i=0;i<m;i++)
	  {
		  scanf("%d",&tmp);
		  if(tmp>=stores[n-1])
		  {
			  printf("%lld\n",1LL*tmp*storep[n-1]);
		  }
		  else
		  {
			  flag=false;
			  p=lower_bound(stores,stores+n,tmp)-stores;
			  //cout<<"storep: "<<storep[p]<<endl;
			  val=1LL*storep[p-1]*tmp;
			 // for(int i=0;i<p+1;i++)
				  //cout<<"price: "<<storep[i]<<endl;
			  //cout<<"val: "<<val<<endl;
			  p=upper_bound(mini,mini+n,val)-mini;
			  for(int i=0;i<p;i++)
			  {
				  if(stores[store[i].num]>=tmp)
				  {
					  flag=true;
					  printf("%lld\n",store[i].minn);
					  break;
				  }
			  }
			  if(!flag)
			  {
				  if(stores[store[p].num]>=tmp&&mini[p]<=val)
				  {
					  flag=true;
					  printf("%lld",store[p].minn);
				  }
			  }
			  if(!flag)
			  {
				  printf("%lld\n",val);
			  }
		  }
	  }

	}
	return 0;
}